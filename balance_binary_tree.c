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
//    printf("new_node===%d",new_node->data);
//    printf("\n");
    NODE* p = NULL;



    if(ZERO == new_node->count)//means the node is a new added node
    {
        if(new_node->data == 5)
            printf("balanced_factor====%d,",new_node->balanced_factor);


        new_node->balanced_factor = ZERO;
        new_node->count++;
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

//    if(p->data == 5)
//    {
//        NODE* p_parent = p->parent;
//        NODE* p_left = p->left;
//        NODE* p_right = p->right;
//        if(p_parent)
//            printf("parent====%d,",p_parent->data);
//        else
//            printf("parent is null");
//        if(p_left)
//            printf("left====%d,",p_left->data);
//        else
//            printf("left is null");
//        if(p_right)
//            printf("right====%d,",p_right->data);
//        else
//            printf("right is null");
//    }
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
    //if the new root has right child node(RR type),then the depth of
    //new left child node should plus two,
    //otherwise, it should plus one
    root->balanced_factor+= right->right?BALANCED_UPPER_BOUND:BALANCED_UPPER_BOUND_MID;
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
    //if the new root has left child node(LL type),then the depth of
    //new right child node should minus two,
    //otherwise, it should minus one
    root->balanced_factor+=left->left?BALANCED_LOWER_BOUND:BALANCED_LOWER_BOUND_MID;
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
