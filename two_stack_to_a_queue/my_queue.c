#include<stdio.h>
#include "../stack/my_stack.h"
#include "my_queue.h"
#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL queueIsNillOrEmpty(pp_myQueue ppmyQueue)
{
    return !ppmyQueue || !(*ppmyQueue) || stackIsNillOrEmpty((*ppmyQueue)->stack_a) || stackIsNillOrEmpty((*ppmyQueue)->stack_b);
}

BOOL queueIsNill(pp_myQueue ppmyQueue)
{
    return !ppmyQueue || !(*ppmyQueue);
}

BOOL queueIsEmpty(pp_myQueue ppmyQueue)
{
    return stackIsNillOrEmpty((*ppmyQueue)->stack_a) || stackIsNillOrEmpty((*ppmyQueue)->stack_b);
}

void q_push(pp_myQueue ppmyQueue, int data)
{
    if(!ppmyQueue)
    {
        printf("p pointer cannot be null!!\n");
        return;
    }
    if(!*ppmyQueue)
    {
        *ppmyQueue = (p_myQueue)calloc(2, sizeof(pp_myStack));
        (*ppmyQueue)->stack_a = (pp_myStack)calloc(1, sizeof(p_myStack));
        (*ppmyQueue)->stack_b = (pp_myStack)calloc(1, sizeof(p_myStack));
    }
    push((*ppmyQueue)->stack_a, data);
}

int* q_top(pp_myQueue ppmyQueue)
{
    if(queueIsNillOrEmpty(ppmyQueue) || stackIsNillOrEmpty((*ppmyQueue)->stack_b))
        return NULL;
    return top((*ppmyQueue)->stack_b);
}

void q_pop(pp_myQueue ppmyQueue)
{
    if(queueIsNill(ppmyQueue))
    {
        printf("queue is nil\n");
        return;
    }
    if(stackIsNillOrEmpty((*ppmyQueue)->stack_b))
    {
        if(stackIsNillOrEmpty((*ppmyQueue)->stack_a))
        {
            printf("queue is empty\n");
            return;
        }
        else
        {
            int size = (*(*ppmyQueue)->stack_a)->size;
//            printStack((*ppmyQueue)->stack_a);
            for(int i=0;i<size;i++)
            {
                int* p_top = top((*ppmyQueue)->stack_a);
                printf("p_top=%d,",*p_top);
                push((*ppmyQueue)->stack_b, *p_top);
                pop((*ppmyQueue)->stack_a);
            }
            printf("\n");
        }
    }
    pop((*ppmyQueue)->stack_b);
}

void freeQueue(pp_myQueue ppmyQueue)
{
    if(queueIsNill(ppmyQueue))
    {
        freeStack((*ppmyQueue)->stack_a);
        freeStack((*ppmyQueue)->stack_b);
        (*ppmyQueue)->stack_a = NULL;
        (*ppmyQueue)->stack_b = NULL;
        free(*ppmyQueue);
        *ppmyQueue = NULL;
        free(ppmyQueue);
    }
}

void printQueue(pp_myQueue ppmyQueue)
{
    if(queueIsNill(ppmyQueue))
    {
        printf("queue is null\n");
        return;
    }
    if(stackIsNillOrEmpty((*ppmyQueue)->stack_a))
    {
        printf("stack_a is null\n");
        return;
    }
    else
    {
        printStack((*ppmyQueue)->stack_a);
    }

    if(stackIsNillOrEmpty((*ppmyQueue)->stack_b))
    {
        printf("stack_b is null\n");
        return;
    }
    else
    {
        printStack((*ppmyQueue)->stack_b);
    }
}
