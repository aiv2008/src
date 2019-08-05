#ifndef BALANCE_BINARY_TREE_H_INCLUDED
#define BALANCE_BINARY_TREE_H_INCLUDED

#include "binary_tree.h"

/**
** initialize the node of the balanced tree
**/
NODE* balanced_node_init(unsigned int data);

/**
** initialize the balanced tree
**/
NODE* balanced_tree_init(unsigned int* data, size_t size);

/**
** add the data to the tree
**/
NODE* balanced_tree_add(NODE* root, unsigned int data);

/**
** delete the node of the tree
** param l_r_flag : use the left child node or the right child node instead
**/
NODE* delete_node(NODE* root, unsigned int data);

/**
** rotate left operation
**/
NODE* rotate_left(NODE* root);

/**
** rotate right operation
**/
NODE* rotate_right(NODE* root);

#endif // BALANCE_BINARY_TREE_H_INCLUDED
