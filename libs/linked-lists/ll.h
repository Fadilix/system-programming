#include <stdarg.h>

#ifndef LL_H
#define LL_H

typedef struct Node {
  int value;
  struct Node *next;
} Node;

Node *list_create(int count, ...);
void print_ll(Node *head);
void list_push_front(Node **head, int value);

#endif
