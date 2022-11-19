#include "../../includes/push_swap.h"

int pa(s_ctx *context) {
    if (!context->stack_b->head)
      return -1;
    ft_lstadd_front(context->stack_a, ft_lstpop_head(context->stack_b));
    return 0;
}
