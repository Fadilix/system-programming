

#ifndef _HASHMAP_H2
#define _HASHMAP_H2

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
char *get(HashMap *map, const char *key);
void destroy_hashmap(HashMap *map);

#endif
