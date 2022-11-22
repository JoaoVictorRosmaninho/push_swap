#include "../includes/push_swap.h"
#include <stdio.h>


static void init_stack(t_list *stack, char **input) {
  int  *ptr_i, i;

  ptr_i = NULL;
  i = 0;
  while (input[i]) { 
    ptr_i = (int *) ft_calloc(1, sizeof(int));
    *ptr_i = ft_atoi(input[i]);
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



int main(int argc, char *argv[]) {
  if (argc < 2)
    exit(0);

  t_list stack_a;
  t_list stack_b;
  t_list instructions; 
  char **input = NULL;
  int op = 0;

  input = ft_split(argv[1], ' ');

  ft_memset(&stack_a, 0, sizeof(t_list));
  ft_memset(&stack_b, 0, sizeof(t_list));
  ft_memset(&instructions, 0, sizeof(t_list));

  init_stack(&stack_a, input);


  while (op != -1) {
      display(&stack_a, &stack_b);
      scanf("%d", &op);
      switch(op) {
        case 1:
          sa(&stack_a, &instructions);
        break;
        case 2:
          sa(&stack_b, &instructions);
        break;
        case 3:
  
  clear(input);
  ft_lstclear(&stack_a, NULL);
  ft_lstclear(&stack_b, NULL);
  ft_lstclear(&instructions, NULL);
}
