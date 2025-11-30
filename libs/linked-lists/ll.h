#include <stdarg.h>
#include <stdlib.h>

#ifndef LL_H
#define LL_H

/*
 * base recursive structure for a node
 */
typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *list_create(int count, ...);
void print_ll(Node *head);
void list_push_front(Node **head, int value);
void list_push_back(Node **head, int value);
void list_pop_front(Node **head);
size_t list_size(Node *head);
void list_delete(Node **head, int value);
void list_free(Node **head);

#endif
