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

  // vector_free(v); // this is where the error is from

  vector_pop(v);
  printf("The size of the vector is %zu\n", v->size);

  int val = vector_get(v, 2);
  printf("%d\n", val);

  printf("This is the value of the vector data before\n");
  for (int i = 0; i < v->size; i++) {
    printf("%d\n", v->data[i]);
  }

  // vector_set(v, 3, 2020);
  // printf("This is the value of the vector data after\n");
  // for (int i = 0; i < v->size; i++) {
  //   printf("%d\n", v->data[i]);
  // }

  vector_free(v);
  return 0;
}
