#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void vector_init(Vector *v) {
  v->size = 0;
  v->capacity = 4;
  v->data = malloc(v->capacity * sizeof(int));
}

void vector_free(Vector *v) {
  free(v->data);
  v->data = NULL;
  v->size = 0;
  v->capacity = 4;
}

void vector_push(Vector *v, int value) {
  if (v->size == v->capacity) {
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * sizeof(int));
  }

  v->data[v->size++] = value;
}

void vector_pop(Vector *v) {
  if (v->size > 0) {
    v->size--;
  }
}

int vector_get(Vector *v, size_t index) {
  if (index > v->size) {
    printf("Index out of range");
    return 0;
  }

  return v->data[index];
}

void vector_set(Vector *v, size_t index, int value) {
  if (index > v->size) {
    printf("Index out of range");
    return;
  }
  v->data[index] = value;
}
