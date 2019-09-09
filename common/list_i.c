#include <stdio.h>
#include <malloc.h>
#include "list_i.h"

void print_list(plist_i list)
{
    for(int i=0;i<list->size;i++)
        printf("%d,", *(list->header+i));
    printf("\n");
}

plist_i list_init(int* a, size_t size)
{
    int* p = a;
    int* header = (int*)malloc(size * sizeof(int));
    plist_i list = (plist_i)malloc(size * sizeof(int) + sizeof(size_t));
    for(int i=0;i<size;i++,p++)
        *(header+i) = *p;
    list->header = header;
    list->size = size;
    return list;
}
