#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"my_queue.h"

void queuePush(myQueue** ppMyqueue, int data)
{
    if(!ppMyqueue)
    {
        printf("function queuePush: queue is null\n");
        return;
    }
    if(!*ppMyqueue)
    {
        *ppMyqueue = (myQueue*)calloc(1, sizeof(int*)+sizeof(int));
        (*ppMyqueue)->capability = 8;
        (*ppMyqueue)->top = (int*)calloc((*ppMyqueue)->capability, sizeof(int));
    }
    if((*ppMyqueue)->size == (*ppMyqueue)->capability)
    {
        int capability = (*ppMyqueue)->capability;
        capability += (capability >> 1);
        int* top = (int*)calloc(capability, sizeof(int));
        for(int i=0;i<(*ppMyqueue)->size;i++)
            *(top + i) = *((*ppMyqueue)->top + i);
        free((*ppMyqueue)->top);
        (*ppMyqueue)->top = top;
        top = '\0';
    }
    *((*ppMyqueue)->top + (*ppMyqueue)->size) = data;
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

void queuePop(myQueue* pMyqueue)
{
    if(!pMyqueue||!pMyqueue->capability||!pMyqueue->size)
    {
        printf("function queuePop: queue is null\n");
        return;
    }
    printf("pop element is: %d,", *pMyqueue->top);
    pMyqueue->top++;
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
    int size = 20;
    int a[size];
    myQueue** ppMyqueue = (myQueue**)calloc(1, sizeof(myQueue*));
//myQueue** ppMyqueue = '\0';
    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,", a[i]);
        queuePush(ppMyqueue, a[i]);
    }
    printf("push finished\n");

    while(ppMyqueue && (*ppMyqueue) && (*ppMyqueue)->size)
    {
        queuePop(*ppMyqueue);
    }
    freeQueue(ppMyqueue);
    ppMyqueue = '\0';
    return 0;
}
