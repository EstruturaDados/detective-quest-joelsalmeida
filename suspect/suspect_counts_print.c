#include <stdio.h>

#include "suspect.h"

void suspect_counts_print(SuspectCount* suspect_counts) {
  if (!suspect_counts) {
    printf("Nenhum suspeito associado.\n");
    return;
  }

  SuspectCount* current = suspect_counts;
  while (current) {
    printf(" - %s: %d\n", current->suspect, current->count);
    current = current->next;
  }
}
