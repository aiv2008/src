#ifndef SWAP_L_R_NODE_H_INCLUDED
#define SWAP_L_R_NODE_H_INCLUDED

typedef struct
{
    int* data;
    size_t size;
} tree, *p_tree, **p_p_tree;

void swap_l_r_node(p_p_tree tree_param);

void init_node(p_p_tree pptree, int* header, size_t size);

#endif // SWAP_L_R_NODE_H_INCLUDED
