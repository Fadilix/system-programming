#include <stdio.h>
#include <stdlib.h>

char *strcpy_remake(char *dest, const char *src) {
  char *ptr = dest; // storing the value of the start
  while ((*dest++ = *src++))
    ;
  return ptr;
}

size_t strlen_remake(const char *s) {
  size_t count = 0;
  while (*s++)
    count++;
  ;
  return count;
}

char *strdup_remake(const char *s) {
  size_t len = strlen_remake(s) + 1;
  char *copy = malloc(len);
  if (copy == NULL)
    return NULL;
  strcpy_remake(copy, s);
  return copy;
}

char *strchr_remake(const char *s, int c) {
  while (*s) {
    if (*s == (char)c)
      return (char *)s;
    s++;
  }

  // if (c == '\0')
  //   return (char *)s;

  return NULL;
}

int main() {
  char dest[40] = "something";
  char source[] = "This is the source";

  char *new_val = strcpy_remake(dest, source);

  for (int i = 0; i < strlen_remake(new_val); i++) {
    putchar(new_val[i]);
  }

  printf("\n");

  // testing strlen
  char random_str[] = "This is random str that is gonna be copied later";
  printf("The length of the random str is %zu\n", strlen_remake(random_str));

  // testing strdup
  char *copy = strdup_remake(random_str);
  for (int i = 0; i < strlen_remake(copy); i++) {
    putchar(copy[i]);
  }

  free(copy);

  printf("\n");

  char to_iterate_over[100] =
      "I'm gonna get at least 18/20 on the C exam, mark my works";
  char *the_char_we_want = strchr_remake(to_iterate_over, 'C');

  printf("Original string is : ");
  for (int i = 0; i < strlen_remake(to_iterate_over); i++) {
    putchar(to_iterate_over[i]);
  }

  printf("\n");
  printf("Printing the string starting from the char we want\n");

  for (int i = 0; i < strlen_remake(the_char_we_want); i++) {
    putchar(the_char_we_want[i]);
  }

  return 0;
}
