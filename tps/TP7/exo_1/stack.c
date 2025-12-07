#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push_item(Node **head, int value) {
  Node *temp = malloc(sizeof(Node));
  temp->value = value;
  temp->next = *head;
  *head = temp;
}

void print_stack(Node *head) {
  printf("___\n");
  while (head != NULL) {
    printf("|%d|\n", head->value);
    if (head->next != NULL) {
      printf("___\n");
    }
    head = head->next;
  }
  printf("___\n\n");
}

int is_empty(Node *head) {
  if (head == NULL) {
    return 1;
  }
  return 0;
}

void pop_item(Node **head) {
  // assert(*head != NULL);

  Node *tmp = *head;
  *head = (*head)->next;
  free(tmp);
}

int top_value(Node *head) {
  if (head != NULL)
    return head->value;
  return -1;
}
