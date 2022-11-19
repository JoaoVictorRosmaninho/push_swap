#include "../../includes/push_swap.h"


/* c is the context strucuture  */
int ra(t_list *stack, t_list *instructions) {

  if (!stack)
    return (-1);

  stack->tail->next = stack->head;
  stack->head->prev = stack->tail;
  stack->tail = stack->head;
  stack->head->next->prev = NULL;
  stack->head = stack->head->next;
  stack->tail->next = NULL;

  if (instructions)  
    ft_lstadd_back(instructions, ft_lstnew(ft_strdup("ra")));
  return(0);
}
