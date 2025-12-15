// #include "tree.h"
// #include <assert.h>
// #include <stdlib.h>
//
// tree create_empty_tree(void) {
//   tree *t = malloc(sizeof(tree));
//   return *t;
// }
//
// tree add_tree(tree t, int v) {
//   tree ptr = t;
//
//   if (&t == NULL) {
//     t.value = v;
//     t.left = NULL;
//     t.right = NULL;
//   }
//
//   while (t.left != NULL && t.right != NULL) {
//     if (t.left->value < v) {
//       t = *t.left;
//     }
//     if (t.right->value < v) {
//       t = *t.right;
//     }
//   }
//   if (t.left == NULL) {
//     t.left->value = v;
//     t.left->left = NULL;
//     t.right->right = NULL;
//   }
//
//   return ptr;
// }
//
// void print_tree(tree t) {
//   while (t && (t.left || t.right) {
//
//   }
// }
