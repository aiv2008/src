#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include "rbtree.h"
#include "node.h"
#define NIL -50000000

void print_node(NODE* node)
{
    if(NIL != node->data)
    {
        printf("\n  ");
        NODE* p = node->parent;
        NODE* l = node->left;
        NODE* r = node->right;
        if(p)
        {
            printf("%d(",p->data);
            printf("%c)\n",p->color);
        }
        else
            printf("nil\n");
        printf("   |\n");
        printf(" ");
        printf("%d(",node->data);
        printf("%c)\n",node->color);
        printf(" /   \\\n");
        if(NIL != l->data)
        {
            printf("%d(",l->data);
            printf("%c)",l->color);
        }
        else
            printf("nil");
        printf("   ");
        if(NIL != r->data)
        {
            printf("%d(",r->data);
            printf("%c)",r->color);
        }
        else
            printf("nil");
        printf("\n");
    }

}

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

NODE* nil_node_init()
{
    NODE* root = (NODE*)malloc(sizeof(NODE));
    root->data = NIL;
    root->color = 'B';
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
    return root;
}

NODE* tree_init()
{
    return nil_node_init();
}

void recolor(NODE* root)
{
    NODE* p = root;
    while(p->data != NIL)
        p->color = !p->color;
    recolor(p->left);
    recolor(p->right);
}

NODE* tree_search(NODE* root, unsigned int data)
{
    NODE* p = root;
    while( NIL != p->data)
    {
        if(data == p->data)
            break;
        else if(p->data < data)
            p = p->right;
        else
            p = p->left;
    }
    return p;
}

NODE* tree_insert(NODE* root, unsigned int data)
{
    //node is the new added node
    NODE* p = root;
    if(NIL == p->data)
    {
        NODE* node = node_init(data);
        node->left = root;
        NODE* right_nil_node = nil_node_init();
        node->right = right_nil_node;
        root->parent = node;
        right_nil_node->parent = node;
        node->color = 'B';
        root = node;
    }
    else
    {
        p = tree_search(root, data);
        if( NIL != p->data )
            p->count++;
        else
        {
            NODE* node = node_init(data);
            NODE* parent = p->parent;
            node->parent = parent;
            node->left = p;
            p->parent = node;
            NODE* right_nil_node = nil_node_init();
            node->right = right_nil_node;
            right_nil_node->parent = node;
            p = node;
            if(node->data < parent->data)
                parent->left = node;
            else
                parent->right = node;
            while(parent)
            {
                if(!('R' == p->color && parent->color == p->color))
                    break;
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
//                    printf("---before rotate begin---\n");
//                    print_node(node);
//                    print_node(node->left);
//                    print_node(node->right);
//                    printf("---before rotate end---\n");
                    if(parent == parent_parent->left)
                        //if parent is pp`s left child node, then rotate right
                        p = rotate_right(parent);
                    else
                        //if parent is pp`s right child node, then rotate left
                        p = rotate_left(parent);
//                    printf("---after rotate begin---\n");
//                    print_node(p);
//                    print_node(p->left);
//                    print_node(p->right);
//                    printf("---after rotate end---\n");
                    parent = p->parent;
                }
            }
            if(!p->parent && 'R' == p->color)
            {//if root is red, then rotate
                NODE* left = node->left;
                NODE* right = node->right;
                root = node->data < p->data?rotate_right(left):rotate_left(right);
            }
        }
    }
    return p->parent?root:p;
}

NODE* rbtree_minimum(NODE* root)
{
    NODE* p = root;
    while(p->data != NIL)
        p = p->left;
    return p->parent;
}

NODE* rbtree_maximum(NODE* root)
{
    NODE* p = root;
    while(p->data != NIL)
        p = p->right;
    return p->parent;
}

void predecesor(NODE* node)
{
    if(node->data != NIL)
    {
        predecesor(node->right);
        printf("%d(",node->data);
        printf("count:%d,",node->count);
        printf("color:%c),",node->color);
//        print_node(node);
        predecesor(node->left);
    }
}

void predecesor_for_test(NODE* node)
{
    if(node->data != NIL)
    {
        predecesor_for_test(node->right);
        print_node(node);
        predecesor_for_test(node->left);
    }
}

void successor(NODE* node)
{
    if(node->data != NIL)
    {
        successor(node->left);
        printf("%d(",node->data);
        printf("count:%d,",node->count);
        printf("color:%c),",node->color);
        successor(node->right);
    }
}

void successor_for_test(NODE* node)
{
    if(node->data != NIL)
    {
        successor_for_test(node->left);
//        printf("%d(",node->data);
//        printf("count:%d,",node->count);
//        printf("color:%c),",node->color);
        print_node(node);
        successor_for_test(node->right);
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


