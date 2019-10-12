#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

typedef struct
{
    struct myBinrayTreeNode *left;
    struct myBinrayTreeNode *right;
    struct myBinrayTreeNode *parent;
    unsigned int data;
} myBinrayTreeNode;

void binaryTreeAdd(myBinrayTreeNode **pp_root, int data);
/**
** 先序遍历(root->left->right)
**/
void binaryTreePreOrderIterator(myBinrayTreeNode *p_root);
/**
** 中序遍历(left->root->right)
**/
void binaryTreeInOrderIterator(myBinrayTreeNode *p_root);
/**
** 后序遍历(left->right->root)
**/
void binaryTreePostOrderIterator(myBinrayTreeNode *p_root)
#endif // BINARY_TREE_H_INCLUDED
