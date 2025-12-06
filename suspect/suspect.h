#ifndef SUSPECT_H
#define SUSPECT_H

typedef struct SuspectCount {
  char* suspect;
  int count;
  struct SuspectCount* next;
} SuspectCount;

void suspect_count_increment(const char* suspect,
                             SuspectCount** suspect_counts);

void suspect_counts_print(SuspectCount* suspect_counts);

char* suspect_most_cited(SuspectCount* suspect_counts);

void suspect_counts_free(SuspectCount** suspect_counts);

#endif /* SUSPECT_H */
