#include "bst.h"

void bst_free(BSTNode* root) {
  if (!root) return;

  bst_free(root->left);
  bst_free(root->right);

  free(root->clue_name);
  free(root);
}
