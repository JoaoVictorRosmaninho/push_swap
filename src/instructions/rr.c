#include "../../includes/push_swap.h"


int rr(t_list *s1, t_list *s2, t_list *instructions) {
    if ( !s1 || !s2 || !instructions)
      return (-1);

    ft_lstadd_back(instructions, ft_lstnew(ft_strdup("rr")));
    return (ra(s1, NULL) && rb(s2, NULL));
}
