#include <stdlib.h>

#include "hash.h"

void hash_free_all(HashEntry** hash_table) {
  for (int i = 0; i < HASH_SIZE; ++i) {
    HashEntry* entry = hash_table[i];

    while (entry) {
      HashEntry* next_entry = entry->next;
      free(entry->clue_name);
      free(entry->suspect);
      free(entry);
      entry = next_entry;
    }
    hash_table[i] = NULL;
  }
}
