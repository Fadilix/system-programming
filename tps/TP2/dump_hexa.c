#include <stdio.h>
#define MAX_LINE 16

// TODO : fix later still needs work
int main() {
  int c, char_count = 0;
  int i = 0;

  char line[MAX_LINE];

  while ((c = getchar()) != EOF) {

    line[i++] = c;

    if (i == MAX_LINE) {
      for (int j = 0; j < MAX_LINE; j++) {
        printf("%02x ", (unsigned char)line[j]);
        ;
      }

      printf("|");

      for (int j = 0; j < MAX_LINE; j++) {
        printf("%c", (c >= ' ' && c <= '~') ? line[j] : '.');
      }
      printf("\n");
      i = 0;
    }
  }

  return 0;
}
