#include<stdio.h>
#include<stdlib.h>
#include"my_stack.h"
#define BOOL int
#define TRUE 1
#define FALSE 0

void push(pp_myStack ppmystack, int data)
{
    if(!ppmystack)
    {
        printf("ppmystack cannot be null\n");
        return;
    }
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
//        free((*ppmystack)->header);
//        (*ppmystack)->header = NULL;
        printf("stack is empty!!!\n");
        return;
    }
    int* header = top(ppmystack);
    printf("pop element is %d\n",*header);
//    (*ppmystack)->header--;
    (*ppmystack)->size--;
}

int* top(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack is null111\n");
        return NULL;
    }
//    return NULL;
    return (*ppmystack)->header+(*ppmystack)->size-1;
}

BOOL stackIsNillOrEmpty(pp_myStack ppmystack)
{
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
//            printf("memory=%d,",((*ppmystack)->header+i));
            printf("data=%d,",*((*ppmystack)->header+i));
        }
        printf("\n");
    }

}

void freeStack(pp_myStack ppmystack)
{
    if(ppmystack&&*ppmystack)
    {
        free((*ppmystack)->header);
        (*ppmystack)->header = NULL;
        free(*ppmystack);
        *ppmystack = NULL;
        free(ppmystack);
        printf("stack has been release!!\n");
    }
    return ;
}

