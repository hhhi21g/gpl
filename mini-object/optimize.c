#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"
#include "optimize.h"

expMap *exp_list = NULL;
int exp_cnt = 0;

typedef struct ConstEntry
{
    SYM *var;   // 变量 / 临时
    SYM *value; // 对应的常量符号
    int state;  // 0 = 未知, 1 = 确认常量, -1 = 非常量
} ConstEntry;

#define MAX_CONST_ENTRY 2048

// 是否是临时变量或普通变量
int is_var(SYM *s)
{
    if (!s)
        return 0;
    return (s->type == SYM_VAR || s->type == SYM_TMP);
}

// s是否在数组中
int in_list(SYM **list, int cnt, SYM *s)
{
    for (int i = 0; i < cnt; i++)
    {
        if (list[i] == s)
            return 1;
    }
    return 0;
}

void print_def_use()
{
    printf("===== DEF / USE Info =====\n");

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        printf("BB %p\n", bb);

        printf("use: ");
        for (int i = 0; i < bb->use_cnt; i++)
            printf("%s ", bb->use[i]->name);
        printf("\n");

        printf("def: ");
        for (int i = 0; i < bb->def_cnt; i++)
            printf("%s ", bb->def[i]->name);
        printf("\n");
    }

    printf("==========================\n");
}

// 添加符号到集合
void add_to_set(SYM **set, int *cnt, SYM *s)
{
    if (!s)
        return;
    for (int i = 0; i < *cnt; i++)
    {
        if (set[i] == s)
            return;
    }
    set[(*cnt)++] = s;
}

// 覆盖删除集合中的符号
void remove_from_set(SYM **set, int *cnt, SYM *v)
{
    for (int i = 0; i < *cnt; i++)
    {
        if (set[i] == v)
        {
            set[i] = set[(*cnt) - 1];
            (*cnt)--;
            return;
        }
    }
}

void compute_def_use()
{
    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        bb->def_cnt = bb->use_cnt = 0;

        for (TAC *t = bb->first;; t = t->next)
        {
            SYM *a = t->a;
            SYM *b = t->b;
            SYM *c = t->c;

            switch (t->op)
            {
            // 二元运算
            case TAC_COPY:
            case TAC_ADD:
            case TAC_SUB:
            case TAC_MUL:
            case TAC_DIV:
            case TAC_EQ:
            case TAC_NE:
            case TAC_LT:
            case TAC_LE:
            case TAC_GT:
            case TAC_GE:
                // use: b, c
                if (is_var(b) && !in_list(bb->def, bb->def_cnt, b) && !in_list(bb->use, bb->use_cnt, b))
                    bb->use[bb->use_cnt++] = b;

                if (is_var(c) && !in_list(bb->def, bb->def_cnt, c) && !in_list(bb->use, bb->use_cnt, c))
                    bb->use[bb->use_cnt++] = c;

                // def: a
                if (is_var(a) && !in_list(bb->def, bb->def_cnt, a))
                    bb->def[bb->def_cnt++] = a;
                break;

            // input a 视为def a
            case TAC_INPUT:
                if (is_var(a) && !in_list(bb->def, bb->def_cnt, a))
                    bb->def[bb->def_cnt++] = a;
                break;

            // output/return: use a
            case TAC_OUTPUT:
            case TAC_RETURN:
                if (is_var(a) && !in_list(bb->def, bb->def_cnt, a) && !in_list(bb->use, bb->use_cnt, a))
                    bb->use[bb->use_cnt++] = a;
                break;

            case TAC_IFZ:
                if (is_var(b) && !in_list(bb->def, bb->def_cnt, b) && !in_list(bb->use, bb->use_cnt, b))
                    bb->use[bb->use_cnt++] = b;
                break;

            // GOTO / LABEL / BEGIN / END / VAR：不产生 def/use
            case TAC_GOTO:
            case TAC_LABEL:
            case TAC_BEGINFUNC:
            case TAC_ENDFUNC:
            case TAC_VAR:
                break;

            default:
                break;
            }

            if (t == bb->last)
                break;
        }
    }
}

void print_liveness()
{
    printf("===== Liveness Info =====\n");

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        printf("BB%d\n", bb->id);

        printf("IN: ");
        for (int i = 0; i < bb->in_cnt; i++)
            printf("%s ", bb->in[i]->name);
        printf("\n");

        printf("OUT:");
        for (int i = 0; i < bb->out_cnt; i++)
            printf("%s ", bb->out[i]->name);
        printf("\n\n");
    }

    printf("==========================\n");
}

