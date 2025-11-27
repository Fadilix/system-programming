#include "str.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  char string[] = "hello world!!!";
  char src[] = "this is the source";
  char dst[] = "this is the destination";

  char to_copy[] = "this is the string to copy";

  char *result = my_strcpy(dst, src);
  printf("%zu\n", my_strlen(string)); // testing my_strlen

  printf("this is the destination now: %s\n", result);

  char *copy = my_strdup(to_copy);
  printf("this is the copied array : %s\n", copy);
  free(copy);

  // comparing
  const char greater[] = "cartoon";
  const char less[] = "cartoon";

  printf("%d\n", my_strcmp(greater, less));

  // concat
  char src_concat[] = "hello";
  char dest_concat[] = "something other than hello";
  char *result_concat = my_strcat(dest_concat, src_concat);

  printf("this is the contatenated string: %s", result_concat);

  return 0;
}
