#include <stdio.h>

int main() {
  int c, line_count, char_count, word_count;

  while ((c = getchar()) != EOF) {
    char_count++;
  }

  printf("Le nombre de caractère est %d", char_count);

  return 0;
}
