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
//    node->balanced_factor = ZERO;
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
    signed balanced_factor = 0;
    while(p)
    {
        NODE* left = p->left;
        NODE* right = p->right;
        p->depth =(!left&&!right)?0:( max(left?left->depth:0,right?right->depth:0)+1);
//        p->balanced_factor = (left?left->depth:-1)-(right?right->depth:-1);
        balanced_factor = (left?left->depth:-1)-(right?right->depth:-1);
//        if( BALANCED_UPPER_BOUND == p->balanced_factor || BALANCED_LOWER_BOUND == p->balanced_factor)break;
        if( BALANCED_UPPER_BOUND == balanced_factor || BALANCED_LOWER_BOUND == balanced_factor)break;
            p = p->parent;
    }
    if(p)
    {
//        if(BALANCED_UPPER_BOUND == p->balanced_factor)
        if(BALANCED_UPPER_BOUND == balanced_factor)
        {
            NODE* left = p->left;
            NODE* left_left = left->left;
            NODE* left_right = left->right;
//            if( BALANCED_UPPER_BOUND_MID == left->balanced_factor )
            signed left_balanced_factor = (left_left?left_left->depth:-1)-(left_right?left_right->depth:-1);
            if( BALANCED_UPPER_BOUND_MID == left_balanced_factor )
                p = rotate_right(left);
            else
            {
                p = rotate_left(left->right);
                p = rotate_right(p);
            }
        }
//        else if(BALANCED_LOWER_BOUND == p->balanced_factor)
        else if(BALANCED_LOWER_BOUND == balanced_factor)
        {
            NODE* right = p->right;
            NODE* right_left = right->left;
            NODE* right_right = right->right;
            signed right_balanced_factor = (right_left?right_left->depth:-1)-(right_right?right_right->depth:-1);
//            if( BALANCED_UPPER_BOUND_MID == right->balanced_factor )
            if( BALANCED_UPPER_BOUND_MID == right_balanced_factor )
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

//        new_node->balanced_factor = ZERO;
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
        NODE* parent = node->parent;
        NODE* left = node->left;
        NODE* right = node->right;
        if(!left)
        {
            if(right)
            {//right replace to the deleted node
                NODE* node_left = node->left;
                NODE* node_right = node->right;
                unsigned int pre_balanced_factor = (node_left?node_left->depth:-1)-(node_right?node_right->depth:-1);
                node->data = right->data;
                node->count = right->count;
                release(right);
                node_left = node->left;
                node_right = node->right;
                unsigned int after_balanced_factor = (node_left?node_left->depth:-1)-(node_right?node_right->depth:-1);
                if(pre_balanced_factor != after_balanced_factor)
                    tree_balanced(node);
            }
            else
                node = release(node);
        }
        else if(!right)
        {
            if(left)
            {//left replace to the deleted node
                NODE* node_left = node->left;
                NODE* node_right = node->right;
                unsigned int pre_balanced_factor = (node_left?node_left->depth:-1)-(node_right?node_right->depth:-1);
                node->data = left->data;
                node->count = left->count;
                release(left);
                node_left = node->left;
                node_right = node->right;
                unsigned int after_balanced_factor = (node_left?node_left->depth:-1)-(node_right?node_right->depth:-1);
                if(pre_balanced_factor != after_balanced_factor)
                    tree_balanced(node);
            }
            else
                node = release(node);
        }
        else
        {
            if(left->depth>=right->depth)
            {//left child node is higher than the right child node
            //fetch the max node of the left child node to replace of the deleted node
                NODE* max_left_node = tree_maximum(left);
                NODE* max_left_node_parent = max_left_node->parent;
//                signed int pre_parent_depth = max_left_node_parent->depth;
                NODE* max_left_node_parent_left = max_left_node_parent->left;
                NODE* max_left_node_parent_right = max_left_node_parent->right;
                unsigned int pre_balanced_factor = (max_left_node_parent_left?max_left_node_parent_left->depth:-1)-(max_left_node_parent_right?max_left_node_parent_right->depth:-1);
                unsigned int data = max_left_node->data;
                unsigned int count = max_left_node->count;
//                node->data = max_left_node->data;
//                node->count = max_left_node->count;
                //use the data of the max node to replace the deleted node,
                //and then release the max node
                max_left_node = release(max_left_node);
                node->data = data;
                node->count = count;
                max_left_node_parent_left = max_left_node_parent->left;
                max_left_node_parent_right = max_left_node_parent->right;
//                signed int after_parent_depth = (!max_left_node_parent_left&&!max_left_node_parent_right)?0:( max(max_left_node_parent_left?max_left_node_parent_left->depth:0,max_left_node_parent_right?max_left_node_parent_right->depth:0)+1);
                unsigned int after_balanced_factor = (max_left_node_parent_left?max_left_node_parent_left->depth:-1)-(max_left_node_parent_right?max_left_node_parent_right->depth:-1);
                //compare the balanced factor of the parent node, if they do not equals to each other,
                //balance the tree
                if(pre_balanced_factor != after_balanced_factor)
                    tree_balanced(max_left_node_parent);
//                root = node;
            }
            else
            {
                NODE* max_right_node = tree_minimum(left);
                NODE* max_right_node_parent = max_right_node->parent;
                NODE* max_right_node_parent_left = max_right_node_parent->left;
                NODE* max_right_node_parent_right = max_right_node_parent->right;
                unsigned int pre_balanced_factor = (max_right_node_parent_left?max_right_node_parent_left->depth:-1)-(max_right_node_parent_right?max_right_node_parent_right->depth:-1);
                unsigned int data = max_right_node->data;
                unsigned int count = max_right_node->count;
                //use the data of the max node to replace the deleted node,
                //and then release the max node
                max_right_node = release(max_right_node);
                node->data = data;
                node->count = count;
                max_right_node_parent_left = max_right_node_parent->left;
                max_right_node_parent_right = max_right_node_parent->right;
                unsigned int after_balanced_factor = (max_right_node_parent_left?max_right_node_parent_left->depth:-1)-(max_right_node_parent_right?max_right_node_parent_right->depth:-1);
                //compare the depth of the parent node, if they do not equals to each other,
                //balance the tree
                if(pre_balanced_factor != after_balanced_factor)
                    tree_balanced(max_right_node_parent);
//                root = node;
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
//    old_root->balanced_factor = (old_root_left?old_root_left->depth:-1) - (old_root_right?old_root_right->depth:-1);
    old_root->parent = root;
    root->left = old_root;
    root_left = root->left;
    NODE* root_right = root->right;
    root->depth = (!root_left&&!root_right)?0:(max(root_left?root_left->depth:0,root_right?root_right->depth:0)+1);
//    root->balanced_factor = (root_left?root_left->depth:-1) - (root_right?root_right->depth:-1);
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
//    old_root->balanced_factor = (old_root_left?old_root_left->depth:-1) - (old_root_right?old_root_right->depth:-1);
    old_root->parent = root;
    root->right = old_root;
    root_right = root->right;
    NODE* root_left = root->left;
    root->depth = (!root_left&&!root_right)?0:( max(root_left?root_left->depth:0,root_right?root_right->depth:0)+1);
//    root->balanced_factor = (root_left?root_left->depth:-1) - (root_right?root_right->depth:-1);
    return root;
}
