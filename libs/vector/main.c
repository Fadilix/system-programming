#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {
  Vector *v = malloc(sizeof(Vector));

  vector_init(v);

  int rand_val = rand() % MAX;

  vector_push(v, rand() % MAX);
  vector_push(v, rand() % MAX);
  vector_push(v, rand() % MAX);
  vector_push(v, rand() % MAX);

  for (int i = 0; i < v->size; i++) {
    printf("%d\n", v->data[i]);
  }

  vector_free(v);
  return 0;
}
