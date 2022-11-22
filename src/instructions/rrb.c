#include "../../includes/push_swap.h"


int rrb(t_list *s1, t_list *instructions) {

  if (rra(s1, NULL)) {
    if (instructions)
      ft_lstadd_back(instructions, ft_lstnew(ft_strdup("rrb")));
    return (1);
  }
  return (0);
}
