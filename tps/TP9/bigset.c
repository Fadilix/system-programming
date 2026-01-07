#include <stdio.h>
#define CHAR_SIZE 8
#define MAX_BIGSET 125
#define MAX_VAL (CHAR_SIZE * MAX_BIGSET)

typedef unsigned char BigSet[MAX_BIGSET];

void bigSet_init(BigSet s) {
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

int bigSet_is_in(BigSet s, int i) {
  if (i >= 0 && i <= MAX_VAL) {
    int byte = i / CHAR_SIZE;
    int bit = i % CHAR_SIZE;

    int start = s[byte];
    int intermidiate = start | 1 << bit;

    return start == intermidiate ? 1 : 0;
  }
  return 0;
}

int main() {
  BigSet e1, e2, e3;
  bigSet_init(e1);
  bigSet_init(e2);
  bigSet_init(e3);

  bigSet_add(e2, 0);
  bigSet_add(e2, 30);
  bigSet_add(e2, 10);
  bigSet_add(e2, 40);
  int is_in = bigSet_is_in(e2, 10);

  if (is_in) {
    printf("The value %d is in the list", 10);
  } else {
    printf("The value %d is in not the list", 10);
  }

  return 0;
  ;
}
