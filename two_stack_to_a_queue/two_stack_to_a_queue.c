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
//    printf("capacity=%d,",(*ppmystack)->capacity);
//    printf("size=%d\n",(*ppmystack)->size);
    if((*ppmystack)->size == (*ppmystack)->capacity)
    {//extend the capacity if the size is out of the capacity,
    //and copy the array to another memory
        printf("stack is extent now!!\n");
        int capacity = (*ppmystack)->capacity;
        (*ppmystack)->capacity = capacity + capacity >>1;
        int* p = (*ppmystack)->header;
        (*ppmystack)->header = (int *)calloc((*ppmystack)->capacity, sizeof(int));
        for(int i=0;i<capacity;i++,p++)
            *((*ppmystack)->header+i) = *p;
        free(p);
        p = NULL;
    }
    int* p_next = ((*ppmystack)->header + (*ppmystack)->size);
    *p_next = data;
    (*ppmystack)->size++;
}

void pop(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        free((*ppmystack)->header);
        (*ppmystack)->header = NULL;
        printf("stack is empty!!!");
        return;
    }
    int* header = top(ppmystack);
    (*ppmystack)->header++;
    (*ppmystack)->size--;
}

int* top(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack cannot be null111\n");
        return NULL;
    }
    return (*ppmystack)->header;
}

bool stackIsNillOrEmpty(pp_myStack ppmystack)
{
    if(!ppmystack)printf("null1111\n");
    if(!(*ppmystack))printf("null2222\n");
//    if(!(*ppmystack)->capacity)printf("null333\n");
    return !ppmystack||!(*ppmystack)||!(*ppmystack)->capacity||!(*ppmystack)->size;
}

void printStack(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack cannot be null222\n");
        return;
    }
    else
    {
        for(int i=0;i<(*ppmystack)->size;i++)
        {
            printf("memory=%d,",((*ppmystack)->header+i));
            printf("data=%d\n",*((*ppmystack)->header+i));
        }
        printf("\n");
    }

}


