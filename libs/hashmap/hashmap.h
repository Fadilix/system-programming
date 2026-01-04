#ifndef _HASHMAP_H
#define _HASHMAP_H

typedef struct Entry {
  char *key;
  char *value;
  struct Entry *next;
} Entry;

typedef struct HashMap {
  Entry **buckets;
  int size;
} HashMap;

unsigned long hash(const char *key, int size);
HashMap *create_hashmap(int size);
void insert(HashMap *map, const char *key, const char *value);
const char *get(HashMap *map, const char *key);
void hm_delete(HashMap *map, const char *key);

#endif
