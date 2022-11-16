#include "../../includes/push_swap.h"

void sa(s_ctx *context) {
  t_node *node_a; 
  t_node *node_b; 

  if (!context->stack_a->head)
    return ;
  node_a = context->stack_a->head;
  node_b = node_a->next;
  node_a->next = node_a->next->next; // apontou pro c 
  node_b->next = node_a;
  context->stack_a->head = node_b;

}
