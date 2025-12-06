#include <stddef.h>

#include "suspect.h"

char* suspect_most_cited(SuspectCount* suspect_counts) {
  if (!suspect_counts) return NULL;

  SuspectCount* current = suspect_counts;
  SuspectCount* best = current;

  while (current) {
    if (current->count > best->count) best = current;
    current = current->next;
  }

  return best ? best->suspect : NULL;
}