void live_variables_analysis()
{
    int changed = 1;

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        bb->in_cnt = 0;
        bb->out_cnt = 0;
    }

    while (changed)
    {
        changed = 0;

        for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
        {
            SYM *old_in[1024];
            SYM *old_out[1024];
            int old_in_cnt = bb->in_cnt;
            int old_out_cnt = bb->out_cnt;

            // 记录旧值用于比较
            memcpy(old_in, bb->in, sizeof(SYM *) * bb->in_cnt);
            memcpy(old_out, bb->out, sizeof(SYM *) * bb->out_cnt);

            bb->out_cnt = 0;

            // OUT[B] = ∪ IN[S], 将所有后继的输入加入到当前BB的输出中
            for (int i = 0; i < bb->succ_count; i++)
            {
                BASIC_BLOCK *succ = bb->succ[i];
                for (int j = 0; j < succ->in_cnt; j++)
                {
                    add_to_set(bb->out, &bb->out_cnt, succ->in[j]);
                }
            }

            // IN[B] = USE ∪ (OUT - DEF)
            bb->in_cnt = 0;

            // USE加入到IN中
            for (int i = 0; i < bb->use_cnt; i++)
            {
                add_to_set(bb->in, &bb->in_cnt, bb->use[i]);
            }

            // OUT的符号不在DEF中则加入IN
            for (int i = 0; i < bb->out_cnt; i++)
            {
                SYM *s = bb->out[i];
                if (!in_list(bb->def, bb->def_cnt, s))
                {
                    add_to_set(bb->in, &bb->in_cnt, s);
                }
            }

            // IN是否改变
            if (old_in_cnt != bb->in_cnt || old_out_cnt != bb->out_cnt ||
                memcmp(old_in, bb->in, sizeof(SYM *) * old_in_cnt) != 0 ||
                memcmp(old_out, bb->out, sizeof(SYM *) * old_out_cnt) != 0)
            {
                changed = 1;
            }
        }
    }
}

int global_dead_assignment()
{
    int changed = 0;

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        SYM *live[1024];
        int live_cnt = bb->out_cnt;

        memcpy(live, bb->out, sizeof(SYM *) * live_cnt); // 使用当前BB的out初始化live

        TAC *first = bb->first;

        for (TAC *p = bb->last; p;)
        {
            TAC *prev = p->prev;
            int is_first = (p == first);

            SYM *a = p->a;
            SYM *b = p->b;
            SYM *c = p->c;

            switch (p->op)
            {
            // 二元运算：use b,c
            case TAC_COPY:
            case TAC_ADD:
            case TAC_SUB:
            case TAC_MUL:
            case TAC_DIV:
            case TAC_EQ:
            case TAC_NE:
            case TAC_LT:
            case TAC_LE:
            case TAC_GT:
            case TAC_GE:
                if (is_var(b))
                    add_live(live, &live_cnt, b);
                if (is_var(c))
                    add_live(live, &live_cnt, c);
                break;

            // output/return/ifz: use a
            case TAC_OUTPUT:
            case TAC_RETURN:
                if (is_var(a))
                    add_live(live, &live_cnt, a);
                break;

            case TAC_IFZ:
                if (is_var(b))
                    add_live(live, &live_cnt, b);
                break;

            // 其他 op：根据需要再补
            default:
                break;
            }

            if (a && (a->type == SYM_VAR || a->type == SYM_TMP) && is_def_tac(p))
            {

                int used_later = live_contains(live, live_cnt, a);

                if (!used_later) // 不在live里就删除，无需后续还有定义
                {
                    remove_tac_bb(bb, p);
                    changed = 1;

                    if (is_first)
                        break;

                    p = prev;
                    continue;
                }

                for (int i = 0; i < live_cnt; i++)
                {
                    if (live[i] == a)
                    {
                        live[i] = live[--live_cnt];
                        break;
                    }
                }
            }

            if (is_first)
                break;
            p = prev;
        }
    }

    return changed;
}

// 是否是二元运算
int is_exp_op(int op)
{
    return (op == TAC_ADD || op == TAC_SUB ||
            op == TAC_MUL || op == TAC_DIV ||
            op == TAC_EQ || op == TAC_NE ||
            op == TAC_LT || op == TAC_LE ||
            op == TAC_GT || op == TAC_GE);
}

// 处理交换律：是否是交换律, 加乘==！=是
int is_commutative_op(int op)
{
    return (op == TAC_ADD || op == TAC_MUL || op == TAC_EQ || op == TAC_NE);
}

// 处理交换律：通过按地址排序让两个符合交换律的式子相同
void normalize_operands(int op, SYM **pb, SYM **pc)
{
    SYM *b = *pb;
    SYM *c = *pc;

    if (!is_commutative_op(op))
        return;

    if (b > c)
    {
        SYM *tmp = b;
        b = c;
        c = tmp;
    }

    *pb = b;
    *pc = c;
}

// 创建一个新节点
expMap *new_exp(int op, SYM *b, SYM *c)
{
    expMap *e = (expMap *)malloc(sizeof(expMap));
    e->id = exp_cnt++;
    e->op = op;
    e->b = b;
    e->c = c;
    e->t = NULL;
    e->next = exp_list;
    exp_list = e;

    return e;
}

expMap *find_exp(int op, SYM *b, SYM *c)
{
    for (expMap *e = exp_list; e; e = e->next)
    {
        if (e->op == op && e->b == b && e->c == c)
            return e;
    }
    return NULL;
}

expMap *find_exp_in_map(expMap *map, int op, SYM *b, SYM *c)
{
    for (expMap *p = map; p; p = p->next)
    {
        if (p->op == op && p->b == b && p->c == c)
            return p;
    }
    return NULL;
}

// 查找并返回规范化的表达式
expMap *get_exp(int op, SYM *b, SYM *c)
{
    if (!is_exp_op(op) || !b || !c)
        return NULL;

    normalize_operands(op, &b, &c);

    expMap *e = find_exp(op, b, c);
    if (!e)
    {
        e = new_exp(op, b, c);
    }
    return e;
}

