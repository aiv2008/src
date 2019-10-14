#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"my_queue.h"
#include"../binary_tree/binary_tree.h"

void queuePush(myQueue** ppMyqueue, void* data, int elemLen)
{
    if(!ppMyqueue)
    {
        printf("function queuePush: queue is null\n");
        return;
    }
    if(!*ppMyqueue)
    {
        *ppMyqueue = (myQueue*)calloc(1, sizeof(void*) + 2 * sizeof(int));
        (*ppMyqueue)->capability = 8;
        (*ppMyqueue)->top = (void*)calloc((*ppMyqueue)->capability, elemLen);
    }
    if((*ppMyqueue)->size == (*ppMyqueue)->capability)
    {
        int capability = (*ppMyqueue)->capability;
        capability += (capability >> 1);
//        int* top = (int*)calloc(capability, sizeof(int));
        char* top = (char*)calloc(capability, elemLen);
        for(int i=0;i<(*ppMyqueue)->size;i++)
        {
            memcpy(top + elemLen * i, (char*)((*ppMyqueue)->top) + elemLen * i, elemLen*i);
        }
        free((*ppMyqueue)->top);
        (*ppMyqueue)->capability = capability;
        (*ppMyqueue)->top = top;
        top = '\0';
    }
    void* newTop = (char*)((*ppMyqueue)->top) +  elemLen * (*ppMyqueue)->size;
    memcpy(newTop, data, elemLen);
    (*ppMyqueue)->size++;
//    printf("queuePush: top=%x\n",(*ppMyqueue)->top);
//    printf("queuePush: top=%x\n",(*ppMyqueue)->top);
}

void* queueTop(myQueue* pMyqueue)
{
    if(!pMyqueue)
    {
        printf("function top: queue is null\n");
        return '\0';
    }
//    return (char*)(pMyqueue->top) + elemLen - sizeof(char*);
    return pMyqueue->top;
}

void queuePop(myQueue* pMyqueue, int elemLen)
{
    if(!pMyqueue||!pMyqueue->capability||!pMyqueue->size)
    {
        printf("function queuePop: queue is null\n");
        return;
    }
//    printf("pop: size==%d\n", pMyqueue->size);
//    printf("pop element is: %d,", *((char*)(pMyqueue->top) + elemLen - sizeof(char*)));
//    pMyqueue->top++;
    pMyqueue->top += elemLen;
    pMyqueue->size--;
    printf("pop successfully\n");
}

void freeQueue(myQueue** ppMyqueue)
{
    if(ppMyqueue)
    {
        free((*ppMyqueue)->top);
        (*ppMyqueue)->top = '\0';
        free(*ppMyqueue);
        printf("queue free successfully\n");
        return;
    }
    printf("function freeQueue: queue is null\n");
}

