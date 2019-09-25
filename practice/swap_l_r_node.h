#ifndef SWAP_L_R_NODE_H_INCLUDED
#define SWAP_L_R_NODE_H_INCLUDED
#define bool char
#define true 1
#define false 0

typedef struct
{
    int* data;
    size_t size;
} tree, *p_tree, **p_p_tree;

void swap_l_r_node(p_p_tree pptree);

void init_node(p_p_tree pptree, int* header, size_t size);

void des_sort(p_p_tree pptree, size_t index_b, size_t index_e);

bool is_nul(p_p_tree pptree);

float my_log(int a, int b);

#endif // SWAP_L_R_NODE_H_INCLUDED
