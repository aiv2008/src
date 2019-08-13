#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct
{
    unsigned int data;
    unsigned char color;
    unsigned int count;
    struct NODE* parent;
    struct NODE* left;
    struct NODE* right;
} NODE;

#endif // NODE_H_INCLUDED
