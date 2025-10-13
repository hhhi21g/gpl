#ifndef AST_H
#define AST_H

#include <stddef.h>

typedef int Value;

#ifdef __cplusplus
extern "C"
{
#endif

    typedef enum
    {
        AST_NUM,
        AST_VAR,
        AST_BINOP,
        AST_UNOP,

        AST_ASSIGN,
        AST_SEQ,
        AST_IF,
        AST_WHILE
    } ASTTag;

    typedef enum
    {
        OP_ADD,
        OP_SUB,
        OP_MUL,
        OP_DIV,
        OP_LT,
        OP_LE,
        OP_GT,
        OP_GE,
        OP_EQ,
        OP_NE,
        OP_AND,
        OP_OR,
        OP_NEG,
        OP_NOT
    } OP;

    typedef struct AST AST;

    struct AST
    {
        ASTTag tag;
        int line;

        union
        {
            struct
            {
                Value value;
            } num;
            struct
            {
                char *name;
            } var;
            struct
            {
                OP op;
                AST *lhs;
                AST *rhs;
            } binop;
            struct
            {
                OP op;
                AST *expr;
            } unop;
            struct
            {
                char *name;
                AST *expr;
            } assign;
            struct
            {
                AST **stmts;
                size_t count;
                size_t capacity;
            } seq;

            struct
            {
                AST *cond;
                AST *then_branch;
                AST *else_branch;
            } if_;

            struct
            {
                AST *cond;
                AST *body;
            } while_;
        };
    };

    // 构建节点
    AST *ast_num(int line, Value v);
    AST *ast_var(int line, const char *name);
    AST *ast_binop(int line, OP op, AST *lhs, AST *rhs);
    AST *ast_unop(int line, OP op, AST *expr);
    AST *ast_assign(int line, const char *name, AST *expr);

    AST *ast_seq_new(int line);
    void ast_seq_push(AST *seq, AST *stmt);

    AST *ast_if(int line, AST *cond, AST *then_branch, AST *else_branch);
    AST *ast_while(int line, AST *cond, AST *body);

    void ast_free(AST *node);

    int eval_expr(AST *expr);     // 计算表达式值
    void exec_stmt(AST *stmt);    // 执行单条语句
    void exec_program(AST *root); // 执行整个语法树
#ifdef __cplusplus
}
#endif

#endif