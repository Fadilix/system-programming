#ifndef _STACK_H_
#define _STACK_H_

struct node {
  int value;
  struct node *next;
};

typedef struct node Node;

void push_item(Node **head, int value);
void pop_item(Node **head);
int top_value(Node *head);
void print_stack(Node *head);

#endif
