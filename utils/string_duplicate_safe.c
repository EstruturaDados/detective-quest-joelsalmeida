#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* safe strdup replacement */
char* string_duplicate_safe(const char* src) {
  if (!src) return NULL;

  size_t length = strlen(src);
  char* copy = malloc(length + 1);

  if (!copy) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  memcpy(copy, src, length + 1);
  return copy;
}
