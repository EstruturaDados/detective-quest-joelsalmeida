#include "../globals.h"

unsigned int hash_function(const char* text) {
  unsigned long sum = 0;
  while (text && *text) {
    sum = (sum * 31u) + (unsigned char)*text++;
  }

  return (unsigned int)(sum % HASH_SIZE);
}