// 初始化
void init_blocks()
{
    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        bb->gen = (unsigned char *)calloc(exp_cnt, sizeof(unsigned char));
        bb->kill = (unsigned char *)calloc(exp_cnt, sizeof(unsigned char));
        bb->ae_in = (unsigned char *)calloc(exp_cnt, sizeof(unsigned char));
        bb->ae_out = (unsigned char *)calloc(exp_cnt, sizeof(unsigned char));
    }
}

void build_expMap()
{
    exp_list = NULL;
    exp_cnt = 0;

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        for (TAC *p = bb->first; p; p = p->next)
        {
            if (is_exp_op(p->op) && p->b && p->c)
            {
                get_exp(p->op, p->b, p->c);
            }
        }
    }
}

// 计算gen,kill
void compute_gen_kill()
{
    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        memset(bb->gen, 0, exp_cnt);
        memset(bb->kill, 0, exp_cnt);
        for (TAC *p = bb->first; p != bb->last->next; p = p->next)
        {
            if ((is_exp_op(p->op)) && p->b && p->c)
            {
                expMap *e = get_exp(p->op, p->b, p->c);

                // 加入GEN
                bb->gen[e->id] = 1;
            }

            if ((p->op == TAC_COPY || is_exp_op(p->op)) && p->a)
            {
                SYM *x = p->a;
                // kill所有含x的表达式
                for (expMap *e = exp_list; e; e = e->next)
                {
                    if (e->b == x || e->c == x)
                    {
                        bb->kill[e->id] = 1;
                    }
                }
            }
        }
    }
}

void print_gen_kill()
{
    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        printf("BB %p:\n", bb);

        printf("GEN: ");
        for (int i = 0; i < exp_cnt; i++)
            if (bb->gen[i])
                printf("%d ", i);
        printf("\n");

        printf("KILL: ");
        for (int i = 0; i < exp_cnt; i++)
            if (bb->kill[i])
                printf("%d ", i);
        printf("\n");
    }
}

// 计算可用表达式分析中的in: 前驱所有BB的out的集合
void compute_ae_in(BASIC_BLOCK *bb)
{
    if (bb->pred_count == 0)
    {
        memset(bb->ae_in, 0, exp_cnt);
        return;
    }

    for (int i = 0; i < exp_cnt; i++)
    {
        bb->ae_in[i] = 1;
    }

    for (int p = 0; p < bb->pred_count; p++)
    {
        BASIC_BLOCK *pred = bb->pred[p];

        for (int i = 0; i < exp_cnt; i++) // 逐位取交集
        {
            bb->ae_in[i] = bb->ae_in[i] && pred->ae_out[i];
        }
    }
}

// 计算可用表达式分析中的out: gen ∪ (IN - kill)
int compute_ae_out(BASIC_BLOCK *bb)
{
    unsigned char new_out[1024];
    memset(new_out, 0, 1024);

    for (int i = 0; i < exp_cnt; i++)
    { // out = gen ∪ (in - kill)
        new_out[i] = (bb->gen[i] || bb->ae_in[i]) && (!bb->kill[i]);
    }

    int changed = 0;
    for (int i = 0; i < exp_cnt; i++)
    {
        if (new_out[i] != bb->ae_out[i])
        {
            changed = 1;
            break;
        }
    }

    memcpy(bb->ae_out, new_out, exp_cnt);
    return changed;
}

void available_expressions_analysis()
{
    int changed = 1;
    BASIC_BLOCK *entry = bb_list;

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        if (bb == entry)
            memset(bb->ae_out, 0, exp_cnt); // entry初始out为空集
        else
        {
            for (int i = 0; i < exp_cnt; i++) // 初始out为全集
                bb->ae_out[i] = 1;
        }
    }

    while (changed)
    {
        changed = 0;
        for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
        {
            compute_ae_in(bb);
            if (compute_ae_out(bb))
                changed = 1;
        }
    }
}

void print_available_expressions()
{
    printf("===== Available Expressions Analysis Result =====\n");

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        printf("BB %p:\n", bb);

        printf("IN : ");
        for (int i = 0; i < exp_cnt; i++)
            if (bb->ae_in[i])
                printf("%d ", i);
        printf("\n");

        printf("OUT: ");
        for (int i = 0; i < exp_cnt; i++)
            if (bb->ae_out[i])
                printf("%d ", i);
        printf("\n\n");
    }
}

static SYM *exp_temp[1024]; // 表达式id上一次被计算时产生的临时变量

void kill_expression(expMap **map, SYM *a)
{
    expMap **pp = map;
    while (*pp)
    {
        expMap *q = *pp;
        if (q->b == a || q->c == a)
        {
            *pp = q->next;
            free(q);
        }
        else
        {
            pp = &((*pp)->next);
        }
    }
}

int global_expression_elimination()
{
    int changed = 0;

    for (int i = 0; i < exp_cnt; i++)
        exp_temp[i] = NULL;

    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        expMap *map = NULL;

        for (expMap *e = exp_list; e; e = e->next)
        {
            if (bb->ae_in[e->id] == 1 && exp_temp[e->id]) // 根据BB的IN构建map,即当前BB内可复用的表达式表
            {
                insert_exp(&map, e->op, e->b, e->c, exp_temp[e->id]);
            }
        }

        TAC *next;
        for (TAC *p = bb->first; p != bb->last->next; p = next)
        {
            next = p->next;

            int op = p->op;

            if (!is_exp_op(op))
            {
                if (p->a && (op == TAC_COPY || op == TAC_INPUT))
                {
                    SYM *a = p->a;

                    // 从exp_temp中删除
                    for (expMap *e = exp_list; e; e = e->next)
                    {
                        if (e->b == a || e->c == a)
                        {
                            exp_temp[e->id] = NULL;
                        }
                    }
                    kill_expression(&map, a);
                }
                continue;
            }

            SYM *b = p->b;
            SYM *c = p->c;
            if (!b || !c)
                continue;

            expMap *m = find_exp_in_map(map, op, b, c);

            if (m)
            {
                SYM *oldt = m->t; // 用找到的对应的临时变量进行替换

                p->op = TAC_COPY;
                p->b = oldt;
                p->c = NULL;
                changed++;
            }
            else
            {
                expMap *e = get_exp(op, b, c);
                int id = e->id;

                exp_temp[id] = p->a;
                insert_exp(&map, op, b, c, p->a);
            }
        }
    }
    return changed;
}

