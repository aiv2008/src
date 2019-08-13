#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <limits.h>
#include "rbtree.h"
#include "node.h"

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
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
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
    //node is the new added node
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
        p = node;
        if(parent)
        {
            if(node->data<parent->data)
                parent->left = node;
            else
                parent->right = node;
        }
        while(parent)
        {
            if('R' == p->color && parent->color == p->color)
            {
                NODE* parent_parent = parent->parent;
                NODE* uncle = NULL;
                if(parent == parent_parent->left)
                    uncle = parent_parent->right;
                else
                    uncle = parent_parent->left;
                if('R' == uncle->color)
                {
                    parent->color = 'B';
                    parent_parent->color = 'R';
                    uncle->color = 'B';
                    p = parent_parent;
                    parent = parent_parent->parent;
                }
                else
                {
                    if(parent == parent_parent->left)
                        //if parent is pp`s left child node, then rotate right
                        p = rotate_right(parent);
                    else
                        //if parent is pp`s right child node, then rotate left
                        p = rotate_left(parent);
                    parent = p->parent;
                }
            }
            else
                break;
        }
        if(!p->parent && 'R' == p->color)
        {//if root is red, then rotate
            NODE* left = node->left;
            NODE* right = node->right;
            if(UINT_MAX == left->data && UINT_MAX == right->data)
            //if only one root node, color the root with black directly
            {
                node->color = 'B';
                root = node;
            }
            else
                root = node->data < p->data?rotate_right(left):rotate_left(right);
//            if(node->data < p->data)
//                root = rotate_right(p->left);
//            else
//                root = rotate_left(p->right);
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
        rbtree_predecesor(node->right);
        printf("%d(",node->data);
        printf("count:%d,",node->count);
        printf("color:%c),",node->color);
        rbtree_predecesor(node->left);
    }
}

void rbtree_successor(NODE* node)
{
    if(node->data != UINT_MAX)
    {
        rbtree_successor(node->left);
        printf("%d(",node->data);
        printf("count:%d,",node->count);
        printf("color:%c),",node->color);
        rbtree_successor(node->right);
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
        parent->color = 'R';
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
    root->color = 'B';
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
        parent->color = 'R';
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
    root->color = 'B';
    return root;
}


