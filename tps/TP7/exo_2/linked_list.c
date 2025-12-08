#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

List prepend_element(List lst, int v) {
  assert(lst != NULL);

  List temp_lst = malloc(sizeof(List));
  temp_lst->value = v;
  temp_lst->next = lst;
  lst = temp_lst;

  return lst;
}

List append_element(List lst, int v) {
  assert(lst != NULL);

  List ptr_lst = lst;

  for (; lst->next; lst = lst->next)
    ;

  List tmp_lst = malloc(sizeof(List));
  tmp_lst->value = v;
  tmp_lst->next = NULL;

  lst->next = tmp_lst;
  // lst->next = tmp;
  // free(tmp_lst);

  return ptr_lst;
}

List delete_elements(List lst, int v) {
  assert(lst != NULL);
  while (lst != NULL && (lst->value == v)) {
    List tmp_lst = lst;
    lst = lst->next;
    free(tmp_lst);
  }

  List ptr_lst = lst;

  while (lst->next != NULL) {
    if (lst->next->value == v) {
      List tmp_lst = lst->next;
      lst->next = tmp_lst->next;
      // printf("infinite loop");
      free(tmp_lst);
      // return ptr_lst;
    } else {
      lst = lst->next;
    }
  }
  return ptr_lst;
}

int find_element(List lst, int v) {
  assert(lst != NULL);
  for (; lst != NULL; lst = lst->next)
    if (lst->value == v)
      return 1;
  return 0;
}

List delete_element(List lst, int v) {
  assert(lst != NULL);

  if (lst != NULL && (lst->value == v)) {
    List tmp_lst = lst;
    lst = lst->next;
    free(tmp_lst);
    return lst;
  }

  List ptr_lst = lst;

  while (lst != NULL && (lst->value != v)) {
    if (lst->next->value == v) {
      List tmp_lst = lst->next;
      lst->next = tmp_lst->next;
      free(tmp_lst);
      return ptr_lst;
    }
    printf("%d\n", lst->value);
    lst = lst->next;
  }

  return ptr_lst;
}

void print_list(List lst) {
  assert(lst != NULL);
  while (lst) {
    printf("%d", lst->value);
    if (lst->next != NULL) {
      printf(" -> ");
    }
    lst = lst->next;
  }
  printf("\n");
}
