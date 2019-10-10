#include<stdio.h>
#include<stdlib.h>
#include"my_list.h"

my_bool listIsNullOrEmpty(myList** ppMyList)
{
    return !ppMyList || !*ppMyList || !(*ppMyList)->header || !(*ppMyList)->size;
}

my_bool listIsNull(myList** ppMyList)
{
    return !ppMyList || !*ppMyList ;
}

my_bool listIsEmpty(myList** ppMyList)
{
    return !(*ppMyList)->header || !(*ppMyList)->size;
}

void add(myList** ppMyList, void* p_data, int elemSize)
{
    if(!ppMyList)
    {
        printf("pointer of list is null\n");
        return;
    }
    if(!*ppMyList)
    {
//        *ppMyList = (myList*)calloc(1, sizeof(int**) + sizeof(int));
        *ppMyList = (myList*)calloc(1, elemSize + 2*sizeof(int));
        (*ppMyList)->capability = 8;
//        (*ppMyList)->header = (int**)calloc((*ppMyList)->capability, sizeof(int*));
        (*ppMyList)->header = (char*)calloc((*ppMyList)->capability, elemSize);
    }
    if((*ppMyList)->size == (*ppMyList)->capability)
    {
        int capability = (*ppMyList)->capability;
        capability += (capability>>1);
        char* new_header = (char*)calloc(capability, elemSize);
        for(int i=0;i<(*ppMyList)->capability;i++)
        {
            *(new_header + i*elemSize) = *(char*)((*ppMyList)->header + i*elemSize);
        }
        free((*ppMyList)->header);
        (*ppMyList)->header = new_header;
        new_header = '\0';
        (*ppMyList)->capability = capability;
    }
//    *((char*)((*ppMyList)->header) + elemSize * (*ppMyList)->size ) = *(char*)p_data;
//    void* v = (*ppMyList)->header + elemSize * (*ppMyList)->size;
    ((*ppMyList)->header + elemSize * (*ppMyList)->size) = p_data;
//    (*ppMyList)->header + elemSize * (*ppMyList)->size = p_data;
    (*ppMyList)->size++;
}
