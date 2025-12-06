#ifndef OPTIMIZE_H
#define OPTIMIZE_H

void compute_def_use();
void print_def_use();

void live_variables_analysis();
void print_liveness();

int global_dead_assignment();
void global_optimize();

void init_blocks();
void build_expMap();
void compute_gen_kill();
void print_gen_kill();

void compute_ae_in(BASIC_BLOCK *bb);
int compute_ae_out(BASIC_BLOCK *bb);
void available_expressions_analysis();
void print_available_expressions();

int global_expression_elimination();
int loop_invariant_code_motion();

void kill_expression(expMap **map, SYM *a);
#endif
