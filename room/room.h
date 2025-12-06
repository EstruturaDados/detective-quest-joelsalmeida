#ifndef ROOM_H
#define ROOM_H

#include "../bst/bst.h"
#include "../hash/hash.h"
#include "../suspect/suspect.h"

/* Forward declaration – avoids circular include */
struct Clue;
typedef struct Clue Clue;

typedef struct Room {
  char* name_pt;         /* Portuguese room name (shown to user) */
  Clue* clue;            /* pointer to a Clue object or NULL */
  int visited;           /* 1 if visited, 0 otherwise */
  char* found_clue_name; /* copy of clue->name if clue was found here (for
                            visualization) */
  struct Room* left;
  struct Room* right;
} Room;

void explore_rooms(Room* start, BSTNode** bst_root,
                   SuspectCount** suspect_counts, HashEntry** hash_table);

Room* room_create(const char* name_pt, Clue* clue);

void room_free_recursive(Room* root);

#endif /* ROOM_H */
