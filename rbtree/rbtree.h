#ifndef RBTREE_H_INCLUDED
#define RBTREE_H_INCLUDED

typedef struct
{
	unsigned int data;
	struct NODE* parent;
	struct NODE* left;
	struct NODE* right;
	char color;
	int count;
} NODE;

void print_node(NODE* node);

NODE* node_init(unsigned int data);

NODE* nil_node_init();

NODE* tree_search(NODE* root, unsigned int data);

NODE* tree_insert(NODE** ppRoot, unsigned int data);

NODE* tree_delete(NODE* root, unsigned int data);

NODE* rbtree_minimum(NODE* root);

NODE* rbtree_maximum(NODE* root);

void predecesor(NODE* node);

void predecesor_for_test(NODE* node);

void successor(NODE* node);

void successor_for_test(NODE* node);

NODE* rotate_left(NODE* root);

NODE* rotate_right(NODE* root);

void node_rela_save(NODE* parent, NODE* child, unsigned char lof);

NODE* tree_rb_fixup(NODE* node);

NODE* release(NODE* node);

#endif
