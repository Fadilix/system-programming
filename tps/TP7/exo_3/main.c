#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TBLOC 14

char *readline(void) {
  char *read = malloc(sizeof(char) * TBLOC);
  char *ptr = read;

  int capacity = TBLOC;

  int size = 0, c;

  while ((c = getchar()) != EOF && c != '\n') {
    read++;
    size++;

    *read = c;

    if (capacity == size - 1) {
      capacity += capacity / 2;
      read = realloc(ptr, capacity);
      ptr = realloc(ptr, capacity);
    }
  }

  *read = '\0';

  return ptr;
}

int main() {
  char *s = NULL;

  do {
    printf("Entrer une chaîne de caractère : ");

    fflush(stdout);

    s = readline();

    if (s) {
      printf("Chaîne lue %s\n", s);
      free(s);
    }
  } while (s);
  return 0;
}
