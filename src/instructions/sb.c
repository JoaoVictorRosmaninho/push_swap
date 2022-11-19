#include "../../includes/push_swap.h"

int sb(t_list *s1, t_list *instructions) {
  if (!s1 || !s1->head || (s1->size == 1))
    return (0);

  if (instructions)
    ft_lstadd_back(instructions, ft_lstnew(ft_strdup("sb")));
  return (sa(s1, NULL));
}
