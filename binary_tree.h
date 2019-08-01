#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

/**
** define the node struct
**/

typedef struct
{
    unsigned int data;//the satellite data of the tree
    unsigned int depth;//the node depth of the tree
    struct NODE* left;//the left child node of this node
    struct NODE* right;//the right child node of this node
    struct NODE* parent;//the parent node of this node
    signed balanced_factor;//the distance between the left child node and right child node
    unsigned int count;//the count of the node that has appeared
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