#define MAX_BB 1024

int build_bb_array(BASIC_BLOCK **bb_array)
{
    int max_id = -1;
    for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
    {
        bb_array[bb->id] = bb;
        if (bb->id > max_id)
            max_id = bb->id;
    }
    return max_id + 1;
}

// dom[i][j]: BB i被BB j支配
static void compute_dominators(BASIC_BLOCK **bb_array, int bb_cnt, unsigned char dom[MAX_BB][MAX_BB])
{
    int entry_id = bb_list->id;

    // 初始：entry 只被自己支配，其余被所有节点支配
    for (int i = 0; i < bb_cnt; i++)
    {
        for (int j = 0; j < bb_cnt; j++)
            dom[i][j] = 1;
    }

    for (int j = 0; j < bb_cnt; j++)
        dom[entry_id][j] = 0;
    dom[entry_id][entry_id] = 1;

    int changed = 1;
    while (changed)
    {
        changed = 0;
        for (BASIC_BLOCK *bb = bb_list; bb; bb = bb->next)
        {
            int b = bb->id;
            if (b == entry_id)
                continue;

            // dom[B] = ∩ pred[B].dom
            unsigned char newdom[MAX_BB];

            for (int j = 0; j < bb_cnt; j++)
                newdom[j] = 1;

            if (bb->pred_count > 0)
            {
                // 初始化成第一个前驱的dom
                BASIC_BLOCK *p0 = bb->pred[0];
                for (int j = 0; j < bb_cnt; j++)
                    newdom[j] = dom[p0->id][j];

                // 与其它前驱的dom做交集
                for (int pi = 1; pi < bb->pred_count; pi++)
                {
                    BASIC_BLOCK *p = bb->pred[pi];
                    for (int j = 0; j < bb_cnt; j++)
                        newdom[j] = newdom[j] & dom[p->id][j];
                }
            }

            // 自己支配自己
            newdom[b] = 1;

            // 变化则继续计算
            for (int j = 0; j < bb_cnt; j++)
            {
                if (dom[b][j] != newdom[j])
                {
                    dom[b][j] = newdom[j];
                    changed = 1;
                }
            }
        }
    }
}

static int in_block_list(BASIC_BLOCK **list, int cnt, BASIC_BLOCK *bb)
{
    for (int i = 0; i < cnt; i++)
        if (list[i] == bb)
            return 1;
    return 0;
}

// 由tail到header的所有基本块集合
static void collect_natural_loop(
    BASIC_BLOCK *header,
    BASIC_BLOCK *tail,
    BASIC_BLOCK **loop_blocks,
    int *loop_cnt,
    unsigned char dom[MAX_BB][MAX_BB])
{
    *loop_cnt = 0;

    loop_blocks[(*loop_cnt)++] = header;
    if (!in_block_list(loop_blocks, *loop_cnt, tail))
        loop_blocks[(*loop_cnt)++] = tail;

    BASIC_BLOCK *stack[MAX_BB];
    int top = 0;
    stack[top++] = tail;

    // DFS遍历
    while (top > 0)
    {
        BASIC_BLOCK *m = stack[--top];

        for (int i = 0; i < m->pred_count; i++)
        {
            BASIC_BLOCK *p = m->pred[i];

            // header 本身除外
            if (p == header)
                continue;

            // p 没被header支配，是循环外的节点，不能加入循环
            if (!dom[p->id][header->id])
                continue;

            // 在循环内
            if (!in_block_list(loop_blocks, *loop_cnt, p))
            {
                loop_blocks[(*loop_cnt)++] = p;
                stack[top++] = p;
            }
        }
    }
}

// 找到循环前的唯一一个环外前驱
static BASIC_BLOCK *find_preheader(BASIC_BLOCK *header,
                                   BASIC_BLOCK **loop_blocks, int loop_cnt)
{
    BASIC_BLOCK *preheader = NULL;

    // 遍历循环header的所有前驱
    for (int i = 0; i < header->pred_count; i++)
    {
        BASIC_BLOCK *p = header->pred[i];
        if (!in_block_list(loop_blocks, loop_cnt, p))
        {
            if (preheader == NULL)
                preheader = p;
            else
                return NULL; // 有多个环外前驱，放弃这个环
        }
    }
    return preheader;
}

static int sym_in_defs(SYM *s, SYM **def_list, int def_cnt)
{
    return in_list(def_list, def_cnt, s);
}

