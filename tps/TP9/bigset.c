#include <stdio.h>
#define CHAR_SIZE 8
#define MAX_BIGSET 125
#define MAX_VAL (CHAR_SIZE * MAX_BIGSET)

typedef unsigned char BigSet[MAX_BIGSET];

void BigSet_init(BigSet s) {
  for (int i = 0; i < MAX_BIGSET; i++) {
    s[i] = 0;
  }
}

void bigSet_add(BigSet s, int i) {
  if (i >= 0 && i <= MAX_VAL) {
    int byte = i / CHAR_SIZE;
    int bit = i % CHAR_SIZE;
    s[byte] |= 1 << bit;
  }
}

int main() { return 0; }
