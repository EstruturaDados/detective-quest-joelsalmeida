#include <stdio.h>

#include "hash.h"

void hash_print_all(HashEntry** hash_table) {
  int printed = 0;
  for (int i = 0; i < HASH_SIZE; ++i) {
    HashEntry* entry = hash_table[i];
    while (entry) {
      printf(" - \"%s\" -> %s\n", entry->clue_name, entry->suspect);
      printed = 1;
      entry = entry->next;
    }
  }

  if (!printed) printf("Nenhuma pista cadastrada.\n");
}
