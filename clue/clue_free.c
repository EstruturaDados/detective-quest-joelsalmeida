#include <stdlib.h>

#include "clue.h"

void clue_free(Clue* clue_ptr) {
  if (!clue_ptr) return;

  if (clue_ptr->name) free(clue_ptr->name);
  if (clue_ptr->suspect) free(clue_ptr->suspect);

  free(clue_ptr);
}
