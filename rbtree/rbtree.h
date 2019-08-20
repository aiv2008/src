#ifndef RBTREE_H_INCLUDED
#define RBTREE_H_INCLUDED
#include "node.h"

/**
** search the input data in the tree
** return: the matched data if exists and nil if others
**/
NODE* tree_search(NODE* root, unsigned int data);

/**
** pre-search
**/
void predecesor(NODE* root);

void predecesor_for_test(NODE* root);
/**
** after-search
**/
void successor(NODE*root);

void successor_for_test(NODE*root);
/**
** search the min data
** return: the min node
**/
NODE* rbtree_minimum(NODE* root);
/**
** search the max data
** return: the max node
**/
NODE* rbtree_maximum(NODE* root);

/**
** insert the node
** return: the root node
**/
NODE* tree_insert(NODE* root, unsigned int data);

/**
** delete the node
** return: the root node
**/
NODE* tree_delete(NODE* root, unsigned int data);

//NODE* tree_rb_delete(NODE* root, unsigned int data);

/**
** rotate left
** param: the right child node of the input node, that will be the root after left rotated
** return: the root node
**/
NODE* rotate_left(NODE* node);

/**
** rotate right
** param: the left child node of the input node, that will be the root after right rotated
** return: the root node
**/
NODE* rotate_right(NODE* node);

/**
** initial the node with input data
** return: the initialized node
**/
NODE* node_init(unsigned int data);
/**
** initial the nil node
** return: the nil node
**/
NODE* nil_node_init();

/**
** initial the tree with the nil node
** the nil node(root node)
**/
NODE* tree_init();

//NODE* tree_balanced(NODE* node);

//void recolor(NODE* root);

/**
** print the node with the tree figure
**/
void print_node(NODE* node);

/**
** connect parent with child(save the relationship between 2 nodes)
**/
void node_rela_save(NODE* parent, NODE* child, unsigned char lof);

/**
** fix up the rb child tree
** param: the child node
** return: the new root of the child tree
**/
NODE* tree_rb_fixup(NODE* node);

/**
** free the node
**/
NODE* release(NODE* node);

#endif // RBTREE_H_INCLUDED
