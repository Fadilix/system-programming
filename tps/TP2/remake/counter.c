#include <stdio.h>

int main() {
  int occur[256] = {0};
  int c;

  while ((c = getchar()) != EOF) {
    occur[c]++;
  }

  for (char c = '0'; c <= '9'; c++) {
    if (occur[c] > 0) {
      printf("le caractère %c apparaît %d fois\n", c, occur[c]);
    }
  }

  for (char c = 'a'; c <= 'z'; c++) {
    if (occur[c] > 0) {
      printf("le caractère %c apparaît %d fois\n", c, occur[c]);
    }
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    if (occur[c] > 0) {
      printf("le caractère %c apparaît %d fois\n", c, occur[c]);
    }
  }

  return 0;
}
