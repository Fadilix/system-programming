#include <stdio.h>

#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} Vector;

void vector_init(Vector *v);
void vector_free(Vector *v);
void vector_push(Vector *v, int value);
void vector_pop(Vector *v);
int vector_get(Vector *v, size_t index);
void vector_set(Vector *v, size_t index, int value);

#endif
