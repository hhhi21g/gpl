#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"
#include "optimize.h"

expMap *exp_list = NULL;
int exp_cnt = 0;

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

void global_optimize()
{
    int changed;

    do
    {
        changed = 0;

        // if (local_copy_propagation())
        //     changed = 1;

        // if (local_constant_folding())
        //     changed = 1;

        // if (local_expression_elimination() != 0)
        //     changed = 1;

        if (global_dead_assignment())
            changed = 1;

    } while (changed);
}