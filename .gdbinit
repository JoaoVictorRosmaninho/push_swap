define plist
  set var $n = $arg0->head
  while $n
    printf "%d ", *(int *) $n->content
    set var $n = $n->next
  end
end


define pnode
  set var $n = $arg0
  while $n
    printf "%d ", *(int *) $n->content
    set var $n = $n->next
  end
end
