#ifndef INTERVAL_TREE_H_INCLUDED
#define INTERVAL_TREE_H_INCLUDED

typedef struct
{
    int low;
    int hight;
    struct p_int_node parent;
    struct p_int_node left;
    struct p_int_node right;

} int_node, *p_int_node;

/**
**
**/
void interval_insert(p_int_node header, p_int_node node);

void interval_delete(p_int_node header, p_int_node node);

p_int_node interval_search(p_int_node header, p_int_node node);

#endif // INTERVAL_TREE_H_INCLUDED
