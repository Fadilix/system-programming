// #include "table.h"

//
// Fonctions elementaires de manipulation de la table
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
  char *key;
  struct node *left;
  struct node *right;
  int count;
} *Table;

/* Creation d'une table vide */
Table creer_table(void) { return NULL; }

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt) {
  if (!table || !elt)
    return 0;

  if (!*table) {
    *table = malloc(sizeof(struct node));
    (*table)->left = NULL;
    (*table)->right = NULL;
    (*table)->key = strdup(elt);
    (*table)->count = 1;
    return 0;
  }

  struct node *current = *table;

  while (current) {
    int cmp = strcmp(elt, current->key);
    if (cmp < 0) {
      if (current->left) {
        current = current->left;
      } else {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->key = strdup(elt);
        new_node->count = 1;
        new_node->left = new_node->right = NULL;
        current->left = new_node;
        return 1;
      }
    } else if (cmp == 0) {
      return ++current->count;

    } else {
      if (current->right) {
        current = current->right;
      } else {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->key = strdup(elt);
        new_node->count = 1;
        new_node->left = new_node->right = NULL;
        current->right = new_node;
        return 1;
      }
    }
  }
  return 0;
}

void inorder_traversal(struct node *node) {
  if (!node)
    return;
  inorder_traversal(node->left);
  printf("%s (%d)\n", node->key, node->count);
  inorder_traversal(node->right);
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
  if (!table) {
    // empty ttable
    return;
  }
  inorder_traversal(table);
}

typedef void (*t_fonction)(char *);
/* Appel d'une fonction sur chacun des éléments de la table */

void inorder_apply(struct node *node, t_fonction func) {
  if (!node)
    return;
  inorder_apply(node->left, func);
  func(node->key);
  inorder_apply(node->right, func);
}

void appliquer_table(Table table, t_fonction fonction) {
  if (!table)
    return;
  inorder_apply(table, fonction);
}

/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char *elt) {
  if (!table)
    return 0; // empty table

  struct node *current = table;
  while (current) {
    int cmp = strcmp(current->key, elt);
    if (cmp == 0) {
      return current->count;
    } else if (cmp < 0) {
      if (current->left != NULL) {
        current = current->left;
      }
    } else {
      if (current->right != NULL) {
        current = current->right;
      }
    }
  }
  return 0;
}

/* Destruction d'une table */
void detruire_table(Table *table) {}
