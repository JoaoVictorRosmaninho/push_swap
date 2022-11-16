#include "../../includes/push_swap.h"

void sa(s_ctx *context) {
  t_node *node;

  node = context->stack_a->tail;

  context->stack_a->tail = context->stack_a->tail->prev; 
  context->stack_a->tail->prev = node; 
}
