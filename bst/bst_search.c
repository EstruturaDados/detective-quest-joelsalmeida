#include "../utils/utils.h"
#include "bst.h"

int bst_search(BSTNode* root, const char* clue_name) {
  BSTNode* current = root;

  while (current) {
    int cmp = case_insensitive_compare(clue_name, current->clue_name);
    if (cmp == 0) return 1;
    current = (cmp < 0) ? current->left : current->right;
  }

  return 0;
}
