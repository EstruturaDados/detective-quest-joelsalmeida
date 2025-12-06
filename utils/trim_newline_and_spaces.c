#include <ctype.h>
#include <string.h>

/* trim leading/trailing whitespace and newline in place */
void trim_newline_and_spaces(char* text) {
  if (!text) return;

  /* trim trailing */
  size_t length = strlen(text);
  while (length > 0 && isspace((unsigned char)text[length - 1])) {
    text[length - 1] = '\0';
    length--;
  }

  /* trim leading */
  char* ptr = text;
  while (*ptr && isspace((unsigned char)*ptr)) ptr++;

  if (ptr != text) memmove(text, ptr, strlen(ptr) + 1);
}
