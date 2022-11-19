#include "../../includes/push_swap.h"

void sb(s_ctx *context) {
  t_node *node_a;
  t_node *node_b;
  t_node *node_c;

  if (!context->stack_b->head)
    return ;

  node_a = context->stack_b->head; 
  node_b = node_a->next;  
  node_c = node_b->next; 
                        
  node_c->prev = node_a; 
  node_a->next = node_c; 

  node_a->prev = node_b;
  node_b->next = node_a; 
  
  node_b->prev = NULL;
  context->stack_b->head = node_b; 
}
