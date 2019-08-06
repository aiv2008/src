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

NODE* balanced_tree_init(unsigned int* data,size_t size)
{
    if(!data || 0 == size)
        return NULL;
    int* p = data;
    NODE* root = NULL;
    for(int i=0;i<size;i++,p++)
    {
        if(i==0)
        {
            root = balanced_node_init(*p);
            root->count++;
        }
        else
            root = balanced_tree_add(root,*p);
    }
    return root;
}

NODE* tree_balanced(NODE* node)
{
    NODE* p = node;
    while(p)
    {
        NODE* left = p->left;
        NODE* right = p->right;
        p->depth =(!left&&!right)?0:( max(left?left->depth:0,right?right->depth:0)+1);
        p->balanced_factor = (left?left->depth:-1)-(right?right->depth:-1);
        if( BALANCED_UPPER_BOUND == p->balanced_factor || BALANCED_LOWER_BOUND == p->balanced_factor)break;
        p = p->parent;
    }
    if(p)
    {
        if(BALANCED_UPPER_BOUND == p->balanced_factor)
        {
            NODE* left = p->left;
            if( BALANCED_UPPER_BOUND_MID == left->balanced_factor )
                p = rotate_right(left);
            else
            {
                p = rotate_left(left->right);
                p = rotate_right(p);
            }
        }
        else if(BALANCED_LOWER_BOUND == p->balanced_factor)
        {
            NODE* right = p->right;
            if( BALANCED_UPPER_BOUND_MID == right->balanced_factor )
            {
                p = rotate_right(right->left);
                p = rotate_left(p);
            }
            else
                p = rotate_left(right);
        }
    }
    return p;
}

NODE* balanced_tree_add(NODE* root, unsigned int data)
{
    NODE* new_node = tree_add(root,data);
    NODE* p = NULL;
    if(ZERO == new_node->count)//means the node is a new added node
    {

        new_node->balanced_factor = ZERO;
        new_node->count++;
        p = new_node->parent;
//        while(p)
//        {
//            NODE* left = p->left;
//            NODE* right = p->right;
//            p->depth =(!left&&!right)?0:( max(left?left->depth:0,right?right->depth:0)+1);
//            p->balanced_factor = (left?left->depth:-1)-(right?right->depth:-1);
//            if( BALANCED_UPPER_BOUND == p->balanced_factor || BALANCED_LOWER_BOUND == p->balanced_factor)break;
//            p = p->parent;
//        }
//        if(p)
//        {
//            if(BALANCED_UPPER_BOUND == p->balanced_factor)
//            {
//                NODE* left = p->left;
//                if( BALANCED_UPPER_BOUND_MID == left->balanced_factor )
//                    p = rotate_right(left);
//                else
//                {
//                    p = rotate_left(left->right);
//                    p = rotate_right(p);
//                }
//            }
//            else if(BALANCED_LOWER_BOUND == p->balanced_factor)
//            {
//                NODE* right = p->right;
//                if( BALANCED_UPPER_BOUND_MID == right->balanced_factor )
//                {
//                    p = rotate_right(right->left);
//                    p = rotate_left(p);
//                }
//                else
//                    p = rotate_left(right);
//            }
//        }
        p = tree_balanced(p);
    }
    else
        p = new_node;
    return (p&&!p->parent)?p:root;
}


NODE* delete_node(NODE* root, unsigned int data)
{
    NODE* node = tree_search_return_node(root, data);
    if(node)//has found
    {
        NODE* p = NULL;
        if(!node->left&&!node->right)//leave node, delete directly, but must be sure the tree is balanced
        {
            NODE* parent = node->parent;
            if(parent)
            {
                node->parent = NULL;
                if(node->data<parent->data)
                {
                    parent->left = NULL;
                    if(!parent->right)
                    {
                        parent->depth--;
                        parent->balanced_factor = 0;
                    }
                    else
                        parent->balanced_factor--;
                }
                else
                {
                    parent->right = NULL;
                    if(!parent->left)
                    {
                        parent->depth--;
                        parent->balanced_factor = 0;
                    }
                    else
                        parent->balanced_factor++;
                }
                p = tree_balanced(parent);//p is the latest node that isn`t balanced
            }
            else//only one node,all the node has been deleted
            {
                p = NULL;
            }
        }
        else if(!node->right)//have not right child node,but must be sure the tree is balanced
        {
            NODE* parent = node->parent;
            NODE* left = node->left;
            node->parent = NULL;
            node->left = NULL;
            left->parent = parent;
            if(parent)
            {
                if(parent->data<left->data)
                    parent->right = left;
                else
                    parent->left = left;
                p = tree_balanced(parent);
            }
            else//remain one node after deleted
            {
                p = left;
            }
        }
        else if(!node->left)//have not left child node,but must be sure the tree is balanced
        {
            NODE* parent = node->parent;
            NODE* right = node->right;
            node->parent = NULL;
            node->right = NULL;
            right->parent = parent;
            if(parent)
            {
                if(parent->data<right->data)
                    parent->right = right;
                else
                    parent->left = right;
                p = tree_balanced(parent);
            }
            else//remain one node after deleted
            {
                p = right;
            }
        }
        else //left and right child node both exists
        {
            if(node->balanced_factor > 0) // left child node is higher than the right
            {

            }
        }
    }
    return root;
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
