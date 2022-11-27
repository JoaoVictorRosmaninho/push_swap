#include "../includes/push_swap.h"
#include <stdio.h>


static void init_stack(t_list *stack, char **argv, int argc) {
  int  i;
  int *ptr_i;

  i = 0;
  ptr_i = NULL;
  while (i < argc) { 
    ptr_i = (int *) ft_calloc(1, sizeof(int));
    *ptr_i = ft_atoi(argv[i]);
    ft_lstadd_front(stack, ft_lstnew(ptr_i));
    i++;
  }
}


void display(t_list *s1, t_list *s2) {
  t_node *A, *B;

  A = s1->head;
  B = s2->head;

  ft_printf("A B\n");

  while (A || B) {
    if (A) {
      ft_printf("%d ", *(int *) A->content);
      A = A->next;
    }
    if (B) {
      ft_printf("%d", *(int *) B->content);
      B = B->next;
    }
    ft_putchar_fd('\n', 1);
  }
}

void clear(char **input) {
  int i = 0;

  while (input[i]) {
    free(input[i]);
    i++;
  }
  free(input);
}



void order(t_list *stack_a, t_list *stack_b, t_list *instructions) {
  (void)stack_b;
  if (stack_a->size == 3) {
    order_three(stack_a, instructions);
  } else if (stack_a->size == 4) {
    order_four(stack_a, stack_b, instructions);
  } else if (stack_a->size == 5) {
    order_five(stack_a, stack_b, instructions);
  } else {  
    merge_sort(stack_a, stack_b, instructions);
  }
}


int main(int argc, char *argv[]) {
  if (argc < 2)
    exit(0);

  t_list stack_a;
  t_list stack_b;
  t_list instructions; 

  ft_memset(&stack_a, 0, sizeof(t_list));
  ft_memset(&stack_b, 0, sizeof(t_list));
  ft_memset(&instructions, 0, sizeof(t_list));

  init_stack(&stack_a, argv, argc);
  
  order(&stack_a, &stack_b, &instructions);

  for (t_node *tmp = instructions.head; tmp; tmp = tmp->next) {
    ft_printf("%s\n", (char *) tmp->content);
  }

  ft_lstclear(&stack_a, NULL);
  ft_lstclear(&stack_b, NULL);
  ft_lstclear(&instructions, NULL);
}
