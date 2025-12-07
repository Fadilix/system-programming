#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *head = malloc(sizeof(Node));

  push_item(&head, 2);
  push_item(&head, 2);

  print_stack(head);

  pop_item(&head);

  print_stack(head);

  printf("The top value is %d", top_value(head));
}
