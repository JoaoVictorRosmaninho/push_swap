#include "../../includes/push_swap.h"

int sa(t_list *s1, t_list *instructions) {
  t_node *node_a;
  t_node *node_b;
  t_node *node_c;

  if (!s1 || !s1->head || (s1->size == 1))
    return (0);

  node_a = s1->head; // primeiro
  node_b = node_a->next;   //segundo
  node_c = node_b->next;  //terceiro 
                        
  node_c->prev = node_a; 
  node_a->next = node_c; // primeiro apontando pro terceiro

  node_a->prev = node_b;
  node_b->next = node_a; 
  
  node_b->prev = NULL;
  s1->head = node_b; // novo primeiro
  
  if (instructions)
    ft_lstadd_back(instructions, ft_lstnew(ft_strdup("sa")));
  return(1);
}
