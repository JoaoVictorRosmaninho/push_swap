#include "../../includes/push_swap.h"



int rrr(t_list *s1, t_list *s2, t_list *instructions) {
   if (rra(s1, NULL) && rrb(s2, NULL)) {
      ft_lstadd_back(instructions, ft_lstnew(ft_strdup("rrr")));
      return (1);
   }
   return (0);
}
