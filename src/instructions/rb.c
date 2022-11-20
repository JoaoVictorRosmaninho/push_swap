#include "../../includes/push_swap.h"


int rb(t_list *stack, t_list *instructions) {

  if(ra(stack, NULL)) {
    if (instructions)
      ft_lstadd_back(instructions, ft_lstnew(ft_strdup("rb")));
    return (1);
  }
  return (0);
}
