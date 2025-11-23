#include <stdio.h>
#include <string.h>

// 1 is palindrome 0 not
//
int palindrome(const char str[]) {
  int i = 0, j = strlen(str) - 1;
  while (i < j) {
    if (str[i] != str[j]) {
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}

int main() {
  char str[] = "racecae";

  printf(palindrome(str) == 1 ? "It is a palindrome"
                              : "It is not a palindrome");
  return 0;
}
