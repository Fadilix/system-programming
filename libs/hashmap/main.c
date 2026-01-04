#include "hashmap.h"
#include <stdio.h>

int main() {
  HashMap *map = create_hashmap(5);
  insert(map, "hello", "10");
  insert(map, "kim", "k");
  insert(map, "mr", "cat");
  insert(map, "ninja", "turtles");

  printf("%s\n", get(map, "hello"));
  printf("%s\n", get(map, "kim"));
  printf("%s\n", get(map, "mr"));
  printf("%s\n", get(map, "ninja"));

  hm_delete(map, "hello");

  const char *result = get(map, "hello");

  printf("%s\n", result ? result : "not found");
}
