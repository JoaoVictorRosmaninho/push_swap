#include "../../includes/push_swap.h"

void sa(s_ctx *context) {
  t_node *node_a;
  t_node *node_b;
  t_node *node_c;

  if (!context->stack_a->head)
    return ;

  node_a = context->stack_a->head; // primeiro
  node_b = node_a->next;   //segundo
  node_c = node_b->next;  //terceiro 
                        
  node_c->prev = node_a; 
  node_a->next = node_c; // primeiro apontando pro terceiro

  node_a->prev = node_b;
  node_b->next = node_a; 
  
  node_b->prev = NULL;
  context->stack_a->head = node_b; // novo primeiro
}
