#include <stdio.h>

int main() {
  int value = 1; 
  int count = 0;
  do {
    printf("Type a value : ");
    scanf("%d", &value);
    if (value < 0) break;
    count++; 
  } while (value > 0);

  printf("You typed %d positive integer values", count);
  return 0;
}
