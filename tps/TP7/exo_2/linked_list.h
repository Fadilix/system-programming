#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct list {
  int value;
  struct list *next;
} *List;

List prepend_element(List lst, int v);
List append_element(List lst, int v);
List delete_element(List lst, int v);
List delete_elements(List lst, int v);
void print_list(List lst);

#endif
