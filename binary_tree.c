#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"binary_tree.h"

#define ZERO 0
#define ONE 1

#define bool char
#define true 1
#define false 0

void tree_search(NODE* node, unsigned int data)
{
    if(node)
    {
        if( node->data == data )
            printf("data:%d has been found! the depth of the data is %d", node->data, node->depth);
        else if(node->data > data)
            tree_search(node->left, data);
        else
            tree_search(node->right, data);
    }
}

NODE* node_init(unsigned int data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->depth = ZERO;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->count = ONE;
    return node;
}

NODE* tree_add(NODE* root, unsigned int data)
{
    NODE* p = root;
    NODE* this_node = NULL;
    bool is_exists = false;//check if it is a exist node
    while(p)
    {
        this_node = p;
        if(data == p->data)
        {
            p->count++;
            is_exists = true;
            break;
        }
        else if( p->data <= data )
            p = p->right;
        else
            p = p->left;
    }

    if(is_exists)
        return p;
    else
    {
        NODE* new_node = node_init(data);
        if( this_node->data <= data )
            this_node->right = new_node;
        else
            this_node->left = new_node;
        new_node->parent = this_node;
        new_node->depth = ++this_node->depth;
        return new_node;
    }
}

NODE* tree_minimum(NODE* root)
{
    NODE* p = root;
    if(!root)
        return NULL;
    while( p->left )
        p = p->left;
    return p;
}

NODE* tree_maximum(NODE* root)
{
    NODE* p = root;
    if(!root)
        return NULL;
    while( p->right )
        p = p->left;
    return p;
}

void tree_forward_all(NODE* node)
{
    if(node)
    {
        tree_forward_all(node->left);
//        printf("%d",node->data);
//        printf("(%d)",node->count);
//        printf(",");

        NODE* left = node->left;
        NODE* right = node->right;
        NODE* parent = node->parent;
        printf("this===%d",node->data);
        printf("(%d),",node->count);
        if(parent)
            printf("parent===%d,",parent->data);
        else
            printf("parent===null,");
        if(left)
            printf("left===%d,",left->data);
        else
            printf("left===null,");
        if(right)
            printf("right===%d,",right->data);
        else
            printf("right===null,");
        printf("\n");
        tree_forward_all(node->right);
    }
}

void tree_backward_all(NODE* node)
{
    if(node)
    {
        tree_backward_all(node->right);
        printf("%d",node->data);
        printf("(%d)",node->count);
        printf(",");
        tree_backward_all(node->left);
    }
}

