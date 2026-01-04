//                                                      -*- coding: utf-8 -*-

#ifndef TABLE_H
#define TABLE_H /* Protection contre les inclusions multiples */

/* Type encapsulé pour la table: une table est un pointeur vers une
 * structure C dont on ne connaît pas le détail */

// liste chaînée
struct node {
  char *elt;
  int count;
  struct node *next;
};

typedef struct node *Table;

typedef void (*t_fonction)(char *elt);

/* Creation d'une table vide */
Table creer_table(void);

/* Insertion d'un élément dans la table triée. Si l'élément est déjà
 * présent dans la table, le compteur d'occurrences est incrémenté.
 * La fonction renvoie le nombre actuel d'occurrences de elt */
int ajouter_table(Table *table, char *elt);

/* Impression triée des éléments de la table */
void imprimer_table(Table table);

/* Appel d'une fonction sur chacun des éléments de la table */
void appliquer_table(Table table, t_fonction fonction);

/* Recherche du nombre d'occurrences d'un élément */
int rechercher_table(Table table, char *elt);

/* Destruction d'une table */
void detruire_table(Table *table);

#endif /* TABLE_H */
