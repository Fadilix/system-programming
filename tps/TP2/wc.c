#include <stdio.h>

int main() {
  int c, line_count = 0, char_count = 0, word_count = 0, in_word = 0;

  while ((c = getchar()) != EOF) {
    char_count++;

    if (c == '\n') {
      line_count++;
    }

    if (c == ' ' || c == '\t' || c == '\n') {
      in_word = 0;
    } else {
      if (!in_word) {
        word_count++;
        in_word = 1;
      }
    }
  }

  printf("lines: %d\n", line_count);
  printf("words: %d\n", word_count);
  printf("chars: %d\n", char_count);
  return 0;
}
