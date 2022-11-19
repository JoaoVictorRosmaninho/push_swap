#include "../../includes/push_swap.h"

int pa(t_list *s1, t_list *s2, t_list *instructions) {
    if ( !s2 || !s2->head)
      return (0);
    if (instructions)
      ft_lstadd_back(instructions, ft_lstnew(ft_strdup("pa")));
    ft_lstadd_front(s1, ft_lstpop_head(s2));
    return (1);
}
