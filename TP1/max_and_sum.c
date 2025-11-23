#include <stdio.h>

int get_max(int a, int b) { return a > b ? a : b; }

int main() {
  int value = 1;
  int count = 0;
  int max = -1;
  int sum = 0;

  for (;;) {
    printf("Type a value : ");
    scanf("%d", &value);

    if (value < 0)
      break;

    max = get_max(max, value);
    sum += value;

    count++;
  }

  printf("The maximum of the %d positive integer values you typed is %d. The "
         "sum is %d",
         count, max, sum);
  return 0;
}
