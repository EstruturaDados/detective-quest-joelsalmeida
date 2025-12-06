#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTNode {
  char* clue_name;
  struct BSTNode* left;
  struct BSTNode* right;
} BSTNode;

void bst_free(BSTNode* root);

void bst_inorder_print(BSTNode* root);

BSTNode* bst_insert(BSTNode* root, const char* clue_name);

int bst_search(BSTNode* root, const char* clue_name);

#endif /* BST_H */
