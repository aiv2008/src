#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <limits.h>
#include "rbtree.h"


NODE* node_init(unsigned int data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->count = 1;
    node->color = 'R';
    return node;
}

NODE* tree_init()
{
    NODE* root = (NODE*)malloc(sizeof(NODE));
    root->data = UINT_MAX;
    root->color = 'B';
    return root;
}

void recolor(NODE* root)
{
    NODE* p = root;
    while(p->data != UINT_MAX)
        p->color = !p->color;
    recolor(p->left);
    recolor(p->right);
}

NODE* tree_insert(NODE* root, unsigned int data)
{
    NODE* node = node_init(data);
    NODE* p = root;
    while(p->data != UINT_MAX)
    {
        if(p->data == node->data)
        {
            p->count++;
            break;
        }
        else if(p->data < node->data)
            p = p->right;
        else
            p = p->left;
    }
    if(p->data == UINT_MAX)
    {
        NODE* parent = p->parent;
        node->parent = parent;
        node->left = p;
        node->right = p;
        p->parent = node;
        if(parent)
        {
            if(parent->data < node->data)
                parent->right = node;
            else
                parent->left = node;

            p = node;
            while(parent && parent->color == 'R' && p->color == 'R')
            {
                NODE* parent_parent = parent->parent;
                NODE* uncle_node = NULL;
                if(parent_parent->data < parent->data)
                    uncle_node = parent_parent->left;
                else
                    uncle_node = parent_parent->right;
                //if the color of parent is equals to the uncle`s,
                //then recolor its uncle and all of successor`s color of its uncle
                if(uncle_node->color == parent->color)
                    recolor(uncle_node);
                else
                {

                }
                node = parent_parent;
                parent = node->parent;
            }
        }
        else
        {
            root = node;
        }


    }
    return root;
}

NODE* rbtree_minimum(NODE* root)
{
    NODE* p = root;
    while(p->data != UINT_MAX)
        p = p->left;
    return p->parent;
}

NODE* rbtree_maximum(NODE* root)
{
    NODE* p = root;
    while(p->data != UINT_MAX)
        p = p->right;
    return p->parent;
}

void rbtree_predecesor(NODE* node)
{
    if(node->data != UINT_MAX)
    {
        rbtree_predecesor(node->left);
        printf("%d,",node->data);
        rbtree_predecesor(node->right);
    }
}

void rbtree_successor(NODE* node)
{
    if(node->data != UINT_MAX)
    {
        rbtree_predecesor(node->right);
        printf("%d,",node->data);
        rbtree_predecesor(node->left);
    }
}

NODE* rotate_left(NODE* root)
{
    NODE* old_root = root->parent;
    NODE* parent = old_root->parent;
    root->parent = parent;
    if(parent)
    {
        if(parent->data>root->data)
            parent->left = root;
        else
            parent->right = root;
    }
    NODE* root_left = root->left;
    old_root->right = root_left;
//    if(root_left)
//        root_left->parent = old_root;
    root_left->parent = old_root;
    NODE* old_root_left = old_root->left;
    NODE* old_root_right = old_root->right;
    old_root->parent = root;
    root->left = old_root;
    root_left = root->left;
    NODE* root_right = root->right;
    return root;
}

NODE* rotate_right(NODE* root)
{
    NODE* old_root = root->parent;
    NODE* parent = old_root->parent;
    root->parent = parent;
    if(parent)
    {
        if(parent->data>root->data)
            parent->left = root;
        else
            parent->right = root;
    }
    NODE* root_right = root->right;
    old_root->left = root_right;
//    if(root_right)
//        root_right->parent = old_root;
    root_right->parent = old_root;
    NODE* old_root_left = old_root->left;
    NODE* old_root_right = old_root->right;
    old_root->parent = root;
    root->right = old_root;
    root_right = root->right;
    NODE* root_left = root->left;
    return root;
}

int main(void)
{
    unsigned int i=0;
    i = ~i;//ֱ�Ӱ�ֵȡ��.���Ƕ��������ɱ�ʾ��ֵ
    printf("unsigned int���ֵ:%u\n", UINT_MAX );
    printf("unsigned int��Сֵ:%u\n", i );
    return 0;
}
