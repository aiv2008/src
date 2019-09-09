#ifndef LIST_I_H_INCLUDED
#define LIST_I_H_INCLUDED

typedef struct
{
    size_t size;
    int* header;
} list_i, *plist_i;

plist_i list_init(int* a, size_t size);

void print_list(plist_i list);

#endif // LIST_I_H_INCLUDED
