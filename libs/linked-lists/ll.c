#include "ll.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Create a ll with a defined number of elements
 * and as many elements as we want using the #include<strdarg.h>
 * library
 */
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

/*
 * Display the ll in a arrow pointer type format
 */
void print_ll(Node *head) {
  while (head != NULL) {
    printf("%d", head->value);
    if (head->next)
      printf(" -> ");
    head = head->next;
  }
  printf("\n");
}

/*
 * Here i noticed that we are using ** because when
 * using * it takes it as a copy of the original pointer
 * so the modification of the list only happens in the local pointer
 * By using ** we are pointing to the pointer of the original Node
 * It is a little bit confusing now but i'll get the hang of it
 */
void list_push_front(Node **head, int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = *head;
  *head = new_node;
}

/*
 * Add element to the end of the linked list
 */
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

/*
 * Remove the first element of the linked list
 */
void list_pop_front(Node **head) {
  if (*head == NULL)
    return;
  Node *tmp = *head;
  *head = (*head)->next;
  free(tmp);
}

/*
 * cycle through the linked list
 * and increment the count till head->next == NULL
 */
size_t list_size(Node *head) {
  size_t count = 0;
  while (head) {
    count++;
    head = head->next;
  }
  return count;
}

/*
 * delete a node from a linked list
 */
void list_delete(Node **head, int value) {
  if (*head == NULL)
    return;

  // case 1: when the head is the element
  // we want to delete
  while (*head != NULL && (*head)->value == value) {
    Node *tmp = *head;
    (*head)->next = tmp->next;
    free(tmp);
  }

  // case 2: delete element we want to delete is after the head
  Node *current = *head;
  while (current != NULL && current->next != NULL) {
    if (current->next->value == value) {
      Node *tmp = current->next;
      current->next = tmp->next;
      free(tmp);
    } else {
      current = current->next;
    }
  }
}
