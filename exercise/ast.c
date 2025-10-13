#include "ast.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

extern int sym_count;
extern struct
{
    char name[100];
    int value;
} sym[];

extern int get_value(const char *name);
extern void set_value(const char *name, int value);

static inline int to_bool(int x) { return x != 0; }

static void exec_seq(AST *seq);

int eval_expr(AST *expr)
{
    if (!expr)
        return 0;

    switch (expr->tag)
    {
    case AST_NUM:
        return expr->num.value;

    case AST_VAR:
        return get_value(expr->var.name);

    case AST_UNOP:
    {
        int v = eval_expr(expr->unop.expr);
        switch (expr->unop.op)
        {
        case OP_NEG:
            return -v;
        case OP_NOT:
            return !to_bool(v);
        default:
            fprintf(stderr, "Unknown UNOP at line %d\n", expr->line);
            exit(1);
        }
    }

    case AST_BINOP:
    {
        int l = eval_expr(expr->binop.lhs);
        int r = eval_expr(expr->binop.rhs);
        switch (expr->binop.op)
        {
        case OP_ADD:
            return l + r;
        case OP_SUB:
            return l - r;
        case OP_MUL:
            return l * r;
        case OP_DIV:
            if (r == 0)
            {
                fprintf(stderr, "Runtime error (line %d): division by zero\n", expr->line);
                exit(1);
            }
            return l / r;

        case OP_LT:
            return to_bool(l < r);
        case OP_LE:
            return to_bool(l <= r);
        case OP_GT:
            return to_bool(l > r);
        case OP_GE:
            return to_bool(l >= r);
        case OP_EQ:
            return to_bool(l == r);
        case OP_NE:
            return to_bool(l != r);

        case OP_AND:
            return to_bool(l) && to_bool(r);
        case OP_OR:
            return to_bool(l) || to_bool(r);

        default:
            fprintf(stderr, "Unknown BINOP at line %d\n", expr->line);
            exit(1);
        }
    }

    case AST_ASSIGN:
        int v = eval_expr(expr->assign.expr);
        set_value(expr->assign.name, v);
        return v;

    case AST_IF:
    case AST_WHILE:
    case AST_SEQ:
        fprintf(stderr, "Invalid expression node (stmt) at line %d\n", expr->line);
        return 0;

    default:
        fprintf(stderr, "Unknown node tag in eval_expr\n");
        exit(1);
    }
}

void exec_stmt(AST *stmt)
{
    if (!stmt)
        return;

    switch (stmt->tag)
    {

    case AST_ASSIGN:
        set_value(stmt->assign.name, eval_expr(stmt->assign.expr));
        return;

    case AST_IF:
        if (eval_expr(stmt->if_.cond))
            exec_stmt(stmt->if_.then_branch);
        else
            exec_stmt(stmt->if_.else_branch);
        return;

    case AST_WHILE:
        while (eval_expr(stmt->while_.cond))
        {
            exec_stmt(stmt->while_.body);
        }
        return;

    case AST_SEQ:
        for (size_t i = 0; i < stmt->seq.count; ++i)
            exec_stmt(stmt->seq.stmts[i]);
        return;

    default:
        eval_expr(stmt);
        return;
    }
}

void exec_program(AST *root)
{
    exec_stmt(root);
    printf("\n********* Final Variable States *********\n");
    for (int i = 0; i < sym_count; i++)
    {
        printf("%s = %d\n", sym[i].name, get_value(sym[i].name));
    }
    printf("*******************************************\n");
}

static void indent_print(int indent)
{
    for (int i = 0; i < indent; i++)
        printf("  ");
}

void ast_print(AST *node, int indent)
{
    if (!node)
        return;
    indent_print(indent);

    switch (node->tag)
    {
    case AST_NUM:
        printf("[NUM] %d\n", node->num.value);
        break;

    case AST_VAR:
        printf("[VAR] %s\n", node->var.name);
        break;

    case AST_BINOP:
        printf("[BINOP] ");
        switch (node->binop.op)
        {
        case OP_ADD:
            printf("+\n");
            break;
        case OP_SUB:
            printf("-\n");
            break;
        case OP_MUL:
            printf("*\n");
            break;
        case OP_DIV:
            printf("/\n");
            break;
        case OP_LT:
            printf("<\n");
            break;
        case OP_LE:
            printf("<=\n");
            break;
        case OP_GT:
            printf(">\n");
            break;
        case OP_GE:
            printf(">=\n");
            break;
        case OP_EQ:
            printf("==\n");
            break;
        case OP_NE:
            printf("!=\n");
            break;
        case OP_AND:
            printf("&&\n");
            break;
        case OP_OR:
            printf("||\n");
            break;
        default:
            printf("?\n");
            break;
        }
        ast_print(node->binop.lhs, indent + 1);
        ast_print(node->binop.rhs, indent + 1);
        break;

    case AST_UNOP:
        printf("[UNOP] %s\n",
               node->unop.op == OP_NEG ? "-" : node->unop.op == OP_NOT ? "!"
                                                                       : "?");
        ast_print(node->unop.expr, indent + 1);
        break;

    case AST_ASSIGN:
        printf("[ASSIGN] %s =\n", node->assign.name);
        ast_print(node->assign.expr, indent + 1);
        break;

    case AST_IF:
        printf("[IF]\n");
        indent_print(indent + 1);
        printf("cond:\n");
        ast_print(node->if_.cond, indent + 2);

        indent_print(indent + 1);
        printf("then:\n");
        ast_print(node->if_.then_branch, indent + 2);

        if (node->if_.else_branch)
        {
            indent_print(indent + 1);
            printf("else:\n");
            ast_print(node->if_.else_branch, indent + 2);
        }
        break;

    case AST_WHILE:
        printf("[WHILE]\n");
        indent_print(indent + 1);
        printf("cond:\n");
        ast_print(node->while_.cond, indent + 2);
        indent_print(indent + 1);
        printf("body:\n");
        ast_print(node->while_.body, indent + 2);
        break;

    case AST_SEQ:
        printf("[SEQ]\n");
        for (size_t i = 0; i < node->seq.count; i++)
            ast_print(node->seq.stmts[i], indent + 1);
        break;

    default:
        printf("[UNKNOWN NODE]\n");
        break;
    }
}