static int sym_in_list2(SYM **list, int cnt, SYM *s)
{
    return in_list(list, cnt, s);
}
static int can_hoist_tac(TAC *p,
                         SYM **loop_defs, int loop_def_cnt,
                         SYM **invariant_defs, int inv_def_cnt,
                         BASIC_BLOCK **loop_blocks, int loop_cnt)
{

    if (p->op == TAC_COPY)
    {
        SYM *a = p->a;
        SYM *b = p->b;

        if (!a || !b)
            return 0;
        if (a->type != SYM_TMP)
            return 0;

        if (sym_in_defs(b, loop_defs, loop_def_cnt))
        {
            if (!sym_in_list2(invariant_defs, inv_def_cnt, b))
                return 0;
        }

        return 1;
    }
    if (!is_exp_op(p->op))
        return 0;

    if (p->a->type != SYM_TMP)
        return 0;

    SYM *a = p->a;
    SYM *b = p->b;
    SYM *c = p->c;

    if (!a || !b || !c)
        return 0;

    int used = 0;
    for (int li = 0; li < loop_cnt; li++)
    {
        BASIC_BLOCK *bb = loop_blocks[li];
        for (TAC *q = bb->first; q && q != bb->last->next; q = q->next)
        {
            if (q->op == TAC_IFZ) // ifz不能被移出循环
            {
                if (q->b == a)
                    return 0;
            }
            if (q->op == TAC_COPY && q->b == a) // 只移出临时变量类型
            {
                if (q->a && q->a->type == SYM_VAR)
                    return 0;
            }

            if (q->b == a || q->c == a) // 临时变量的值只被临时变量使用，才会移出
            {
                used = 1;
                break;
            }
        }
        if (used)
            break;
    }

    if (!used)
        return 0;

    // 操作数在循环中不被重新赋值
    SYM *ops[2] = {b, c};
    for (int i = 0; i < 2; i++)
    {
        SYM *s = ops[i];
        if (!s)
            continue;

        if (sym_in_defs(s, loop_defs, loop_def_cnt))
        {
            if (!sym_in_list2(invariant_defs, inv_def_cnt, s))
                return 0;
        }
    }

    return 1;
}

int tac_in_bb(TAC *pos, BASIC_BLOCK *bb)
{
    if (!pos || !bb || !bb->first || !bb->last)
        return 0;

    for (TAC *q = bb->first; q; q = q->next)
    {
        if (q == pos)
            return 1;
        if (q == bb->last)
            break;
    }
    return 0;
}

static void insert_tac_after(TAC *p, TAC *pos, BASIC_BLOCK *bb)
{
    // 如果 pos 不属于这个 bb，则强制让pos = bb->last
    if (pos && !tac_in_bb(pos, bb))
        pos = bb->last;

    // 链表插入
    if (!pos)
    {
        // 插入链表头
        p->next = tac_first;
        if (tac_first)
            tac_first->prev = p;
        tac_first = p;

        if (!bb->first)
            bb->first = p;
    }
    else
    {
        // 插到 pos 后
        p->next = pos->next;
        if (pos->next)
            pos->next->prev = p;
        pos->next = p;
        p->prev = pos;

        // 如果 pos 是 bb 的 last，则更新 last
        if (pos == bb->last)
            bb->last = p;
    }

    // 如果 bb 是空块，那么 p 既是 first 也是 last
    if (!bb->first)
        bb->first = bb->last = p;
}

// 循环内部找临时变量a的变量声明，获得所在基本块
static TAC *find_var_def_in_loop(SYM *a,
                                 BASIC_BLOCK **loop_blocks, int loop_cnt,
                                 BASIC_BLOCK **var_bb_out)
{
    for (int i = 0; i < loop_cnt; i++)
    {
        BASIC_BLOCK *bb = loop_blocks[i];
        for (TAC *q = bb->first; q && q != bb->last->next; q = q->next)
        {
            if (q->op == TAC_VAR && q->a == a)
            {
                if (var_bb_out)
                    *var_bb_out = bb;
                return q;
            }
        }
    }
    return NULL;
}

// 收集循环内所有被赋值的变量，loop_defs
static void collect_loop_defs(
    BASIC_BLOCK **loop_blocks,
    int loop_cnt,
    SYM **loop_defs,
    int *loop_def_cnt)
{
    *loop_def_cnt = 0;

    // 逐个遍历循环块
    for (int i = 0; i < loop_cnt; i++)
    {
        BASIC_BLOCK *bb = loop_blocks[i];

        for (int j = 0; j < bb->def_cnt; j++)
        {
            // 利用BB的def
            SYM *d = bb->def[j];

            // 去重
            int found = 0;
            for (int k = 0; k < *loop_def_cnt; k++)
            {
                if (loop_defs[k] == d)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                loop_defs[*loop_def_cnt] = d;
                (*loop_def_cnt)++;
            }
        }
    }
}

