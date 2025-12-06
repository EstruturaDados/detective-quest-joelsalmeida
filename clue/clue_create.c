
#include <stdio.h>
#include <stdlib.h>

#include "../globals.h"
#include "../utils/utils.h"
#include "clue.h"

Clue* clue_create(const char* name, const char* suspect) {
  if (!name) return NULL;

  Clue* new_clue = malloc(sizeof(Clue));

  if (!new_clue) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  new_clue->name = string_duplicate_safe(name);
  new_clue->suspect = suspect ? string_duplicate_safe(suspect)
                              : string_duplicate_safe(UNKNOWN_SUSPECT);
  return new_clue;
}
