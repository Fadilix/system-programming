#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 100
#define MAX 10000000

pthread_mutex_t lock;

void *routine(void *counter) {
  int *c = (int *)counter;

  char *result = malloc(64 * sizeof(char));

  snprintf(result, 64, "data from thread %ld", (long)counter);

  for (int i = 0; i < MAX; i++) {
    pthread_mutex_lock(&lock);
    (*c)++;
    pthread_mutex_unlock(&lock);
  }

  printf("Thread finished execution\n");

  return (void *)result;
}

int main(void) {
  int count = 0;

  pthread_t threads[NUM_THREADS];
  void *exit_value;

  pthread_mutex_init(&lock, NULL);

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, routine, &count);
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], &exit_value);
  }

  printf("Final count %d\nand the exit value is %s", count, (char *)exit_value);
  free(exit_value);

  return 0;
}
