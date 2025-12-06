#include <ctype.h>

/* case-insensitive compare; safe on ASCII and locale-dependent for others */
int case_insensitive_compare(const char* a, const char* b) {
  if (!a) return b ? -1 : 0;
  if (!b) return 1;

  while (*a && *b) {
    unsigned char ca = (unsigned char)tolower((unsigned char)*a);
    unsigned char cb = (unsigned char)tolower((unsigned char)*b);
    if (ca != cb) return (ca < cb) ? -1 : 1;
    a++;
    b++;
  }

  if (*a == *b) return 0;

  return (*a) ? 1 : -1;
}
