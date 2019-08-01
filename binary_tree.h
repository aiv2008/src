#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

/**
** define the node struct
**/

typedef struct
{
    unsigned int data;
    unsigned int depth;
    struct NODE* left;
    struct NODE* right;
    struct NODE* parent;
    signed balanced_factor;
} NODE;

/**
** search the node data of the tree that equals to the input data
**/
void tree_search(NODE* node, unsigned int data);

/**
** fetch the depth of the first node that equals to the input data of the tree
**/
int first_node_depth(NODE* node, unsigned int data);

int equal_data_count(NODE* node, unsigned int data);

/**
** initialize the node of the tree
**/
NODE* node_init(unsigned int data);

/**
** add the data to the tree
** return to the new node
**/
NODE* tree_add(NODE* root, unsigned int data);

/**
** fetch the minimum node data of the tree
**/
NODE* tree_minimum(NODE* root);

/**
** fetch the maximum node data of the tree
**/
NODE* tree_maximum(NODE* root);

void tree_forward_all(NODE* node);

void tree_backward_all(NODE* node);

#endif // BINARY_TREE_H_INCLUDED