int loop_invariant_code_motion()
{
    int changed = 0;

    if (!bb_list)
        return 0;

    BASIC_BLOCK *bb_array[MAX_BB] = {0};
    int bb_cnt = build_bb_array(bb_array);

    // 计算 dom
    static unsigned char dom[MAX_BB][MAX_BB];
    compute_dominators(bb_array, bb_cnt, dom);

    // 找所有tail -> header，满足 header 支配 tail
    for (BASIC_BLOCK *tail = bb_list; tail; tail = tail->next)
    {
        for (int si = 0; si < tail->succ_count; si++)
        {
            BASIC_BLOCK *header = tail->succ[si];
            int t_id = tail->id;
            int h_id = header->id;

            // header 支配 tail
            if (dom[t_id][h_id])
            {
                // natural loop
                BASIC_BLOCK *loop_blocks[MAX_BB];
                int loop_cnt = 0;
                collect_natural_loop(header, tail, loop_blocks, &loop_cnt, dom);

                // 找 preheader
                BASIC_BLOCK *preheader = find_preheader(header, loop_blocks, loop_cnt);
                if (!preheader)
                    continue; // 没有合适 preheader，跳过这个 loop

                // 收集环内 def 集合
                SYM *loop_defs[1024];
                int loop_def_cnt = 0;
                collect_loop_defs(loop_blocks, loop_cnt, loop_defs, &loop_def_cnt);

                // 迭代寻找所有 loop-invariant 指令
                SYM *invariant_defs[1024]; // 确认是循环不变量的变量集合
                int inv_def_cnt = 0;

                TAC *hoist_tac[1024]; // 需要搬到preheader的表达式TAC
                BASIC_BLOCK *hoist_bb[1024];
                int hoist_cnt = 0;

                TAC *hoist_var_tac[1024];        // 定义循环内不变量的变量声明
                BASIC_BLOCK *hoist_var_bb[1024]; // 变量声明的BB
                SYM *hoisted_temps[1024];        // 已经处理过的临时变量
                int hoist_var_cnt = 0;

                for (int li = 0; li < loop_cnt; li++)
                {
                    // 扫描循环内所有BB
                    BASIC_BLOCK *bb = loop_blocks[li];
                    for (TAC *p = bb->first; p && p != bb->last->next; p = p->next)
                    {
                        if (!is_exp_op(p->op))
                            continue;

                        if (can_hoist_tac(p, loop_defs, loop_def_cnt,
                                          invariant_defs, inv_def_cnt,
                                          loop_blocks, loop_cnt))

                        {
                            hoist_tac[hoist_cnt] = p;
                            hoist_bb[hoist_cnt] = bb;
                            hoist_cnt++;

                            // 记录它定义的 a 为 invariant 定义
                            if (p->a && !sym_in_list2(invariant_defs, inv_def_cnt, p->a))
                                invariant_defs[inv_def_cnt++] = p->a;

                            // 对应的 var 也被挪到 preheader
                            if (!sym_in_list2(hoisted_temps, hoist_var_cnt, p->a))
                            {
                                BASIC_BLOCK *var_bb = NULL;
                                TAC *var_tac = find_var_def_in_loop(p->a, loop_blocks, loop_cnt, &var_bb);
                                if (var_tac && var_bb)
                                {
                                    hoist_var_tac[hoist_var_cnt] = var_tac;
                                    hoist_var_bb[hoist_var_cnt] = var_bb;
                                    hoisted_temps[hoist_var_cnt] = p->a;
                                    hoist_var_cnt++;
                                }
                            }
                        }
                    }
                }

                if (hoist_cnt == 0)
                    continue;

                TAC *var_insert_pos = NULL;
                for (TAC *q = preheader->first; q && q != preheader->last->next; q = q->next)
                {
                    if (q->op == TAC_VAR)
                        var_insert_pos = q; // 不变量定义插入到preheader中所有VAR的后面
                }

                TAC *insert_pos = preheader->last; // 不变量的赋值TAC插入到preheader的最后

                for (int i = 0; i < hoist_var_cnt; i++) // 插入不变量定义
                {
                    TAC *v = hoist_var_tac[i];
                    BASIC_BLOCK *from_bb = hoist_var_bb[i];

                    remove_tac_bb(from_bb, v);

                    // 插到最后一个 var 后面
                    insert_tac_after(v, var_insert_pos, preheader);
                    var_insert_pos = v;
                    changed = 1;
                }

                for (int i = 0; i < hoist_cnt; i++) // 插入赋值TAC
                {
                    TAC *p = hoist_tac[i];
                    BASIC_BLOCK *from_bb = hoist_bb[i];

                    remove_tac_bb(from_bb, p);
                    insert_tac_after(p, insert_pos, preheader);
                    insert_pos = p;
                }
            }
        }
    }

    return changed;
}

int tac_uses_sym(TAC *p, SYM *s)
{
    if (!p || !s)
        return 0;

    // 所有使用 b 和 c 的 TAC
    switch (p->op)
    {
    case TAC_COPY:
    case TAC_ADD:
    case TAC_SUB:
    case TAC_MUL:
    case TAC_DIV:
    case TAC_EQ:
    case TAC_NE:
    case TAC_LT:
    case TAC_LE:
    case TAC_GT:
    case TAC_GE:
        if (p->b == s || p->c == s)
            return 1;
        return 0;

    case TAC_OUTPUT:
        return (p->a == s);

    case TAC_IFZ:
        return (p->b == s);

    case TAC_RETURN:
        return (p->a == s);

    default:
        return 0;
    }
}

