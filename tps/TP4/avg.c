#include <stdarg.h>
#include <stdio.h>

float average(int count, ...) {
  va_list ap;
  va_start(ap, count);

  float sum = 0;
  for (int i = 0; i < count; i++) {
    float val = va_arg(ap, double);
    sum += val;
  }

  va_end(ap);

  return sum / count;
}

int main() {
  printf("AVG = %.1f\n", average(2, 10.0, 15.0));
  return 0;
}
