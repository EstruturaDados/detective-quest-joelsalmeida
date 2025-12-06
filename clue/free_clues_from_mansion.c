#include <stddef.h>

#include "../room/room.h"
#include "clue.h"

/* Free all clue objects created in build_mansion.
   We must free each unique Clue that was created.
   For this small example we free each clue pointer once by traversing tree.
*/
void free_clues_from_mansion(Room* root) {
  if (!root) return;

  if (root->clue) {
    clue_free(root->clue);
    root->clue = NULL;
  }

  free_clues_from_mansion(root->left);
  free_clues_from_mansion(root->right);
}
