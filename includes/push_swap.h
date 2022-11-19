#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

#include "../libft/libft.h"
#include <unistd.h>

typedef struct {
  t_list *stack_a;
  t_list *stack_b;
  t_list *instructions;
} s_ctx;


void sa(s_ctx *context);
void sb(s_ctx *context);
void ss(s_ctx *context);
int pa(s_ctx *context);
int pb(s_ctx *context);
int ra(t_list *stack, t_list *instructions);
int rb(t_list *stack, t_list *instructions);
#endif
