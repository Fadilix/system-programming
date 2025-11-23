#include <math.h>
#include <stdio.h>

double celsius_to_fahrenheit(double celsius) {
  return ((9 * celsius) / 5.0) + 32;
}

int main() {
  printf("+-------+-------+\n");
  for (double celsius = 0; celsius <= 20; celsius += 0.5) {
    int fahrenheit = (int)rint((celsius_to_fahrenheit(celsius)));

    printf("|  %.1fC | %dF |\n", celsius, fahrenheit);
  }

  printf("+-------+-------+");
  return 0;
}
