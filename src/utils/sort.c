#include "../../includes/push_swap.h"


static unsigned char get_lower_value(t_list *lst, int *value) {
  unsigned int pos_i;
  unsigned int pos_j;
  t_node *head;

  *value = *(int *) lst->head->content;
  head  = lst->head->next;
  pos_i = 0;
  pos_j = 0;
  while(head) {
    if (*(int * ) head->content < *value)
    {
      *value = *(int *) head->content ;
      pos_i = pos_j;
    }
    head = head->next;
    pos_j++;
  }

  return (pos_i >= (lst->size / 2));
}

void order_three(t_list *s1, t_list *instructions) {

  int a = *(int *) s1->head->content;
  int b = *(int *) s1->head->next->content;
  int c = *(int *) s1->head->next->next->content;

  if (a > b && b > c) {
    sa(s1, instructions);
    rra(s1, instructions);
  }
  else if (a > b && a < c &&  b < c) 
    sa(s1, instructions);
  else if (a < b && a > c && b > c) 
    rra(s1, instructions);
  else if (a > b && a > c && b < c) 
    ra(s1, instructions);
  else if (a < b&& a > c && b < c) 
    rra(s1, instructions);
  else if (a < b && b > c && c > a) 
  {
    sa(s1, instructions);
    ra(s1, instructions);
  }
}


static int push_n_to_pb(t_list *s1, t_list *s2, t_list *instructions) {
  int lower_value;

  if (get_lower_value(s1, &lower_value)) {
    while ( *(int *) s1->head->content != lower_value )
      rra(s1, instructions);
  } else {
    while ( *(int *) s1->head->content != lower_value )
      ra(s1, instructions);
  }
  return pb(s1, s2, instructions);
}


void order_four(t_list *s1, t_list *s2, t_list *instructions) {
  push_n_to_pb(s1, s2, instructions);
  order_three(s1, instructions);
  pa(s1, s2, instructions);
}


void order_five(t_list *s1, t_list *s2, t_list *instructions) {
  push_n_to_pb(s1, s2, instructions);
  push_n_to_pb(s1, s2, instructions);
  order_three(s1, instructions);
  pa(s1, s2, instructions);
  pa(s1, s2, instructions);
}

void split_list( t_list *a, t_list *b, t_list *stack) {
  t_node *head;
  t_node *tail;

  head = stack->head;
  tail = head->next;

  while (tail) {
    tail = tail->next;
    if (tail) {
      head = head->next;
      tail = tail->next;
    }
  }
  a->head = stack->head;
  a->tail = head;
  b->head = head->next;
  b->tail = stack->tail;
  a->tail->next = NULL;
  b->size = ft_lstsize(b);
  a->size = ft_lstsize(a); 
}


t_node *merge(t_node *a, t_node *b) {
  t_node *result;

  result = NULL;

  if (!a)
    return (b);
  if (!b)
    return (a);

  int ac = *(int *) a->content;
  int bc = *(int *) b->content;
  if (ac <= bc) {
    result = a;
    result->next = merge(a->next, b);
    result->next->prev = result;
  } else {
    result = b;
    result->next = merge(a, b->next);
    result->next->prev = result;
  }

  return (result);

}

void merge_sort(t_list *s1, t_list *s2, t_list *instructions) {
    t_list a;
    t_list b;

    if (s1->size <= 5) {
        if (s1->size == 5)
          order_five(s1, s2, instructions);
        else if (s1->size == 4)
          order_four(s1, s2, instructions);
        else if (s1->size == 3)
          order_three(s1, instructions);
        
        return;
    }
    split_list(&a, &b, s1);

    merge_sort(&a, s2, instructions);
    merge_sort(&b, s2, instructions);

    s1->head = merge(a.head, b.head);
}


