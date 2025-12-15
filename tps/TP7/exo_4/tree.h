#ifndef _TREE_H
#define _TREE_H

struct node {
  int value;
  struct node *left;
  struct node *right;
};

typedef struct node *tree;

tree create_empty_tree(void);
tree add_tree(tree t, int v);
void print_tree(tree t);

#endif // !_TREE_H
