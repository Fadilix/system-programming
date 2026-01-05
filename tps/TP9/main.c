#include <stdio.h>

void print_in_base10(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10) {
    print_in_base10(n / 10);
  }
  putchar(n % 10 + '0');
}

void print_in_base_n(int n, int b) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / b) {
    print_in_base_n(n / b, b);
  }

  int digit = n % b;
  putchar(digit < 10 ? digit + '0' : digit - 10 + 'A');
}

void print_binary(int n) {
  if (n) {
    print_binary(n / 2);
  }
  putchar(n % 2 + '0');
}

void print_bin_with_bit(int n) {
  if (n) {
    print_bin_with_bit(n >> 1);
  }
  putchar((n & 1) + '0');
  // 10111000101
  // 00000000001
}

int main() {
  print_in_base10(100);
  print_in_base_n(1008722057, 36);
  printf("\n");
  print_binary(16);
  printf("\n");
  print_bin_with_bit(17);
  printf("\n");
  print_bin_with_bit(0);

  return 0;
}
