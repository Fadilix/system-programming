#include <stdio.h>

double celsius_to_fahrenheit(double celsius) {
  return ((9 * celsius) / 5.0) + 32;
}

int main() {
  printf("+-------+-------+\n");
  for (double i = 0; i <= 20; i += 0.5) {
    printf("|  %.1fC | %.1fF |\n", i, celsius_to_fahrenheit(i));
  }
  printf("+-------+-------+");
  return 0;
}
