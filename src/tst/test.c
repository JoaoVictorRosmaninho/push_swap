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
  ft_memset(&list, 0, sizeof(list));
  ft_memset(&list_b, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));

  int *d = ft_calloc(1, sizeof(int));
  int *e = ft_calloc(1, sizeof(int));
  int *f = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;
  *d = 4; *e = 5; *f = 6;

  ft_lstadd_front(&list, ft_lstnew(a));
  ft_lstadd_front(&list, ft_lstnew(b));
  ft_lstadd_front(&list, ft_lstnew(c));

  ft_lstadd_front(&list_b, ft_lstnew(d));
  ft_lstadd_front(&list_b, ft_lstnew(e));
  ft_lstadd_front(&list_b, ft_lstnew(f));
  s_ctx context; 

  context.stack_a = &list;
  context.stack_b = &list_b;
  pa(&context);
  assert( *((int *)(list.head->content)) == *f, "pa");
  pa(&context);
  assert( *((int *)(list.head->content)) == *e, "pa");

  ft_lstclear(&list, NULL);
  ft_lstclear(&list_b, NULL);
}

void test_pb(void) {
  t_list list;
  t_list list_b;
  ft_memset(&list, 0, sizeof(list));
  ft_memset(&list_b, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));

  int *d = ft_calloc(1, sizeof(int));
  int *e = ft_calloc(1, sizeof(int));
  int *f = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;
  *d = 4; *e = 5; *f = 6;

  ft_lstadd_front(&list, ft_lstnew(a));
  ft_lstadd_front(&list, ft_lstnew(b));
  ft_lstadd_front(&list, ft_lstnew(c));

  ft_lstadd_front(&list_b, ft_lstnew(d));
  ft_lstadd_front(&list_b, ft_lstnew(e));
  ft_lstadd_front(&list_b, ft_lstnew(f));
  s_ctx context; 

  context.stack_a = &list;
  context.stack_b = &list_b;
  pb(&context);
  assert( *((int *)(list_b.head->content)) == *c, "pb");
  pb(&context);
  assert( *((int *)(list_b.head->content)) == *b, "pb");

  ft_lstclear(&list, NULL);
  ft_lstclear(&list_b, NULL);
}


void test_ra(void) {
  t_list list;
  ft_memset(&list, 0, sizeof(list));

  int *a = ft_calloc(1, sizeof(int));
  int *b = ft_calloc(1, sizeof(int));
  int *c = ft_calloc(1, sizeof(int));

  *a = 1; *b = 2; *c = 3;

  t_node *node_a = ft_lstnew(a);
  t_node *node_b = ft_lstnew(b);
  t_node *node_c = ft_lstnew(c);

  ft_lstadd_back(&list, node_a);
  ft_lstadd_back(&list, node_b);
  ft_lstadd_back(&list, node_c);

  s_ctx context; 

  context.stack_a = &list;
  ra(&context);
  assert( list.tail == node_a, "pr");
  assert( list.head == node_c, "pr");
  ra(&context);
  assert( list.tail == node_c, "pr");
  assert( list.head == node_a, "pr");

  ft_lstclear(&list, NULL);
}

int main(void) {
  test_pa();
  test_pb();
  test_ra();
  
}
