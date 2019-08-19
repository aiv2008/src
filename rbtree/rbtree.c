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

//void recolor(NODE* root)
//{
//    NODE* p = root;
//    while(p->data != NIL)
//        p->color = !p->color;
//    recolor(p->left);
//    recolor(p->right);
//}

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
//        node->left = root;
//        root->parent = node;
        node_rela_save(node, root, 'l');
        NODE* right_nil_node = nil_node_init();
//        node->right = right_nil_node;
//        right_nil_node->parent = node;
        node_rela_save(node, right_nil_node, 'r');
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
//            node->parent = parent;
//            if(node->data < parent->data)
//                parent->left = node;
//            else
//                parent->right = node;
            node_rela_save(parent, node, node->data < parent->data?'l':'r');
//            node->left = p;
//            p->parent = node;
            node_rela_save(node, p, 'l');
            NODE* right_nil_node = nil_node_init();
//            node->right = right_nil_node;
//            right_nil_node->parent = node;
            node_rela_save(node, right_nil_node, 'r');
//            p = node;
            p = tree_rb_fixup(node);
//            while(parent)
//            {
//                if(!('R' == p->color && parent->color == p->color))
//                    break;
//                NODE* parent_parent = parent->parent;
//                NODE* uncle = NULL;
//                if(parent == parent_parent->left)
//                    uncle = parent_parent->right;
//                else
//                    uncle = parent_parent->left;
//                if('R' == uncle->color)
//                {
//                    parent->color = 'B';
//                    parent_parent->color = 'R';
//                    uncle->color = 'B';
//                    p = parent_parent;
//                    parent = parent_parent->parent;
//                }
//                else
//                {
//                    if(parent == parent_parent->left)
//                        //if parent is pp`s left child node, then rotate right
//                        p = p == parent->left?rotate_right(parent):rotate_right(rotate_left(p));
//                    else
//                        //if parent is pp`s right child node, then rotate left
//                        p = p == parent->left?rotate_left(rotate_right(p)):rotate_left(parent);
//                    parent = p->parent;
//                }
//            }
            if(!p->parent && 'R' == p->color)//if root is red, then rotate
                p->color = 'B';
        }
    }
    return p->parent?root:p;
}

NODE* tree_delete(NODE* root, unsigned int data)
{
    NODE* node = tree_search(root, data);
    if( NIL != node->data )
    {
        NODE* left = node->left;
        NODE* right = node->right;
        NODE* p = NULL;
        if( NIL != left->data )
        {
            NODE* p = rbtree_maximum(left);
            node->data = p->data;
            node->count = p->count;
            node = p;
        }
        else if(NIL != right->left)
        {
            NODE* p = rbtree_minimum(right);
            node->data = p->data;
            node->count = p->count;
            node = p;
        }
        //now , parameter "node" is the node being deleted
        NODE* parent = node->parent;
        if( 'R' == node->color )
        {
            //delete the node directly
            node_rela_save(parent, node->left, 'l');
            release(node->right);
            release(node);
        }
        else
        {
            parent->color = 'B';
            NODE* brother = node == parent->left?parent->right : parent->left;
            brother = 'R';
            //delete the node: begin
            node_rela_save(parent, node->left, 'l');
            release(node->right);
            release(node);
            //delete the node: end
            NODE* brother_left = brother->left;
            NODE* brother_right = brother->right;
            if(NIL != brother_left->data)
                p = tree_rb_fixup(brother_left);
            else if( NIL != brother_right->data )
                p = tree_rb_fixup(brother_right);
//            else

        }
    }
    return root;
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
    NODE* left = root->left;
    NODE* right = root->right;
    if( NIL != left->data || NIL != right->data)
    {
        root->color = 'B';
        old_root->color = 'R';
    }
//    root->parent = parent;
//    if(parent)
//    {
//        if(root->data < parent->data)
//            parent->left = root;
//        else
//            parent->right = root;
//    }
    node_rela_save(parent, root, parent?(root->data < parent->data?'l':'r') : ' ');
//    old_root->parent = root;
//    root->left = old_root;
    node_rela_save(root, old_root, 'l');
//    old_root->right = left;
//    left->parent = old_root;
    node_rela_save(old_root, left, 'r');
    return root;
}

NODE* rotate_right(NODE* root)
{
    NODE* old_root = root->parent;
    NODE* parent = old_root->parent;
    NODE* left = root->left;
    NODE* right = root->right;
    if( NIL != left->data || NIL != right->data)
    {
        root->color = 'B';
        old_root->color = 'R';
    }
//    root->parent = parent;
//    if(parent)
//    {
//        if(root->data < parent->data)
//            parent->left = root;
//        else
//            parent->right = root;
//    }
    node_rela_save(parent, root, parent?(root->data < parent->data?'l':'r') : ' ');
//    old_root->parent = root;
//    root->right = old_root;
    node_rela_save(root, old_root, 'r');
//    old_root->left = right;
//    right->parent = old_root;
    node_rela_save(old_root, right, 'l');
    return root;
}

void node_rela_save(NODE* parent, NODE* child, unsigned char lof)
{
    child->parent = parent;
    if(parent)
        if('l' == lof)
            parent->left = child;
        else if('r' == lof)
            parent->right = child;
}

NODE* tree_rb_fixup(NODE* node)
{
    NODE* p = node;
    NODE* parent = node->parent;
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
            if(parent == parent_parent->left)
                //if parent is pp`s left child node, then rotate right
                p = p == parent->left?rotate_right(parent):rotate_right(rotate_left(p));
            else
                //if parent is pp`s right child node, then rotate left
                p = p == parent->left?rotate_left(rotate_right(p)):rotate_left(parent);
            parent = p->parent;
        }
    }
    return p;
}

NODE* release(NODE* node)
{
    NODE* parent = node->parent;
    if(parent)
    {
        if(parent->data<=node->data)
            parent->right = NULL;
        else
            parent->left = NULL;
        node->parent = NULL;
    }
    node->left = NULL;
    node->right = NULL;
    free(node);
    return node = NULL;
}
