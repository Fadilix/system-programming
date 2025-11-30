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
 * We use a `Node **head` because in C, function arguments are passed by value.
 * If we use only `Node *head`, then `head` inside the function is just a copy
 * of the original pointer, so changing it does NOT change the actual list head.
 *
 * By using `Node **head`, we pass the address of the pointer. This allows the
 * function to modify the original head pointer itself (for example when
 * deleting or inserting at the front of the list).
 *
 * It's a second level of indirection and it looks confusing at first, but it
 * becomes natural once you understand that we need a pointer-to-pointer
 * whenever we want to change the caller’s pointer.
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
