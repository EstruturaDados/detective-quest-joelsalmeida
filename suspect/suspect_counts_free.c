#include <stddef.h>
#include <stdlib.h>

#include "suspect.h"

void suspect_counts_free(SuspectCount** suspect_counts) {
  SuspectCount* current = *suspect_counts;

  while (current) {
    SuspectCount* next_node = current->next;
    free(current->suspect);
    free(current);
    current = next_node;
  }

  *suspect_counts = NULL;
}
