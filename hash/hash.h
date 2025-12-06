#ifndef HASH_H
#define HASH_H

#include "../globals.h"

typedef struct HashEntry {
  char* clue_name;
  char* suspect; /* <-- consistent field name: suspect */
  struct HashEntry* next;
} HashEntry;

HashEntry* hash_find(const char* clue_name, HashEntry** hash_table);

void hash_free_all(HashEntry** hash_table);

unsigned int hash_function(const char* text);

void hash_insert(const char* clue_name, const char* suspect,
                 HashEntry** hash_table);

void hash_print_all(HashEntry** hash_table);

#endif /* HASH_H */
