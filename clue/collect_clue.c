#include "../bst/bst.h"
#include "../hash/hash.h"
#include "../room/room.h"
#include "../suspect/suspect.h"
#include "../utils/utils.h"
#include "clue.h"

/* -------------------------
   Clue collection when entering room
   -------------------------*/

void collect_clue(Room* room, BSTNode** bst_root, SuspectCount** suspect_counts,
                  HashEntry** hash_table) {
  if (!room || !room->clue) return;

  const char* clue_name = room->clue->name;
  const char* suspect_name =
      room->clue->suspect ? room->clue->suspect : UNKNOWN_SUSPECT;

  /* skip if already collected into BST */
  if (bst_search(*bst_root, clue_name)) return;

  /* insert into BST */
  *bst_root = bst_insert(*bst_root, clue_name);

  /* insert mapping and increment suspect count if mapping was not present */
  if (!hash_find(clue_name, hash_table)) {
    hash_insert(clue_name, suspect_name, hash_table);
    suspect_count_increment(suspect_name, suspect_counts);
  }

  /* mark that this room had its clue found (store a copy for visualization) */
  if (!room->found_clue_name)
    room->found_clue_name = string_duplicate_safe(clue_name);

  /* Note: we keep the Clue object to allow showing mapping at the end.
     Clues are freed in final cleanup (free_clues_from_mansion).
  */
}
