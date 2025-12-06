#include <stdlib.h>
#include <string.h>
#include <strings.h>  // POSIX strcasecmp (needed on Linux)

#include "hash.h"

HashEntry* hash_find(const char* clue_name, HashEntry** hash_table) {
  if (!clue_name) return NULL;

  unsigned int index = hash_function(clue_name);
  HashEntry* entry = hash_table[index];
  while (entry) {
    if (strcasecmp(entry->clue_name, clue_name) == 0) return entry;
    entry = entry->next;
  }

  return NULL;
}
