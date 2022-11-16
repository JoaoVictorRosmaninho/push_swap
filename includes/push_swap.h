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
#endif
