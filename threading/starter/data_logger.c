#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define CLIENT_THREADS 3
// #define LOGGER_THREADS 1

pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

char *message_buffer = NULL;
int message_available = 0;

void *client_worker(void *arg) {

  int *id = (int *)arg;

  for (int i = 0; i < 6; i++) {
    printf("client working...\n");
    pthread_mutex_lock(&lock);
    while (message_available == 1) {
      pthread_cond_wait(&cond_empty, &lock);
    }

    message_buffer = malloc(64);
    sprintf(message_buffer, "Step: Executed from thread %d", *id);
    message_available = 1;

    pthread_cond_signal(&cond_full);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

void *logger(void *arg) {
  for (int i = 0; i < 6 * CLIENT_THREADS; i++) {
    printf("logger working...\n");
    pthread_mutex_lock(&lock);

    while (message_available == 0) {
      pthread_cond_wait(&cond_full, &lock);
    }

    printf("[LOG] Message from client : %s\n", message_buffer);
    free(message_buffer);
    message_buffer = NULL;
    message_available = 0;

    pthread_cond_signal(&cond_empty);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main(void) {
  pthread_t threads[CLIENT_THREADS];
  pthread_t logger_thread;
  int ids[CLIENT_THREADS];

  for (int i = 0; i < CLIENT_THREADS; i++) {
    ids[i] = i + 1;
    if (pthread_create(&threads[i], NULL, client_worker, &ids[i])) {
      fprintf(stderr, "Error while creating client thread\n");
    }
  }

  if (pthread_create(&logger_thread, NULL, logger, NULL)) {
    fprintf(stderr, "Error while creating logger thread\n");
  }

  for (int i = 0; i < CLIENT_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  pthread_join(logger_thread, NULL);

  return 0;
}
