#ifndef MIRROR_RECURSIVELY_BINARYTREE_H_INCLUDED
#define MIRROR_RECURSIVELY_BINARYTREE_H_INCLUDED

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct
{
    struct myBinrayTreeNode *left;
    struct myBinrayTreeNode *right;
    struct myBinrayTreeNode *parent;
    unsigned int data;
} myBinrayTreeNode;


void add(myBinrayTreeNode **pp_root, unsigned int data);

void delete(myBinrayTreeNode **pp_root, unsigned int data);

myBinrayTreeNode* search(myBinrayTreeNode **pp_root, unsigned int data);

/**
** 输出镜像(递归)
**/
void mirrorRecursively(myBinrayTreeNode *p_root);
/**
** 输出镜像(循环)
**/
void mirrorLooply(myBinrayTreeNode *p_root);

BOOL binaryTreeIsNullOrEmpty(myBinrayTreeNode **pp_root);

/**
** 先序遍历
**/
void preOrderIterator(myBinrayTreeNode *p_root);
/**
** 中序遍历
**/
void inOrderIterator(myBinrayTreeNode *p_root);
/**
** 后续遍历
**/
void postOrderIterator(myBinrayTreeNode *p_root);

#endif // MIRROR_RECURSIVELY_BINARYTREE_H_INCLUDED
