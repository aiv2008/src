#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

typedef struct
{
    struct myBinrayTreeNode *left;
    struct myBinrayTreeNode *right;
    struct myBinrayTreeNode *parent;
    unsigned int data;
} myBinrayTreeNode;

void binaryTreeAdd(myBinrayTreeNode **pp_root, unsigned int data);
/**
** �������(root->left->right)
**/
void binaryTreePreOrderIterator(myBinrayTreeNode *p_root);
/**
** �������(left->root->right)
**/
void binaryTreeInOrderIterator(myBinrayTreeNode *p_root);
/**
** �������(left->right->root)
**/
void binaryTreePostOrderIterator(myBinrayTreeNode *p_root);

void freeBinaryTree(myBinrayTreeNode **ppRoot);

myBinrayTreeNode* binaryTreeMaximum( myBinrayTreeNode* pRoot);

myBinrayTreeNode* binaryTreeMinimum(myBinrayTreeNode* pRoot);
#endif // BINARY_TREE_H_INCLUDED