int loop_sinking()
{
    int changed = 0;

    if (!bb_list)
        return 0;

    // 构建bb_array，计算dom支配关系
    BASIC_BLOCK *bb_array[MAX_BB] = {0};
    int bb_cnt = build_bb_array(bb_array);

    unsigned char dom[MAX_BB][MAX_BB];
    compute_dominators(bb_array, bb_cnt, dom);

    // 遍历所有回边 tail到header
    for (BASIC_BLOCK *tail = bb_list; tail; tail = tail->next)
    {
        for (int si = 0; si < tail->succ_count; si++)
        {
            BASIC_BLOCK *header = tail->succ[si];
            if (!header)
                continue;

            int t = tail->id;
            int h = header->id;

            // 不是回边，跳过
            if (!dom[t][h])
                continue;

            // 得到这个回边对应的自然循环
            BASIC_BLOCK *loop_blocks[MAX_BB];
            int loop_cnt = 0;
            collect_natural_loop(header, tail, loop_blocks, &loop_cnt, dom);

            // 找header 的唯一一个环外前驱
            BASIC_BLOCK *preheader = find_preheader(header, loop_blocks, loop_cnt);
            if (!preheader)
                continue;

            // 如果preheader没有前驱，为了避免跨过input等初始化，直接跳过
            if (preheader->pred_count == 0)
                continue;

            // 在这个循环里找可以下沉的var = tmp类型
            for (int li = 0; li < loop_cnt; li++)
            {
                BASIC_BLOCK *bb = loop_blocks[li];

                for (TAC *p = bb->first; p && p != bb->last->next; p = p->next)
                {
                    if (!is_def_tac(p))
                        continue;

                    SYM *a = p->a;
                    if (!a)
                        continue;
                    if (a->type != SYM_VAR)
                        continue;

                    // a 在这个循环里恰好定义一次
                    int def_times = 0;
                    BASIC_BLOCK *def_bb = NULL;
                    TAC *def_tac = NULL;

                    for (int lj = 0; lj < loop_cnt; lj++)
                    {
                        BASIC_BLOCK *bb2 = loop_blocks[lj];
                        for (TAC *q = bb2->first; q && q != bb2->last->next; q = q->next)
                        {
                            if (is_def_tac(q) && q->a == a)
                            {
                                def_times++;
                                def_bb = bb2;
                                def_tac = q;
                            }
                        }
                    }

                    if (def_times != 1 || !def_tac)
                        continue;

                    // 定义是 a TAC_COPY tmp 形式
                    if (def_tac->op != TAC_COPY)
                        continue;

                    SYM *tmp = def_tac->b;
                    if (!tmp || tmp->type != SYM_TMP)
                        continue;

                    // a 在循环内部不被使用
                    int used_in_loop = 0;
                    for (int lj = 0; lj < loop_cnt; lj++)
                    {
                        BASIC_BLOCK *bb2 = loop_blocks[lj];
                        for (TAC *q = bb2->first; q && q != bb2->last->next; q = q->next)
                        {
                            if (q == def_tac)
                                continue;
                            if (tac_uses_sym(q, a))
                            {
                                used_in_loop = 1;
                                break;
                            }
                        }
                        if (used_in_loop)
                            break;
                    }
                    if (used_in_loop)
                        continue;

                    // a在循环外被使用
                    int used_outside = 0;
                    for (BASIC_BLOCK *bb2 = bb_list; bb2; bb2 = bb2->next)
                    {
                        int in_loop = 0;
                        for (int k = 0; k < loop_cnt; k++)
                        {
                            if (loop_blocks[k] == bb2)
                            {
                                in_loop = 1;
                                break;
                            }
                        }
                        if (in_loop)
                            continue;

                        for (TAC *q = bb2->first; q && q != bb2->last->next; q = q->next)
                        {
                            if (tac_uses_sym(q, a))
                            {
                                used_outside = 1;
                                break;
                            }
                        }
                        if (used_outside)
                            break;
                    }
                    if (!used_outside)
                        continue;

                    // tmp 在循环里恰好有一个定义
                    int tmp_def_times = 0;
                    BASIC_BLOCK *tmp_def_bb = NULL;
                    TAC *tmp_def_tac = NULL;

                    for (int lj = 0; lj < loop_cnt; lj++)
                    {
                        BASIC_BLOCK *bb2 = loop_blocks[lj];
                        for (TAC *q = bb2->first; q && q != bb2->last->next; q = q->next)
                        {
                            if (is_def_tac(q) && q->a == tmp)
                            {
                                tmp_def_times++;
                                tmp_def_bb = bb2;
                                tmp_def_tac = q;
                            }
                        }
                    }

                    if (tmp_def_times != 1 || !tmp_def_tac)
                        continue;

                    // tmp的定义是二元表达式
                    if (!is_exp_op(tmp_def_tac->op))
                        continue;

                    // tmp 在循环内只被a = tmp这一处使用
                    int tmp_used_other = 0;
                    for (int lj = 0; lj < loop_cnt; lj++)
                    {
                        BASIC_BLOCK *bb2 = loop_blocks[lj];
                        for (TAC *q = bb2->first; q && q != bb2->last->next; q = q->next)
                        {
                            if (q == tmp_def_tac || q == def_tac)
                                continue;
                            if (tac_uses_sym(q, tmp))
                            {
                                tmp_used_other = 1;
                                break;
                            }
                        }
                        if (tmp_used_other)
                            break;
                    }
                    if (tmp_used_other)
                        continue;

                    // tmp_def_tac的操作数在这个循环内不能被重新定义
                    int invariant = 1;
                    SYM *b = tmp_def_tac->b;
                    SYM *c = tmp_def_tac->c;
                    SYM *ops[2] = {b, c};

                    for (int bi = 0; bi < 2 && invariant; bi++)
                    {
                        SYM *s = ops[bi];
                        if (!s)
                            continue;

                        for (int li2 = 0; li2 < loop_cnt; li2++)
                        {
                            BASIC_BLOCK *bb2 = loop_blocks[li2];
                            for (TAC *q = bb2->first; q && q != bb2->last->next; q = q->next)
                            {
                                if (is_def_tac(q) && q->a == s)
                                {
                                    invariant = 0;
                                    break;
                                }
                            }
                            if (!invariant)
                                break;
                        }
                    }

                    if (!invariant)
                        continue;

                    // 满足所有条件，可以下沉
                    // 把 tmp_def_tac 和 def_tac 移动到 preheader 末尾
                    TAC *new_tmp_def = mk_tac(tmp_def_tac->op,
                                              tmp_def_tac->a,
                                              tmp_def_tac->b,
                                              tmp_def_tac->c);
                    TAC *new_def = mk_tac(def_tac->op,
                                          def_tac->a,
                                          def_tac->b,
                                          def_tac->c);

                    // 插入位置：preheader->last 之后
                    TAC *insert_pos = preheader->last;
                    insert_tac_after(new_tmp_def, insert_pos, preheader);
                    insert_pos = new_tmp_def;
                    insert_tac_after(new_def, insert_pos, preheader);

                    // 删除循环内部的原始定义
                    remove_tac_bb(tmp_def_bb, tmp_def_tac);
                    remove_tac_bb(def_bb, def_tac);

                    changed = 1;
                }
            }
        }
    }

    return changed;
}

