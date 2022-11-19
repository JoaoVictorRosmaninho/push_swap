#include "../../includes/push_swap.h"


int rra(t_list *stack, t_list *instructions) {
  if ( !stack )
    return (0);
  
  t_node *node;

  node = stack->tail->prev;
  node->next = NULL;
  stack->tail->prev = NULL;
  stack->tail->next = stack->head;
  stack->head->prev = stack->tail;
  stack->head = stack->tail;
  stack->tail = node;
  if (instructions)
    ft_lstadd_back(stack, ft_lstnew(ft_strdup("rra")));
  return (0);
}
