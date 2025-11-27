#include <stdio.h>
#include <string.h>

void strcpy_remake(char s1[], char s2[]) {
  int i = 0;
  for (i = 0; s2[i]; i++) {
    s1[i] = s2[i];
  }
  s2[i] = '\0';
}

int strcmp_remake(char s1[], char s2[]) {
  int i = 0;

  for (i = 0; s1[i] && s1[i] == s2[i]; i++) {
  }

  return s1[i] - s2[i];
}

void strupper_remake(char str[]) {
  for (int i = 0; str[i]; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] += 'A' - 'a';
    }
  }
}

int main() {
  char str[] = "I'm a fu**ing genius";
  strupper_remake(str);

  int comp = strcmp_remake("A", "B");

  printf("%d\n", comp);

  for (int i = 0; i < strlen(str); i++) {
    putchar(str[i]);
  }
  return 0;
}
