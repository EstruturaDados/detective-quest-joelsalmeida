#include <stdio.h>
#include <stdlib.h>

#include "../utils/utils.h"
#include "hash.h"

void hash_insert(const char* clue_name, const char* suspect,
                 HashEntry** hash_table) {
  if (!clue_name || !suspect) return;

  if (hash_find(clue_name, hash_table)) return; /* already present */

  unsigned int index = hash_function(clue_name);
  HashEntry* entry = malloc(sizeof(HashEntry));
  if (!entry) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  entry->clue_name = string_duplicate_safe(clue_name);
  entry->suspect = string_duplicate_safe(suspect);
  entry->next = hash_table[index];
  hash_table[index] = entry;
}
