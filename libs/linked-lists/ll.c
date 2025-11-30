#include "ll.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

Node *list_create(int count, ...) {
  va_list ap;
  va_start(ap, count);

  int value = va_arg(ap, int);
  Node *current = malloc(sizeof(Node));
  current->value = value;
  current->next = NULL;

  Node *ptr;
  ptr = current;

  for (int i = 1; i < count; i++) {
    Node *next = malloc(sizeof(Node));
    int value = va_arg(ap, int);

    next->value = value;
    current->next = next;
    current = next;
  }

  va_end(ap);
  return ptr;
}

void print_ll(Node *head) {
  while (head != NULL) {
    printf("%d", head->value);
    if (head->next)
      printf(" -> ");
    head = head->next;
  }
  printf("\n");
}

void list_push_front(Node **head, int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = *head;
  *head = new_node;
}

void list_push_back(Node *head, int value) {
  if (head == NULL)
    return;

  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;

  Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

void list_pop_front(Node **head) {
  if (*head == NULL)
    return;
  Node *tmp = *head;
  *head = (*head)->next;
  free(tmp);
}

size_t list_size(Node *head) {
  size_t count = 0;
  while (head) {
    count++;
    head = head->next;
  }
  return count;
}
