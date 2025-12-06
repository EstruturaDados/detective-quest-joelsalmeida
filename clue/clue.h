#ifndef CLUE_H
#define CLUE_H

#include "../bst/bst.h"
#include "../hash/hash.h"
#include "../suspect/suspect.h"

/* Forward declaration – avoids circular include */
struct Room;
typedef struct Room Room;

typedef struct Clue {
  char* name;    /* clue identifier (string) */
  char* suspect; /* suspect name associated with this clue */
} Clue;

Clue* clue_create(const char* name, const char* suspect);

void clue_free(Clue* clue);

void collect_clue(Room* room, BSTNode** bst_root, SuspectCount** suspect_counts,
                  HashEntry** hash_table);

void free_clues_from_mansion(Room* root);

#endif /* CLUE_H */
