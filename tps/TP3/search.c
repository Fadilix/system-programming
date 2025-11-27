#include <stdio.h>
#include <string.h>

int indexx(const char str[], const char c) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == c) {
      return i;
    }
  }
  return -1;
}

int indexx_right(const char str[], const char c) {
  for (int i = strlen(str); i > 0; i--) {
    if (str[i] == c) {
      return i;
    }
  }
  return -1;
}

int main() {
  char str[] = "Hello world!";
  int index_left = indexx(str, 'o');
  int index_right = indexx_right(str, 'o');

  printf("The first index that matches the character is %d\n", index_left);
  printf("The last index that matches the character is %d\n", index_right);

  return 0;
}
