#include "../../includes/push_swap.h"


void assert(int tof, const char *msg) {
  if (!tof) 
  {
    ft_printf("Teste %s Falhou!\n", msg);
    return;
  }
  ft_printf("Teste %s Passou!\n", msg);
}


void test_pa(void) {
  t_list list;
  t_list list_b;
  t_list instructions;
  ft_memset(&list, 0, sizeof(list));
  ft_memset(&list_b, 0, sizeof(list));
  ft_memset(&instructions, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));
  int *d = ft_calloc(1, sizeof(int));
  int *e = ft_calloc(1, sizeof(int));
  int *f = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;
  *d = 1; *e = 2; *f = 3;

  t_node *node_a = ft_lstnew(a);
  t_node *node_b = ft_lstnew(b);
  t_node *node_c = ft_lstnew(c);
  t_node *node_d = ft_lstnew(d);
  t_node *node_e = ft_lstnew(e);
  t_node *node_f = ft_lstnew(f);

  ft_lstadd_back(&list, node_a);
  ft_lstadd_back(&list, node_b);
  ft_lstadd_back(&list, node_c);

  ft_lstadd_back(&list_b, node_d);
  ft_lstadd_back(&list_b, node_e);
  ft_lstadd_back(&list_b, node_f);

  assert(list.size == 3, "pa: stack_a  deve ter tamanho igual 3");
  assert(list_b.size == 3, "pa: stack_b deve ter tamanho igual a 3");

  pa(&list, &list_b,  &instructions);
  assert( list.head == node_d, "pa: stack_a head deve ser igual ao ultimo item de stack_b");
  assert(list.size == 4, "pa: stack_a  deve ter tamanho igual 4");
  assert(list_b.size == 2, "pa: stack_b deve ter tamanho igual a 2");
  
  pa(&list, &list_b,  &instructions);
  assert( list.head == node_e, "pa: stack_a head deve ser igual ao ultimo item de stack_b");
  assert(list.size == 5, "pa: stack_a  deve ter tamanho igual 5");
  assert(list_b.size == 1, "pa: stack_b deve ter tamanho igual a 1");
  
  pa(&list, &list_b,  &instructions);
  assert( list.head == node_f, "pa: stack_a head deve ser igual ao ultimo item de stack_b");
  assert(list.size == 6, "pa: stack_a  deve ter tamanho igual 6");
  assert(list_b.size == 0, "pa: stack_b deve ter tamanho igual a 0");
  int r = pa(&list, &list_b,  &instructions);
  assert( list.head == node_f, "pa: stack_a head deve ser igual ao ultimo item de stack_b");
  assert( r == 0, "pa: stack_a deve continuar com o mesmo head");
  assert(instructions.size == 3, "pa: instructions deve ter o tamanho igual a 3");
  ft_lstclear(&list, NULL);
  ft_lstclear(&list_b, NULL);
  ft_lstclear(&instructions, NULL);
}

void test_pb(void) {
  t_list list;
  t_list list_b;
  t_list instructions;
  ft_memset(&list, 0, sizeof(list));
  ft_memset(&list_b, 0, sizeof(list));
  ft_memset(&instructions, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));
  int *d = ft_calloc(1, sizeof(int));
  int *e = ft_calloc(1, sizeof(int));
  int *f = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;
  *d = 1; *e = 2; *f = 3;

  t_node *node_a = ft_lstnew(a);
  t_node *node_b = ft_lstnew(b);
  t_node *node_c = ft_lstnew(c);
  t_node *node_d = ft_lstnew(d);
  t_node *node_e = ft_lstnew(e);
  t_node *node_f = ft_lstnew(f);

  ft_lstadd_back(&list, node_a);
  ft_lstadd_back(&list, node_b);
  ft_lstadd_back(&list, node_c);

  ft_lstadd_back(&list_b, node_d);
  ft_lstadd_back(&list_b, node_e);
  ft_lstadd_back(&list_b, node_f);

  assert(list.size == 3, "pb: stack_a  deve ter tamanho igual 3");
  assert(list_b.size == 3, "pb: stack_b deve ter tamanho igual a 3");

  pb(&list_b, &list,  &instructions);
  assert( list_b.head == node_a, "pb: stack_b head deve ser igual ao ultimo item de stack_a");
  assert(list_b.size == 4, "pb: stack_b  deve ter tamanho igual 4");
  assert(list.size == 2, "pb: stack_a deve ter tamanho igual a 2");
  
  pb(&list_b, &list,  &instructions);
  assert( list_b.head == node_b, "pb: stack_b head deve ser igual ao ultimo item de stack_a");
  assert(list_b.size == 5, "pb: stack_b  deve ter tamanho igual 5");
  assert(list.size == 1, "pb: stack_a deve ter tamanho igual a 1");
  
  pb(&list_b, &list,  &instructions);
  assert( list_b.head == node_c, "pb: stack_b head deve ser igual ao ultimo item de stack_a");
  assert(list_b.size == 6, "pb: stack_b  deve ter tamanho igual 6");
  assert(list.size == 0, "pb: stack_a deve ter tamanho igual a 0");
  int r = pb(&list_b, &list,  &instructions);
  assert( list_b.head == node_c, "pb: stack_b head deve ser igual ao ultimo item de stack_a");
  assert( r == 0, "pb: stack_b deve continuar com o mesmo head");
  assert(instructions.size == 3, "pb: instructions deve ter o tamanho igual a 3");
  ft_lstclear(&list, NULL);
  ft_lstclear(&list_b, NULL);
  ft_lstclear(&instructions, NULL);
}

