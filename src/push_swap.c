#include "../includes/push_swap.h"

static void clear_context(s_ctx *context) {
  ft_lstclear(context->stack_a, NULL);
  ft_lstclear(context->stack_b, NULL);
  ft_lstclear(context->instructions, NULL);


  free(context->stack_a);
  free(context->stack_b);
  free(context->instructions);
}

static void init_stack(t_list *stack, int argc, char *argv[]) {
  int *ptr_i;
  int  i;

  ptr_i = NULL; 
  i = 1;
  while (i < argc) {
    ptr_i = (int *) ft_calloc(1, sizeof(int));
    *ptr_i = ft_atoi(argv[i]);
    ft_lstadd_front(stack, ft_lstnew(ptr_i));
    i++;
  }
}

void init_context(s_ctx *context) {
  context->stack_a      =  (t_list *) ft_calloc(1, sizeof(t_list));
  context->stack_b      =  (t_list *) ft_calloc(1, sizeof(t_list));
  context->instructions =  (t_list *) ft_calloc(1, sizeof(t_list));
} 

void display(s_ctx *context) {
  for (t_node *aux = context->stack_a->head ; aux != NULL; aux = aux->next) {
    ft_printf("%d ", *(int *) aux->content);
  }
  ft_putchar_fd('\n', 1);
}


void display_reverse(s_ctx *context) {
  for (t_node *aux = context->stack_a->tail ; aux != NULL; aux = aux->prev) {
    ft_printf("%d ", *(int *) aux->content);
  }
  ft_putchar_fd('\n', 1);
}

int main(int argc, char *argv[]) {
  s_ctx context; 

  init_context(&context);

  init_stack(context.stack_a, argc, argv);
  
  display(&context);

  sa(&context);

  display(&context);

  ft_printf("size: %d\n", context.stack_a->size);

  ft_printf("printando ao contrario:\n");
  
  display_reverse(&context);


  clear_context(&context);
}
