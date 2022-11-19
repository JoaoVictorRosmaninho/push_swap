#include "../../includes/push_swap.h"


/* c is the context strucuture  */
int ra(t_list *stack, t_list *instructions) {
  t_node *node;

  if (!stack)
    return (-1);
  /* penultimo aponta pro novo ultimo  */
  stack->tail->prev->next = stack->head;
  /* ultimo tem seu prev ajustado   */
  stack->head->prev = stack->tail->prev;
  /* primeiro tem seu next ajustado pro segundo   */
  stack->tail->next = stack->head->next;
  /*  ultimo tem seu proximo apontado pra NULL */
  stack->head->next = NULL;
  /*  primeiro tem o prev ajustado pra NULL */
  stack->tail->prev = NULL;

  /*  swap  */
  node = stack->head; 
  stack->head = stack->tail; 
  stack->tail = node;

  if (instructions)  
    ft_lstadd_back(instructions, ft_lstnew(ft_strdup("ra")));
  return(0);
}
