#include "../../includes/push_swap.h"

int sb(t_list *s1, t_list *instructions) {

  if (sa(s1, NULL)) {
    if (instructions)
      ft_lstadd_back(instructions, ft_lstnew(ft_strdup("sb")));
    return (1);
  }
  return (0);
}
