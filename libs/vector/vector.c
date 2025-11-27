#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_init(Vector *v) {
  v->size = 0;
  v->capacity = 4;
  v->data = malloc(sizeof(int) * v->capacity);
}

void vector_free(Vector *v) {
  free(v->data);
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}

void vector_push(Vector *v, int value) {
  if (v->size == v->capacity) {
    size_t new_capacity = v->capacity * 2;
    int *new_data = realloc(v->data, new_capacity * sizeof(int));

    if (!new_data) {
      fprintf(stderr, "failed reallocating memory");
      return;
    }
    v->data = new_data;
    v->capacity = new_capacity;
  }

  v->data[v->size] = value;
  v->size++;
}
