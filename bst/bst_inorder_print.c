#include "bst.h"

void bst_inorder_print(BSTNode* root) {
  if (!root) return;

  bst_inorder_print(root->left);
  printf(" - %s\n", root->clue_name);
  bst_inorder_print(root->right);
}
