#include <stdio.h>

int absolute(int n) {
  return n < 0 ? -n : n;
}

int main() {
  int value;
  printf("Type an integer value (Can be positive or not): ");
  scanf("%d", &value);
  
  printf("The absolute value is %d", absolute(value));
  return 0;
}
