#include "../../includes/push_swap.h"

int ss(t_list *s1, t_list *s2, t_list *instructions) {
  if (sa(s1, NULL) && sb(s2, NULL)) {
    ft_lstadd_back(instructions, ft_lstnew(ft_strdup("ss")));
    return (0);
  }
  return (-1);
}
