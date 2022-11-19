#include "../../includes/push_swap.h"


/* c is the context strucuture  */
int ra(s_ctx *c) {
  t_node *node;

  if (!c || !c->stack_a)
    return (-1);
  /* penultimo aponta pro novo ultimo  */
  c->stack_a->tail->prev->next = c->stack_a->head;
  /* ultimo tem seu prev ajustado   */
  c->stack_a->head->prev = c->stack_a->tail->prev;
  /* primeiro tem seu next ajustado pro segundo   */
  c->stack_a->tail->next = c->stack_a->head->next;
  /*  ultimo tem seu proximo apontado pra NULL */
  c->stack_a->head->next = NULL;
  /*  primeiro tem o prev ajustado pra NULL */
  c->stack_a->tail->prev = NULL;

  /*  swap  */
  node = c->stack_a->head; 
  c->stack_a->head = c->stack_a->tail; 
  c->stack_a->tail = node;

  return(0);
}
