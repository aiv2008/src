#include<stdio.h>
#include<stdlib.h>
#include"two_stack_to_a_queue.h"
#define bool char
#define true 1
#define false 0

void push(pp_myStack ppmystack, int data)
{
    if(!ppmystack)printf("ppmystack cannot be null");
    if(!(*ppmystack))
    {
        *ppmystack = (p_myStack)calloc(1, sizeof(int*) + 2*sizeof(int));
        (*ppmystack)->capacity = 8;
        (*ppmystack)->size = 0;
        (*ppmystack)->header = (int*)calloc((*ppmystack)->capacity, sizeof(int));
    }
    if((*ppmystack)->size == (*ppmystack)->capacity)
    {//extend the capacity if the size is out of the capacity,
    //and copy the array to another memory
        int capacity = (*ppmystack)->capacity;
        (*ppmystack)->capacity = capacity + capacity >>1;
        int new_array[(*ppmystack)->capacity];
        int* p = (*ppmystack)->header;
        for(int i=0;i<(*ppmystack)->size;i++,p++)
            new_array[i] = *p;
        free((*ppmystack)->header);
        (*ppmystack)->header = new_array;
    }
    int* p_next = ((*ppmystack)->header + (*ppmystack)->size);
    *p_next = data;
    (*ppmystack)->size++;
}

void pop(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack cannot be null");
        return;
    }
    int* header = top(ppmystack);
    printf("before top addr=%d\n", header);
    printf("before top=%d\n", *header);
    (*ppmystack)->header++;
    (*ppmystack)->size--;
    free(header);
    printf("after top addr=%d\n", (*ppmystack)->header);
    printf("after top=%d\n", *((*ppmystack)->header));
}

int* top(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack cannot be null");
        return NULL;
    }
    return (*ppmystack)->header;
}

bool stackIsNillOrEmpty(pp_myStack ppmystack)
{
    return !ppmystack||!(*ppmystack)||!(*ppmystack)->capacity||!(*ppmystack)->size;
//    return !pptree||!(*pptree)||!(*pptree)->data||!(*pptree)->size;
}

void printStack(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack cannot be null");
        return;
    }
    for(int i=0;i<(*ppmystack)->size;i++)
    {
        printf("memory=%d,",((*ppmystack)->header+i));
        printf("data=%d\n",*((*ppmystack)->header+i));
    }
    printf("\n");
}


