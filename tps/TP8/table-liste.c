#include "table.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Fonctions elementaires de manipulation de la table
//

/* Creation d'une table vide */
Table creer_table(void) { return NULL; }

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt) {
  if (!table)
    return 0;

  struct node *prev = malloc(sizeof(struct node));
  prev = NULL;
  struct node *current = *table;

  while (current != NULL && strcmp(current->elt, elt) <= 0) {
    if (strcmp(current->elt, elt) == 0) {
      return current->count++;
    }
    prev = current;
    current = current->next;
  }

  struct node *new_node = malloc(sizeof(struct node));
  new_node->elt = strdup(elt);
  new_node->count = 1;
  new_node->next = current;

  if (prev == NULL) {
    *table = new_node; // Insertion en tête
  } else {
    prev->next = new_node; // Insertion ailleurs
  }

  return 1;
}

/* Impression triée des éléments de la table */
void imprimer_table(Table table) {
  if (!table)
    return;

  struct node *current = table;

  while (current != NULL) {
    printf("%s", current->elt);
    if (current->next != NULL) {
      printf(" -> ");
    }
    current = current->next;
  }
}
//
// /* Appel d'une fonction sur chacun des éléments de la table */
// void appliquer_table(Table table, t_fonction fonction) {}
//
// /* Recherche du nombre d'occurrences d'un élément */
// int rechercher_table(Table table, char *elt) {}
//
// /* Destruction d'une table */
// void detruire_table(Table *table) {}
