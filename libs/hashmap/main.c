#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
  char *key;
  char *value;
  struct Entry *next;
} Entry;

typedef struct HashMap {
  Entry **buckets;
  int size;
} HashMap;

// djb1 algorithm
unsigned long hash(const char *key, int size) {
  unsigned long hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % 5;
}

HashMap *create_hash(int size) {
  HashMap *map = malloc(sizeof(HashMap));
  if (!map) {
    return NULL;
  }

  map->buckets = (Entry **)calloc(size, sizeof(Entry *));
  if (!map->buckets) {
    free(map->buckets);
    return NULL;
  }
  map->size = size;
  return map;
}

void insert(HashMap *map, const char *key, const char *value) {
  if (!map || !key || !value) {
    return;
  }

  unsigned long index = hash(key, map->size);
  Entry *current = map->buckets[index];

  while (current) {
    if (strcmp(current->key, key) == 0) {
      free(current->value);
      current->value = strdup(value);
      return;
    }
    current = current->next;
  }

  Entry *new_entry = malloc(sizeof(Entry));
  if (!new_entry)
    return; // allocation failed

  new_entry->key = strdup(key);
  new_entry->value = strdup(value);

  if (!new_entry->key || !new_entry->value) {
    free(new_entry->key);
    free(new_entry->value);
    free(new_entry);
    return;
  }

  new_entry->next = map->buckets[index];
  map->buckets[index] = new_entry;
}

const char *get(HashMap *map, const char *key) {
  if (!map)
    return NULL;
  unsigned long index = hash(key, map->size);
  Entry *current = map->buckets[index];

  while (current) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }
  return NULL; // not found
  //
}

void delete(HashMap *map, const char *key) {
  if (!map || !key)
    return;

  unsigned long index = hash(key, map->size);
  Entry *current = map->buckets[index];
  if (!current)
    return;

  Entry *prev = NULL;
  while (current) {
    if (strcmp(current->key, key) == 0) {
      if (prev == NULL) {
        map->buckets[index] = current->next;
        free(current->key);
        free(current->value);
        free(current);
        return;
      } else {
        prev->next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        return;
      }
    } else {
      prev = current;
      current = current->next;
    }
  }
}

int main() {
  HashMap *map = create_hash(5);
  insert(map, "hello", "10");
  insert(map, "kim", "k");
  insert(map, "mr", "cat");
  insert(map, "ninja", "turtles");

  printf("%s\n", get(map, "hello"));
  printf("%s\n", get(map, "kim"));
  printf("%s\n", get(map, "mr"));
  printf("%s\n", get(map, "ninja"));

  delete(map, "hello");

  const char *result = get(map, "hello");

  printf("%s\n", result ? result : "not found");
}
