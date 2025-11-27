#include "str.h"
#include <stdlib.h>

// size_t my_strlen(const char *str) {
//   int count = 0;
//   while (*str++)
//     count++;
//   return count;
// }
//

// pointer arithmetic
size_t my_strlen(const char *str) {
  const char *p = str;
  while (*p)
    p++;
  return p - str;
}

char *my_strcpy(char *dst, const char *src) {
  char *p = dst;
  while ((*dst++ = *src++))
    ;
  return p;
}

char *my_strdup(const char *str) {
  size_t len = my_strlen(str) + 1;
  char *copy = malloc(len);
  my_strcpy(copy, str);
  return copy;
}

int my_strcmp(const char *first, const char *second) {
  while ((*first) && (*first == *second)) {
    first++;
    second++;
  }

  return *(unsigned char *)first - *(unsigned char *)second;
}

char *my_strcat(char *dest, const char *src) {
  char *first = dest;
  char *p_temp = dest;

  while (*dest++)
    p_temp++;
  ;
  while ((*p_temp++ = *src++))
    ;
  return first;
}