static char *dup_cstr(const char *s)
{
    if (!s)
        return NULL;
    size_t n = strlen(s) + 1;
    char *p = (char *)malloc(n);
    if (p)
        memcpy(p, s, n);
    return p;
}

static AST *ast_new(ASTTag tag, int line)
{
    AST *n = (AST *)calloc(1, sizeof(AST));
    n->tag = tag;
    n->line = line;
    return n;
}

AST *ast_num(int line, Value v)
{
    AST *n = ast_new(AST_NUM, line);
    n->num.value = v;
    return n;
}

AST *ast_var(int line, const char *name)
{
    AST *n = ast_new(AST_VAR, line);
    n->var.name = dup_cstr(name);
    return n;
}

AST *ast_binop(int line, OP op, AST *lhs, AST *rhs)
{
    AST *n = ast_new(AST_BINOP, line);
    n->binop.op = op;
    n->binop.lhs = lhs;
    n->binop.rhs = rhs;
    return n;
}

AST *ast_unop(int line, OP op, AST *expr)
{
    AST *n = ast_new(AST_UNOP, line);
    n->unop.op = op;
    n->unop.expr = expr;
    return n;
}

AST *ast_assign(int line, const char *name, AST *expr)
{
    AST *n = ast_new(AST_ASSIGN, line);
    n->assign.name = dup_cstr(name);
    n->assign.expr = expr;
    return n;
}

AST *ast_seq_new(int line)
{
    AST *n = ast_new(AST_SEQ, line);
    n->seq.stmts = NULL;
    n->seq.count = 0;
    n->seq.capacity = 0;
    return n;
}

void ast_seq_push(AST *seq, AST *stmt)
{
    assert(seq && seq->tag == AST_SEQ);
    if (seq->seq.count == seq->seq.capacity)
    {
        size_t newcap = seq->seq.capacity ? seq->seq.capacity * 2 : 4;
        AST **newbuf = (AST **)realloc(seq->seq.stmts, newcap * sizeof(AST *));
        assert(newbuf && "Out of memory");
        seq->seq.stmts = newbuf;
        seq->seq.capacity = newcap;
    }
    seq->seq.stmts[seq->seq.count++] = stmt;
}

AST *ast_if(int line, AST *cond, AST *then_branch, AST *else_branch)
{
    AST *n = ast_new(AST_IF, line);
    n->if_.cond = cond;
    n->if_.then_branch = then_branch;
    n->if_.else_branch = else_branch; // 可为 NULL
    return n;
}

AST *ast_while(int line, AST *cond, AST *body)
{
    AST *n = ast_new(AST_WHILE, line);
    n->while_.cond = cond;
    n->while_.body = body;
    return n;
}

void ast_free(AST *node)
{
    if (!node)
        return;

    switch (node->tag)
    {
    case AST_NUM:
        break;

    case AST_VAR:
        free(node->var.name);
        break;

    case AST_BINOP:
        ast_free(node->binop.lhs);
        ast_free(node->binop.rhs);
        break;

    case AST_UNOP:
        ast_free(node->unop.expr);
        break;

    case AST_ASSIGN:
        free(node->assign.name);
        ast_free(node->assign.expr);
        break;

    case AST_SEQ:
        for (size_t i = 0; i < node->seq.count; ++i)
        {
            ast_free(node->seq.stmts[i]);
        }
        free(node->seq.stmts);
        break;

    case AST_IF:
        ast_free(node->if_.cond);
        ast_free(node->if_.then_branch);
        ast_free(node->if_.else_branch);
        break;

    case AST_WHILE:
        ast_free(node->while_.cond);
        ast_free(node->while_.body);
        break;
    }
    free(node);
}
