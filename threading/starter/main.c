#include <pthread.h>
#include <stdio.h>

void *print_message(void *msg) {
  char *msg_c = (char *)msg;
  printf("%s", msg_c);

  return NULL;
}

int main(void) {

  pthread_t thread;
  char *msg = "hello world!!!\n";

  if (pthread_create(&thread, NULL, print_message, (void *)msg)) {
    fprintf(stderr, "Error creating thread\n");
  }

  pthread_join(thread, NULL);

  printf("Thread finished execution\n");

  return 0;
}
