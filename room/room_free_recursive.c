
#include <stdlib.h>

#include "../room/room.h"

void room_free_recursive(Room* root) {
  if (!root) return;

  room_free_recursive(root->left);
  room_free_recursive(root->right);

  if (root->name_pt) free(root->name_pt);
  if (root->found_clue_name) free(root->found_clue_name);
  /* do not free root->clue here; clues are freed separately */
  free(root);
}
