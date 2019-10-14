#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"

void binaryTreeAdd(myBinrayTreeNode **pp_root, unsigned int data)
{
    if(!pp_root)
    {
        printf("binary tree pointer is null\n");
        return;
    }
    if(!*pp_root)
    {
        *pp_root = (myBinrayTreeNode*)calloc(1, 3*sizeof(myBinrayTreeNode*) + sizeof(int));
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
        p_move = (myBinrayTreeNode*)calloc(1, 3*sizeof(myBinrayTreeNode*) + sizeof(int));
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

void binaryTreePreOrderIterator(myBinrayTreeNode *p_root)
{
    if(p_root)
    {
        printf("%d,", p_root->data);
        binaryTreePreOrderIterator(p_root->left);
        binaryTreePreOrderIterator(p_root->right);
    }
}

void binaryTreeInOrderIterator(myBinrayTreeNode *p_root)
{
    if(p_root)
    {
        binaryTreeInOrderIterator(p_root->left);
        printf("%d,", p_root->data);
        binaryTreeInOrderIterator(p_root->right);
    }
}

void binaryTreePostOrderIterator(myBinrayTreeNode *p_root)
{
    if(p_root)
    {
        binaryTreePostOrderIterator(p_root->left);
        binaryTreePostOrderIterator(p_root->right);
        printf("%d,", p_root->data);
    }
}

void freeBinaryTree(myBinrayTreeNode **ppRoot)
{
    if(*ppRoot)
    {
        free((*ppRoot)->parent);
        free((*ppRoot)->left);
        free((*ppRoot)->right);
        (*ppRoot)->parent = '\0';
        (*ppRoot)->left = '\0';
        (*ppRoot)->right = '\0';
    }
}

