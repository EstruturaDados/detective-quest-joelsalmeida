#include <stdlib.h>

#include "../utils/utils.h"
#include "bst.h"

BSTNode* bst_insert(BSTNode* root, const char* clue_name) {
  if (!root) {
    BSTNode* node = malloc(sizeof(BSTNode));

    if (!node) {
      perror("malloc");
      exit(EXIT_FAILURE);
    }

    node->clue_name = string_duplicate_safe(clue_name);
    node->left = node->right = NULL;

    return node;
  }

  int cmp = case_insensitive_compare(clue_name, root->clue_name);

  if (cmp == 0) return root; /* already present */

  if (cmp < 0)
    root->left = bst_insert(root->left, clue_name);
  else
    root->right = bst_insert(root->right, clue_name);

  return root;
}
