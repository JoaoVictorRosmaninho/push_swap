#include "../../includes/push_swap.h"



int rrr(t_list *s1, t_list *s2, t_list *instructions) {
  if (!stack)
    return (-1);
  ft_lstadd_back(instructions, ft_lstnew(ft_strdup("rrr")));
  return (rra(s1, NULL) && rrb(s2, NULL));
}
