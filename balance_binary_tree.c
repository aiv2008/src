#include<stdio.h>
#include "balance_binary_tree.h"

#define ZERO 0
#define BALANCED_UPPER_BOUND_MID 1
#define BALANCED_LOWER_BOUND_MID -1
#define BALANCED_UPPER_BOUND 2
#define BALANCED_LOWER_BOUND -2

NODE* balanced_node_init(unsigned int data)
{
    NODE* node = node_init(data);
    node->balanced_factor = ZERO;
    return node;
}

NODE* balanced_tree_add(NODE* root, unsigned int data)
{
    NODE* new_node = tree_add(root,data);

    printf("new_node===%d",new_node->data);

    printf("\n");

    NODE* p = NULL;

    if(ZERO == new_node->count)//means the node is a new added node
    {
        new_node->balanced_factor = ZERO;
        p = new_node->parent;
        while(p)
        {
            if( new_node->data < p->data )
                p->balanced_factor++;
            else
                p->balanced_factor--;
            if( BALANCED_UPPER_BOUND == p->balanced_factor || BALANCED_LOWER_BOUND == p->balanced_factor)break;
            p = p->parent;
        }
        if(p)
        {
            if(BALANCED_UPPER_BOUND == p->balanced_factor)
            {
                NODE* left = p->left;
                if( BALANCED_UPPER_BOUND_MID == left->balanced_factor )
                    p = rotate_right(p);
                else
                {
                    p = rotate_left(p->left);
                    p = rotate_right(p->parent);
                }
            }
            else if(BALANCED_LOWER_BOUND == p->balanced_factor)
            {
                NODE* right = p->right;
                if( BALANCED_UPPER_BOUND_MID == right->balanced_factor )
                {
                    p = rotate_right(p->right);
                    p = rotate_left(p->parent);
                }
                else
                    p = rotate_left(p);
            }
        }
    }
    else
        p = new_node;

//    printf("data===%d",(p&&!p->parent)?(p->data):(root->data));
//    printf("\n");

    if(!p)
        printf("p is null\n");
    else
    {
        NODE* left = p->left;
        NODE* right = p->right;
        NODE* parent = p->parent;
        if(left)
        {
            printf("left===%d",left->data);
            printf("(%d),",left->balanced_factor);
        }
        else
            printf("left is null,");
        if(right)
            {
            printf("right===%d",right->data);
            printf("(%d),",right->balanced_factor);
        }
        else
            printf("right is null,");
        if(parent)
            {
            printf("parent===%d",parent->data);
            printf("(%d),",parent->balanced_factor);
        }
        else
            printf("parent is null,");
    }


    return (p&&!p->parent)?p:root;
}

NODE* rotate_left(NODE* root)
{
    NODE* parent = root->parent;
    NODE* right = root->right;
    root->parent = right;
    root->right = right->left;
    right->parent = parent;
    right->left = root;
    root->balanced_factor+=BALANCED_UPPER_BOUND;
    right->balanced_factor++;
    if(parent)
    {
        if(parent->data>right->data)
            parent->left = right;
        else
            parent->right = right;
    }
    return right;
}

NODE* rotate_right(NODE* root)
{
    NODE* parent = root->parent;
    NODE* left = root->left;
    root->parent = left;
    root->left = left->right;
    left->parent = parent;
    left->right = root;
    root->balanced_factor+=BALANCED_LOWER_BOUND;
    left->balanced_factor--;
    if(parent)
    {
        if(parent->data>left->data)
            parent->left = left;
        else
            parent->right = left;
    }
    return left;
}
