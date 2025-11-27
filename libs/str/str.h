#include <stdio.h>

#ifndef STR_H
#define STR_H

// String Library (str.h)
// remaking these to learn more about c
//
// Implement functions:
// my_strlen
// my_strcpy, my_strdup
// my_strcmp
// my_strcat

size_t my_strlen(const char *str); // length of an array of char

char *
my_strcpy(char *dst,
          const char *src); // copy the content of a string to another string

char *
my_strdup(const char *str); // return a pointer to the first element of the copy

int my_strcmp(const char *first,
              const char *second); // compare two (char *) and return the

char *my_strcat(char *dest, const char *src);

#endif
