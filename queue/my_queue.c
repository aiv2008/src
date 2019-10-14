#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"my_queue.h"

void queuePush(myQueue** ppMyqueue, void* data, int elemLen)
{
    if(!ppMyqueue)
    {
        printf("function queuePush: queue is null\n");
        return;
    }
    if(!*ppMyqueue)
    {
//        *ppMyqueue = (myQueue*)calloc(1, sizeof(int*)+ 2 * sizeof(int));
        *ppMyqueue = (myQueue*)calloc(1, sizeof(void*) + 2 * sizeof(int));
        (*ppMyqueue)->capability = 8;
//        (*ppMyqueue)->top = (int*)calloc((*ppMyqueue)->capability, sizeof(int));
        (*ppMyqueue)->top = (void*)calloc((*ppMyqueue)->capability, elemLen);
    }
//    char* queueTop = (char*)((*ppMyqueue)->top);
    if((*ppMyqueue)->size == (*ppMyqueue)->capability)
    {
        int capability = (*ppMyqueue)->capability;
        capability += (capability >> 1);
//        int* top = (int*)calloc(capability, sizeof(int));
        char* top = (char*)calloc(capability, elemLen);
        for(int i=0;i<(*ppMyqueue)->size;i++)
        {
//            *(top + i) = *((*ppMyqueue)->top + i);
            *(top + elemLen * i) = *((char*)((*ppMyqueue)->top) + elemLen * i);
        }
        free((*ppMyqueue)->top);
        (*ppMyqueue)->capability = capability;
        (*ppMyqueue)->top = top;
        top = '\0';
    }
    *((char*)((*ppMyqueue)->top) + elemLen * (*ppMyqueue)->size) = *(char*)data;
//    *((*ppMyqueue)->top + (*ppMyqueue)->size) = data;
    printf("push elem===%d\n", *((char*)((*ppMyqueue)->top) + elemLen * (*ppMyqueue)->size));
    (*ppMyqueue)->size++;
}

int* top(myQueue* pMyqueue)
{
    if(!pMyqueue)
    {
        printf("function top: queue is null\n");
        return '\0';
    }
    return pMyqueue->top;
}

void queuePop(myQueue* pMyqueue, int elemLen)
{
    if(!pMyqueue||!pMyqueue->capability||!pMyqueue->size)
    {
        printf("function queuePop: queue is null\n");
        return;
    }
    printf("pop: size==%d\n", pMyqueue->size);
    printf("pop element is: %d,", *((char*)pMyqueue->top));
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

int main(void)
{
    srand(time(0));
    int size = 9;
    int a[size];

    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,", a[i]);
    }
    printf("\n");
    myQueue** ppMyqueue = (myQueue**)calloc(1, sizeof(myQueue*));
//myQueue** ppMyqueue = '\0';
    for(int i=0;i<size;i++)
    {
        queuePush(ppMyqueue, &a[i], sizeof(int));
    }
    printf("push finished\n");

    while(ppMyqueue && (*ppMyqueue) && (*ppMyqueue)->size)
    {
        queuePop(*ppMyqueue, sizeof(int));
    }
//    freeQueue(ppMyqueue);
//    ppMyqueue = '\0';
    return 0;
}
