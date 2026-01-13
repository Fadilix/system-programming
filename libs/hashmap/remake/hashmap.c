#include "hashmap.h"

#include <stdlib.h>
#include <string.h>

unsigned long hash(const char *key, int size) {
  if (!key || size == 0)
    return -1;

  unsigned long hash = 5381;
  int c;
  while ((c = *key++))
    hash = (hash << 5) + c;
  return hash % size;
}

HashMap *create_hashmap(int size) {
  HashMap *map = malloc(sizeof(HashMap));
  if (!map)
    return NULL;

  map->size = size;
  map->buckets = calloc(map->size, sizeof(Entry *));
  if (!map->buckets) {
    free(map);
    return NULL;
  }

  return map;
}

void insert(HashMap *map, const char *key, const char *value) {
  if (!map || !key || !value)
    return;

  unsigned long index = hash(key, map->size);
  Entry *current = map->buckets[index];

  // Check if key exists and update
  while (current) {
    if (strcmp(current->key, key) == 0) {
      free(current->value);
      current->value = strdup(value);
      return;
    }
    current = current->next;
  }

  // Insert new entry at head (O(1))
  Entry *new_entry = malloc(sizeof(Entry));
  if (!new_entry)
    return;

  new_entry->key = strdup(key);
  new_entry->value = strdup(value);
  new_entry->next = map->buckets[index];
  map->buckets[index] = new_entry;
}

char *get(HashMap *map, const char *key) {
  if (!map || !key)
    return NULL;

  unsigned long index = hash(key, map->size);
  Entry *current = map->buckets[index];

  while (current) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }

  return NULL;
}

void destroy_hashmap(HashMap *map) {
  if (!map)
    return;

  for (int i = 0; i < map->size; i++) {
    Entry *current = map->buckets[i];
    while (current) {
      Entry *next = current->next;
      free(current->key);
      free(current->value);
      free(current);
      current = next;
    }
  }

  free(map->buckets);
  free(map);
}
