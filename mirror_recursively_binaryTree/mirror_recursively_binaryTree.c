#include<stdio.h>
#include<stdlib.h>
#include"mirror_recursively_binaryTree.h"

void listAdd(myList **ppMyList, myBinrayTreeNode* pMyBinaryTreeNode)
{
    if(!ppMyList)
    {
        printf("pointer of list is null\n");
        return;
    }
    if(!*ppMyList)
    {
        *ppMyList = (myList*)calloc(1, sizeof(myBinrayTreeNode**) + 2*sizeof(int));
        (*ppMyList)->capability = 8;
        (*ppMyList)->header = (myBinrayTreeNode**)calloc((*ppMyList)->capability, sizeof(myBinrayTreeNode*));
    }
    if((*ppMyList)->size == (*ppMyList)->capability)
    {
        int capability = (*ppMyList)->capability;
        capability += (capability>>1);
        myBinrayTreeNode** new_header = (unsigned int**)calloc(capability, sizeof(myBinrayTreeNode*));
        for(int i=0;i<(*ppMyList)->capability;i++)
        {
            *(new_header + i) = *((*ppMyList)->header + i);
        }
        free((*ppMyList)->header);
        (*ppMyList)->header = new_header;
        new_header = '\0';
        (*ppMyList)->capability = capability;
    }
    *((*ppMyList)->header +  (*ppMyList)->size) = pMyBinaryTreeNode;
    (*ppMyList)->size++;
}

void add(myBinrayTreeNode **pp_root, unsigned int data)
{
    if(!pp_root)
    {
        printf("binary tree pointer is null\n");
        return;
    }
    if(!*pp_root)
    {
        *pp_root = (myBinrayTreeNode*)calloc(1, 3*sizeof(myBinrayTreeNode*) + sizeof(unsigned int));
        (*pp_root)->left = '\0';
        (*pp_root)->right = '\0';
        (*pp_root)->parent = '\0';
        (*pp_root)->data = data;
    }
    else
    {
        myBinrayTreeNode* p_move = *pp_root;
        myBinrayTreeNode* p_parentMove = '\0';
        while(p_move)
        {
            p_parentMove = p_move;
            if(data <= p_move->data)
                p_move = p_move->left;
            else
                p_move = p_move->right;
        }
        p_move = (myBinrayTreeNode*)calloc(1, 3*sizeof(myBinrayTreeNode*) + sizeof(unsigned int));
        p_move->left = '\0';
        p_move->right = '\0';
        p_move->parent = '\0';
        p_move->data = data;
        p_move->parent = p_parentMove;
        if(p_move->data <= p_parentMove->data)
            p_parentMove->left = p_move;
        else
            p_parentMove->right = p_move;
    }
}

BOOL binaryTreeIsNullOrEmpty(myBinrayTreeNode **pp_root)
{
    return !pp_root || !*pp_root;
}

void preOrderIterator(myBinrayTreeNode *p_root)
{
    if(p_root)
    {
        printf("%d,", p_root->data);
        preOrderIterator(p_root->left);
        preOrderIterator(p_root->right);
    }
}

void inOrderIterator(myBinrayTreeNode *p_root)
{
    if(p_root)
    {
        inOrderIterator(p_root->left);
        printf("%d,", p_root->data);
        inOrderIterator(p_root->right);
    }
}

void postOrderIterator(myBinrayTreeNode *p_root)
{
    if(p_root)
    {
        postOrderIterator(p_root->left);
        postOrderIterator(p_root->right);
        printf("%d,", p_root->data);
    }
}

void mirrorRecursively(myBinrayTreeNode *p_root)
{
    if(p_root)
    {
        myBinrayTreeNode* left = p_root->left;
        myBinrayTreeNode* right = p_root->right;
        p_root->right = left;
        p_root->left = right;
        if(left)mirrorRecursively(left);
        if(right)mirrorRecursively(right);
    }
}



void mirrorLooply(myBinrayTreeNode *p_root)
{
    if(p_root && (p_root->left || p_root->right))
    {
        //用一个list保存父节点的指针, 初始化长度为8
        myList **ppMyList = (myList **)calloc(1, sizeof(myList *));
        listAdd(ppMyList, p_root);
        for(int i=0; i<(*ppMyList)->size; i++)
        {
            myBinrayTreeNode* node = *((*ppMyList)->header + i);
            myBinrayTreeNode* left = node->left ;
            myBinrayTreeNode* right = node->right;
            if(left && (left->left||left->right))listAdd(ppMyList, left);
            if(right && (right->left||right->right))listAdd(ppMyList, right);
            node->right = left;
            node->left = right;
        }

    }
}
