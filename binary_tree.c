#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"binary_tree.h"

#define ZERO 0
#define ONE 1

#define bool char
#define true 1
#define false 0

NODE* minimum_node(NODE* root)
{
    NODE* p = root;
    if(!root)
        return NULL;
    while( p->left )
        p = p->left;
    return p;
}

NODE* maximum_node(NODE* root)
{
    NODE* p = root;
    if(!root)
        return NULL;
    while( p->right )
        p = p->left;
    return p;
}

int tree_search(NODE* node, unsigned int data)
{
    signed int count = 0;
    NODE* p = node;
    while(p)
    {
        if( p->data == data )
        {
            count = p->count;
            break;
        }
        else if(p->data < data)
            p = p->right;
        else
            p = p->left;
    }
    return count;
}

NODE* tree_search_return_node(NODE* node, unsigned int data)
{
    signed int count = 0;
    NODE* p = node;
    while(p)
    {
        if( p->data == data )
        {
            count = p->count;
            break;
        }
        else if(p->data < data)
            p = p->right;
        else
            p = p->left;
    }
    return p;
}

NODE* node_init(unsigned int data)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->depth = ZERO;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->count = ZERO;
    return node;
}

NODE* tree_init(unsigned int* data,size_t size)
{
    if(!data || 0 == size)
        return NULL;
    int* p = data;
    NODE* root = NULL;
    for(int i=0;i<size;i++,p++)
    {
        if(i==0)
        {
            root = node_init(*p);
            root->count = ONE;
        }
        else
            root = tree_add(root,*p);
    }
    return root;
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
        else if( p->data < data )
            p = p->right;
        else
            p = p->left;
    }

    if(is_exists)
        return p;
    else
    {
        NODE* new_node = node_init(data);
        if( this_node->data < data )
            this_node->right = new_node;
        else
            this_node->left = new_node;
        new_node->parent = this_node;
        return new_node;
    }
}

void tree_forward_all(NODE* node)
{
    if(node)
    {
        tree_forward_all(node->left);
        printf("%d",node->data);
        printf("(%d)",node->count);
        printf(",");
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

