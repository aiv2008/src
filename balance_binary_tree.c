#include<stdio.h>
#include "balance_binary_tree.h"

#define ZERO 0
#define BALANCED_UPPER_BOUND_MID 1
#define BALANCED_LOWER_BOUND_MID -1
#define BALANCED_UPPER_BOUND 2
#define BALANCED_LOWER_BOUND -2
#define max(a,b)(a>b?a:b)

NODE* balanced_node_init(unsigned int data)
{
    NODE* node = node_init(data);
    node->balanced_factor = ZERO;
    return node;
}

NODE* balanced_tree_init(unsigned int* data)
{
    if(!data)
        return NULL;
    NODE* root = balanced_node_init(*data);
    printf("root1 equals to :%d\n",root->data);
    unsigned int* p = data;
    p++;
    while(p++)
    {
        printf("p equals to :%d\n",*p);
        root = balanced_tree_add(root,*p);
//        printf("root2 equals to :%d\n",root->data);
    }
    return root;
}

NODE* balanced_tree_add(NODE* root, unsigned int data)
{
    NODE* new_node = tree_add(root,data);
//    printf("new_node===%d",new_node->data);
//    printf("\n");
    NODE* p = NULL;
    if(ZERO == new_node->count)//means the node is a new added node
    {

        new_node->balanced_factor = ZERO;
        new_node->count++;
        p = new_node->parent;
//        printf("new_node===%d(",new_node->data);
//        printf("%d),",new_node->depth);
        while(p)
        {
            NODE* left = p->left;
            NODE* right = p->right;
            p->depth =(!left&&!right)?0:( max(left?left->depth:0,right?right->depth:0)+1);
//            printf("p===%d(",p->data);
//            printf("%d)",p->depth);
//            printf("\n");
            p->balanced_factor = (left?left->depth:-1)-(right?right->depth:-1);
//            printf("p->balanced_factor===%d",p->balanced_factor);
//            printf("\n");
//            if( new_node->data < p->data )
//                p->balanced_factor++;
//            else
//                p->balanced_factor--;
            if( BALANCED_UPPER_BOUND == p->balanced_factor || BALANCED_LOWER_BOUND == p->balanced_factor)break;
            p = p->parent;
        }
        if(p)
        {
            if(BALANCED_UPPER_BOUND == p->balanced_factor)
            {
                NODE* left = p->left;
                if( BALANCED_UPPER_BOUND_MID == left->balanced_factor )
//                    p = rotate_right(p);
                    p = rotate_right(left);
                else
                {
//                    p = rotate_left(p->left);
//                    p = rotate_right(p->parent);
                    p = rotate_left(left->right);
                    p = rotate_right(p);
                }
            }
            else if(BALANCED_LOWER_BOUND == p->balanced_factor)
            {
                NODE* right = p->right;
                if( BALANCED_UPPER_BOUND_MID == right->balanced_factor )
                {
//                    p = rotate_right(p->right);
//                    p = rotate_left(p->parent);
                    p = rotate_right(right->left);
                    p = rotate_left(p);
                }
                else
//                    p = rotate_left(p);
                    p = rotate_left(right);
            }
        }
    }
    else
        p = new_node;
    return (p&&!p->parent)?p:root;
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
    if(root_left)
        root_left->parent = old_root;
    NODE* old_root_left = old_root->left;
    NODE* old_root_right = old_root->right;
    old_root->depth = (!old_root_left&&!old_root_right)?0:( max(old_root_left?old_root_left->depth:0,old_root_right?old_root_right->depth:0)+1);
    old_root->balanced_factor = (old_root_left?old_root_left->depth:-1) - (old_root_right?old_root_right->depth:-1);
    old_root->parent = root;
    root->left = old_root;
    root_left = root->left;
    NODE* root_right = root->right;
    root->depth = (!root_left&&!root_right)?0:(max(root_left?root_left->depth:0,root_right?root_right->depth:0)+1);
    root->balanced_factor = (root_left?root_left->depth:-1) - (root_right?root_right->depth:-1);
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
    if(root_right)
        root_right->parent = old_root;
    NODE* old_root_left = old_root->left;
    NODE* old_root_right = old_root->right;
    old_root->depth = (!old_root_left&&!old_root_right)?0:(max(old_root_left?old_root_left->depth:0,old_root_right?old_root_right->depth:0)+1);
    old_root->balanced_factor = (old_root_left?old_root_left->depth:-1) - (old_root_right?old_root_right->depth:-1);
    old_root->parent = root;
    root->right = old_root;
    root_right = root->right;
    NODE* root_left = root->left;
    root->depth = (!root_left&&!root_right)?0:( max(root_left?root_left->depth:0,root_right?root_right->depth:0)+1);
    root->balanced_factor = (root_left?root_left->depth:-1) - (root_right?root_right->depth:-1);
    return root;
}
