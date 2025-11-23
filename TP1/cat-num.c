// this program prints for a file each line with its line number

#include <stdio.h>

int main() {
  int count = 1;
  char c;

  printf("%d ", count);
  while ((c = getchar()) != EOF) {
    putchar(c);

    if (c == '\n') {
      ++count;
      printf("%d ", count);
    }
  }

  return 0;
}
