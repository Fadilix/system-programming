#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void cat_strings(char str1[], ...) {
  va_list ap;
  va_start(ap, str1);

  while (str1 != NULL) {
    for (int i = 0; i < strlen(str1); i++) {
      putchar(str1[i]);
    }
    str1 = va_arg(ap, char *);
  }
  va_end(ap);
}

int main() { cat_strings("Tú ", "eres ", " bellísima", NULL); }
