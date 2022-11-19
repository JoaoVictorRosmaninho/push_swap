#include "../../includes/push_swap.h"


int rrb(t_list *stack, t_list *instructions) {
  t_node *node;

  if ( !stack )
    return (-1);
  
  if (instructions)
    ft_lstadd_back(stack, ft_lstnew(ft_strdup("rrb")));
  return (rra(stack, NULL));
}
