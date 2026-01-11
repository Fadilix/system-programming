#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

// using the djb2 algorithm
unsigned long hash(const char *key, int size) {
  if (!key || size == 0)
    return -1;

  unsigned long hash = 5381;
  int c;
  while ((c = *key++))
    hash = (hash << 5) + c;
  return hash % size;
}

HashMap *create_hashmap() {
  HashMap *map = malloc(sizeof(HashMap));

  // malloc failed
  if (!map) {
    return NULL;
  }

  map->size = 4;
  map->buckets = calloc(map->size, sizeof(Entry *));

  // malloc failed
  if (!map->buckets) {
    return NULL;
  }

  return map;
}

void *insert(HashMap *map, const char *key, const char *value) {
  if (!map) {
    printf("No map provided");
    return;
  }

  unsigned long index = hash(key, map->size);
  Entry *current = map->buckets[index];
}
