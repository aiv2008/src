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
** �������(�ݹ�)
**/
void mirrorRecursively(myBinrayTreeNode *p_root);
/**
** �������(ѭ��)
**/
void mirrorLooply(myBinrayTreeNode *p_root);

BOOL binaryTreeIsNullOrEmpty(myBinrayTreeNode **pp_root);

/**
** �������
**/
void preOrderIterator(myBinrayTreeNode *p_root);
/**
** �������
**/
void inOrderIterator(myBinrayTreeNode *p_root);
/**
** ��������
**/
void postOrderIterator(myBinrayTreeNode *p_root);

#endif // MIRROR_RECURSIVELY_BINARYTREE_H_INCLUDED
