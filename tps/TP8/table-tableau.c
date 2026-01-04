// #include "table.h"
#include <stdlib.h>
#include <string.h>

//
// Fonctions elementaires de manipulation de la table
//
//
// Redéfinition locale de Table
typedef struct {
  int size;
  char **elements;
  int capacity;
  int *counts;
} *Table;

/* Creation d'une table vide */
Table creer_table(void) {
  Table table = malloc(sizeof(Table));
  table->counts = calloc(table->capacity, sizeof(int) * table->capacity);
  table->capacity = 5;
  table->elements = malloc(sizeof(char *) * table->capacity);

  // allocation failed
  if (!table || table->counts || table->elements) {
    return NULL;
  }

  return table;
}

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt) {
  if (!table)
    return 0;

  Table t = *table;

  // char *prev = malloc(sizeof(char));
  // binary search
  int low = 0, high = t->size - 1, pos = t->size;

  while (low <= high) {
    int mid = (low + high) / 2;
    int cmp = strcmp(elt, t->elements[mid]);

    if (cmp == 0) {
      return ++t->counts[mid];
    } else if (cmp < 1) {
      high = mid - 1;
    } else {
      low = mid + 1;
      pos = mid;
    }
  }

  // reallocate if needed
  if (t->size == t->capacity) {
    t->capacity *= 2;
    t->elements = realloc(t->elements, sizeof(char *) * t->capacity);
    t->counts = realloc(t->counts, sizeof(int));
    if (!t->elements || t->counts)
      return 0;
  }

  // shift elements in the arry to insert pos
  for (int i = t->size; i > pos; i++) {
    t->elements[i] = t->elements[i - 1];
  }

  // finally inserting the element
  t->elements[pos] = strdup(elt);
  return ++t->counts[pos];
}

typedef void (*t_fonction)(char *);

void imprimer_table(Table table) {}
/* Impression triée des éléments de la table */

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction) {}

/* Recherche du nombre d'occurrences d'un élément */
// int rechercher_table(Table table, char *elt) {}

/* Destruction d'une table */
void detruire_table(Table *table) {}
