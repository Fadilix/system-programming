#include <pthread.h>
#include <stdio.h>
#include <string.h>

char *printer_buffer = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *user_thread(void *arg) {
  char *jobs[] = {"Resume.pdf", "Contract.docx", "Recipe.txt"};

  for (int i = 0; i < 3; i++) {
    pthread_mutex_lock(&lock);

    while (printer_buffer != NULL) {
      pthread_cond_wait(&cond, &lock);
    }

    printf("User: Sending job '%s' to printer...\n", jobs[i]);
    printer_buffer = jobs[i];

    pthread_cond_signal(&cond);

    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

void *printer_thread(void *arg) {
  for (int i = 0; i < 3; i++) {
    pthread_mutex_lock(&lock);

    while (printer_buffer == NULL) {
      pthread_cond_wait(&cond, &lock);
    }

    printf("Printer: Now printing... [%s]\n", printer_buffer);
    printer_buffer = NULL;

    pthread_cond_signal(&cond);

    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main() {
  pthread_t user, printer;
  pthread_create(&user, NULL, user_thread, NULL);
  pthread_create(&printer, NULL, printer_thread, NULL);

  pthread_join(user, NULL);
  pthread_join(printer, NULL);

  printf("Done! All jobs printed.\n");
  return 0;
}
