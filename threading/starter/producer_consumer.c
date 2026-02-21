#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int message_buffer = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *producer(void *arg) {
  for (int i = 0; i < 5; i++) {
    pthread_mutex_lock(&lock);
    while (message_buffer != 0) {
      pthread_cond_wait(&cond, &lock);
    }
    message_buffer = i + 1;
    printf("Produced: %d\n", message_buffer);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

void *consumer(void *arg) {
  for (int i = 0; i < 5; i++) {

    pthread_mutex_lock(&lock);
    while (message_buffer == 0) {
      pthread_cond_wait(&cond, &lock);
    }
    printf("Consumed %d\n", message_buffer);
    message_buffer = 0;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main() {
  pthread_t p, c;
  pthread_create(&p, NULL, producer, NULL);
  pthread_create(&c, NULL, consumer, NULL);
  pthread_join(p, NULL);
  pthread_join(c, NULL);
  return 0;
}
