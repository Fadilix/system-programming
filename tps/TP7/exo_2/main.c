#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  List lst = malloc(sizeof(List));
  lst = prepend_element(lst, 3);
  lst = append_element(lst, 2);
  lst = append_element(lst, 5);
  lst = append_element(lst, 5);
  lst = append_element(lst, 5);
  lst = append_element(lst, 5);
  lst = append_element(lst, 5);
  lst = append_element(lst, 5);

  print_list(lst);

  lst = delete_element(lst, 2);

  print_list(lst);

  lst = delete_elements(lst, 5);

  // delete_elements(lst, 3);

  print_list(lst);

  // int result = find_element(lst, 1);
  // printf(result ? "Element found" : "Element not found");
}
