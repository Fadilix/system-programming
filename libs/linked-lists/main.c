#include "ll.h"
#include <stdio.h>

int main() {

  Node *current = list_create(4, 2, 3, 4, 7);

  print_ll(current);

  list_push_front(&current, 6);

  print_ll(current);

  list_push_back(current, 9);

  print_ll(current);

  list_pop_front(&current);

  print_ll(current);

  size_t ll_size = list_size(current);
  printf("%zu\n", ll_size);

  list_delete(&current, 4);

  print_ll(current);

  // list_delete(&current, 4);
  //
  // print_ll(current);

  return 1;
}
