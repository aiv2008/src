#ifndef RBTREE_H_INCLUDED
#define RBTREE_H_INCLUDED
#include "node.h"


NODE* tree_search(NODE* root, unsigned int data);

void predecesor(NODE* root);

void successor(NODE*root);

NODE* minimum(NODE* root);

NODE* maximum(NODE* root);

NODE* tree_insert(NODE* root, unsigned int data);

NODE* tree_delete(NODE* root, unsigned int data);

NODE* rotate_left(NODE* node);

NODE* rotate_right(NODE* node);

NODE* node_init(unsigned int data);

NODE* tree_init();

NODE* tree_balanced(NODE* node);

void recolor(NODE* root);

#endif // RBTREE_H_INCLUDED