void test_rb(void) {
  t_list list;
  t_list instructions;
  ft_memset(&list, 0, sizeof(list));
  ft_memset(&instructions, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;

  t_node *node_a = ft_lstnew(a);
  t_node *node_b = ft_lstnew(b);
  t_node *node_c = ft_lstnew(c);
  
  assert( rb(&list, &instructions) == 0, "rb: não deve fazer nada");
  assert( instructions.size == 0, "rb: não adicionar nenhuma instrução");

  ft_lstadd_back(&list, node_a);
  ft_lstadd_back(&list, node_b);
  ft_lstadd_back(&list, node_c);

  rb(&list, &instructions);
  assert( list.tail == node_a, "rb: tail deve ser igual ao node_a");
  assert( list.head == node_b, "rb: head deve ser igual ao node_b");
  rb(&list, &instructions);
  assert( list.tail == node_b, "rb: tail deve ser igual ao node_b");
  assert( list.head == node_c, "rb: head deve ser igual ao node_c");
  rb(&list, &instructions);
  assert( list.tail == node_c, "rb: tail deve ser igual ao node_c");
  assert( list.head == node_a, "rb: head deve ser igual ao node_a");
  assert( instructions.size == 3, "rb: não ter 3 intruções");

  ft_lstclear(&list, NULL);
  ft_lstclear(&instructions, NULL);
}

void display(t_list *list) {
  for (t_node *node = list->head; node != NULL; node = node->next) {
    ft_printf("%d ", *(int *) node->content);
  }
  ft_putchar_fd('\n', 1);
}


void test_rra(void) {
  t_list list;
  t_list instructions;
  ft_memset(&list, 0, sizeof(t_list));
  ft_memset(&instructions, 0, sizeof(t_list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;
  
  assert( rb(&list, &instructions) == 0, "rra: não deve fazer nada");
  assert( instructions.size == 0, "rra: não adicionar nenhuma instrução");

  t_node *node_a = ft_lstnew(a);
  t_node *node_b = ft_lstnew(b);
  t_node *node_c = ft_lstnew(c);

  ft_lstadd_back(&list, node_a);
  ft_lstadd_back(&list, node_b);
  ft_lstadd_back(&list, node_c);

  rra(&list, &instructions);
  assert( list.tail == node_b, "rra: ultimo elemento deve ser o node_b");
  assert( list.head == node_c, "rra: primeiro elemento deve ser  o node_c");
  rra(&list, &instructions);
  assert( list.tail == node_a, "rra: ultimo elemento deve ser  o node_a");
  assert( list.head == node_b, "rra: primeiro elemento deve ser o node_b");
  rra(&list, &instructions);
  assert( list.tail == node_c, "rra: ultimo elemento deve ser  o node_c");
  assert( list.head == node_a, "rra: primeiro elemento deve ser o node_a");
  assert( instructions.size == 3, "rra: instructions deve ter tamanho igual a 3");

  ft_lstclear(&list, NULL);
  ft_lstclear(&instructions, NULL);
}


void test_sa(void) {
  t_list list;
  t_list instructions;
  ft_memset(&list, 0, sizeof(list));
  ft_memset(&instructions, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;
  
  assert(sa(&list, &instructions) == 0, "sa: quando nao há nenhum elemento nao se deve fazer nada");

  t_node *node_a = ft_lstnew(a);
  t_node *node_b = ft_lstnew(b);
  t_node *node_c = ft_lstnew(c);

  ft_lstadd_back(&list, node_a);
  assert(sa(&list, &instructions) == 0, "sa: quando se têm um elemento nao se deve fazer nada");
  ft_lstadd_back(&list, node_b);
  ft_lstadd_back(&list, node_c);
  
  assert(list.size == 3, "sa: size deve ser igual a 3");
  sa(&list, &instructions);
  assert(list.head == node_b, "sa: head deve ser igual ao ultimo item");
  sa(&list, &instructions);
  assert(list.head == node_a, "sa: head deve ser igual ao primeiro item");
  assert(instructions.size == 2, "pb: instructions deve ter o tamanho igual a 2");
  

  ft_lstclear(&list, NULL);
  ft_lstclear(&instructions, NULL);

}

void test_sb(void) {
  t_list list;
  t_list instructions;
  ft_memset(&list, 0, sizeof(list));
  ft_memset(&instructions, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;
  
  assert(sb(&list, &instructions) == 0, "sb: quando nao há nenhum elemento nao se deve fazer nada");

  t_node *node_a = ft_lstnew(a);
  t_node *node_b = ft_lstnew(b);
  t_node *node_c = ft_lstnew(c);

  ft_lstadd_back(&list, node_a);
  assert(sb(&list, &instructions) == 0, "sb: quando se têm um elemento nao se deve fazer nada");
  ft_lstadd_back(&list, node_b);
  ft_lstadd_back(&list, node_c);
  
  assert(list.size == 3, "sb: size deve ser igual a 3");
  sb(&list, &instructions);
  assert(list.head == node_b, "sb: head deve ser igual ao ultimo item");
  sb(&list, &instructions);
  assert(list.head == node_a, "sb: head deve ser igual ao primeiro item");
  assert(instructions.size == 2, "pb: instructions deve ter o tamanho igual a 2");

  ft_lstclear(&list, NULL);
  ft_lstclear(&instructions, NULL);

}
int main(void) {
  test_pa();
  ft_printf("\n\n");
  test_pb();
  ft_printf("\n\n");
  test_sa();
  ft_printf("\n\n");
  test_sb();
 // test_ra();
  ft_printf("\n\n");
  test_rb();
  ft_printf("\n\n");
  test_rra();
  
}
