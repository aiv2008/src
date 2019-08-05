#ifndef BALANCE_BINARY_TREE_H_INCLUDED
#define BALANCE_BINARY_TREE_H_INCLUDED

#include "binary_tree.h"

/**
** initialize the node of the balanced tree
**/
NODE* balanced_node_init(unsigned int data);

NODE* balanced_tree_init(unsigned int* data, size_t size);

/**
** add the data to the tree
**/
NODE* balanced_tree_add(NODE* root, unsigned int data);

/**
** rotate left
**/
NODE* rotate_left(NODE* root);

/**
** rotate right
**/
NODE* rotate_right(NODE* root);

#endif // BALANCE_BINARY_TREE_H_INCLUDED
