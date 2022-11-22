#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

#include "../libft/libft.h"
#include <unistd.h>

typedef struct {
  t_list *stack_a;
  t_list *stack_b;
  t_list *instructions;
} s_ctx;


int sa(t_list *s1, t_list *instructions);
int sb(t_list *s1, t_list *instructions);
int ss(t_list *s1, t_list *s2, t_list *instructions);
int pa(t_list *s1, t_list *s2, t_list *instructions);
int pb(t_list *s1, t_list *s2, t_list *instructions);
int ra(t_list *s1, t_list *instructions);
int rb(t_list *s1, t_list *instructions);
int rra(t_list *s1, t_list *instructions);
int rrb(t_list *s1, t_list *instructions);
int rrr(t_list *s1, t_list *s2, t_list *instructions);
#endif
