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
    (*ppmystack)->size++;
    *((*ppmystack)->header + (*ppmystack)->size) = data;
}

void pop(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack cannot be null");
        return;
    }
    int* header = top(ppmystack);
    (*ppmystack)->header++;
    free(header);
}

int* top(pp_myStack ppmystack)
{
    if(stackIsNillOrEmpty(ppmystack))
    {
        printf("stack cannot be null");
        return;
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
        printf("%d,",*((*ppmystack)->header+i));
    }
    printf("\n");
}

int main(void)
{
    int a[] = {4,6,8,89,3,2,4,5};
    pp_myStack ppmystack = (pp_myStack)calloc(1, sizeof(p_myStack));
    for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++)
        push(ppmystack, a[i]);
    printStack(ppmystack);
    return 0;
}
