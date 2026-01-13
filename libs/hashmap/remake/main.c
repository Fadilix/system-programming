#include "hashmap.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
  printf("Testing Hashmap...\n");

  // Create
  HashMap *map = create_hashmap(10);
  assert(map != NULL);
  printf("[PASS] Creation\n");

  // Insert
  insert(map, "hello", "world");
  insert(map, "foo", "bar");
  insert(map, "key", "value");
  printf("[PASS] Insertion\n");

  // Get
  char *val1 = get(map, "hello");
  char *val2 = get(map, "foo");
  char *val3 = get(map, "key");
  char *val4 = get(map, "missing");

  assert(strcmp(val1, "world") == 0);
  assert(strcmp(val2, "bar") == 0);
  assert(strcmp(val3, "value") == 0);
  assert(val4 == NULL);
  printf("[PASS] Retrieval\n");

  // Update
  insert(map, "hello", "galaxy");
  char *val_updated = get(map, "hello");
  assert(strcmp(val_updated, "galaxy") == 0);
  printf("[PASS] Update\n");

  // Destroy
  destroy_hashmap(map);
  printf("[PASS] Destruction\n");

  printf("All tests passed!\n");
  return 0;
}
