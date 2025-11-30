#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *current = list_create(4, 2, 3, 4, 7);

  print_ll(current);

  list_push_front(&current, 6);

  print_ll(current);

  list_push_back(current, 9);

  print_ll(current);

  return 1;
}
