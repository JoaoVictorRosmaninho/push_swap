#include "../../includes/push_swap.h"


int rb(t_list *stack, t_list *instructions) {

  if ( !stack )
    return (-1);
  if (instructions)
    ft_lstadd_back(instructions, ft_lstnew(ft_strdup("rb")));
  return ra(stack, NULL);
}
