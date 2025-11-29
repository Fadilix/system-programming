#include "ll.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *current = malloc(sizeof(Node));
  current = list_create(4, 2, 3, 4, 7);

  // printf("Hello world!!!");

  print_ll(current);
  free(current);
  return 0;
}
