#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  List lst = malloc(sizeof(List));
  lst = prepend_element(lst, 3);
  lst = prepend_element(lst, 3);
  lst = prepend_element(lst, 3);
  lst = prepend_element(lst, 3);

  lst = append_element(lst, 2);
  lst = append_element(lst, 2);
  lst = append_element(lst, 2);
  lst = append_element(lst, 2);
  //
  // print_list(lst);
  //
  // delete_element(lst, 2);
  // print_list(lst);
  //
  // delete_elements(lst, 3);
  // print_list(lst);
  //
  size_t size = sizeof(int *);

  size_t lst_size = sizeof(List);

  printf("%zu\n", size);
  printf("%zu\n", lst_size);
  printf("%zu\n", sizeof(double *));

  char array[] = "something is wrong about this code";
  printf("%c", 1 [array]);
}
