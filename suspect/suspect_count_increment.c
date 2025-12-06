#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../utils/utils.h"
#include "suspect.h"

void suspect_count_increment(const char* suspect,
                             SuspectCount** suspect_counts) {
  if (!suspect) return;

  SuspectCount* current = *suspect_counts;

  while (current) {
    if (strcasecmp(current->suspect, suspect) == 0) {
      current->count += 1;
      return;
    }

    current = current->next;
  }

  SuspectCount* node = malloc(sizeof(SuspectCount));

  if (!node) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  node->suspect = string_duplicate_safe(suspect);
  node->count = 1;
  node->next = *suspect_counts;

  *suspect_counts = node;
}