// 判断是否是常量类型
static int is_const_sym(SYM *s)
{
    if (!s)
        return 0;
    return (s->type == SYM_INT || s->type == SYM_CHAR);
}

static int find_const_entry(ConstEntry *tab, int cnt, SYM *v)
{
    for (int i = 0; i < cnt; i++)
    {
        if (tab[i].var == v)
            return i;
    }
    return -1;
}

int global_constant_propagation()
{
    ConstEntry tab[MAX_CONST_ENTRY];
    int tab_cnt = 0;
    int changed = 0;

    // 初始化
    for (int i = 0; i < MAX_CONST_ENTRY; i++)
    {
        tab[i].var = NULL;
        tab[i].value = NULL;
        tab[i].state = 0;
    }

    /*********************
     * 第一次扫描：收集“全局常量变量”
     * 条件：某个变量在全程序中
     *  - 只出现一次赋值
     *  - 该赋值是  var = const;
     *********************/
    for (TAC *p = tac_first; p; p = p->next)
    {
        // ✅ 只看真正的“定义语句”（var=..., tmp=...）
        if (!is_def_tac(p))
            continue;

        SYM *a = p->a;
        SYM *b = p->b;

        if (!a || !is_var(a))
            continue;

        int idx = find_const_entry(tab, tab_cnt, a);

        int is_const_assign = 0;
        SYM *const_val = NULL;

        // 这里只认 var = const 这种形式
        if (p->op == TAC_COPY && is_const_sym(b) && p->c == NULL)
        {
            is_const_assign = 1;
            const_val = b;
        }

        if (idx < 0)
        {
            // 第一次看到这个变量的定义
            if (tab_cnt >= MAX_CONST_ENTRY)
                continue; // 防止溢出，直接放弃后面的

            idx = tab_cnt++;
            tab[idx].var = a;
            if (is_const_assign)
            {
                tab[idx].state = 1; // 确认常量
                tab[idx].value = const_val;
            }
            else
            {
                tab[idx].state = -1; // 不是常量（或不处理）
                tab[idx].value = NULL;
            }
        }
        else
        {
            // 已经见过一次，再遇到任何形式的赋值，都标记为非常量
            tab[idx].state = -1;
            tab[idx].value = NULL;
        }
    }

    /*********************
     * 第二次扫描：用常量替换 RHS 上的变量引用
     *********************/
    for (TAC *p = tac_first; p; p = p->next)
    {
        SYM *b = p->b;
        SYM *c = p->c;

        // 替换 b
        if (b && is_var_or_tmp(b))
        {
            int idx = find_const_entry(tab, tab_cnt, b);
            if (idx >= 0 && tab[idx].state == 1 && tab[idx].value && b != tab[idx].value)
            {
                p->b = tab[idx].value;
                changed = 1;
            }
        }

        // 替换 c
        if (c && is_var_or_tmp(c))
        {
            int idx = find_const_entry(tab, tab_cnt, c);
            if (idx >= 0 && tab[idx].state == 1 && tab[idx].value && c != tab[idx].value)
            {
                p->c = tab[idx].value;
                changed = 1;
            }
        }
    }

    return changed;
}

void global_optimize()
{
    int changed;

    do
    {
        changed = 0;

        if (global_constant_propagation())
            changed = 1;

        if (local_copy_propagation())
            changed = 1;
        if (local_constant_folding())
            changed = 1;

        build_cfg();
        compute_def_use();
        live_variables_analysis();
        build_expMap();
        init_blocks();
        compute_gen_kill();
        available_expressions_analysis();

        if (global_expression_elimination() != 0)
            changed = 1;

        if (local_copy_propagation())
            changed = 1;

        if (global_dead_assignment())
            changed = 1;

        if (loop_invariant_code_motion())
        {
            changed = 1;
            build_cfg();
            compute_def_use();
            live_variables_analysis();
            build_expMap();
            init_blocks();
            compute_gen_kill();
            available_expressions_analysis();
        }

        if (loop_sinking())
        {
            changed = 1;

            build_cfg();
            compute_def_use();
            live_variables_analysis();
        }
    } while (changed);
}