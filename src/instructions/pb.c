#include "../../includes/push_swap.h"

int pb(t_list *s1, t_list *s2, t_list *instructions) {
    if (pa(s2, s1, NULL)) 
    {
      if (instructions)
        ft_lstadd_back(instructions, ft_lstnew(ft_strdup("pb")));
      return (1);
    }
    return (0);
}
