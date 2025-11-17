#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "tac.h"
#include "optimize.h"

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
        bb->def_cnt = 0;
        bb->use_cnt = 0;
        for (TAC *t = bb->first; t != bb->last->next; t = t->next)
        {
            SYM *a = t->a;
            SYM *b = t->b;
            SYM *c = t->c;

            if (is_var(b) && !in_list(bb->def, bb->def_cnt, b)) // 是变量且没被定义
            {
                if (!in_list(bb->use, bb->use_cnt, b))
                    bb->use[bb->use_cnt++] = b;
            }

            if (is_var(c) && !in_list(bb->def, bb->def_cnt, c))
            {
                if (!in_list(bb->use, bb->use_cnt, c))
                    bb->use[bb->use_cnt++] = c;
            }

            if (is_var(a))
            {
                if (!in_list(bb->def, bb->def_cnt, a)) // a首次被定义
                    bb->def[bb->def_cnt++] = a;
            }
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