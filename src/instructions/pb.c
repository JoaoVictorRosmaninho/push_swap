#include "../../includes/push_swap.h"

int pb(s_ctx *context) {
    if (!context->stack_b->head)
      return -1;
    ft_lstadd_front(context->stack_b, ft_lstpop_head(context->stack_a));
    return 0;
}
