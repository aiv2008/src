#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
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
//        *ppMyqueue = (myQueue*)calloc(1, sizeof(void*) + 2 * sizeof(int));
        *ppMyqueue = (myQueue*)calloc(1, sizeof(myQueue));
        (*ppMyqueue)->capability = 8;
        (*ppMyqueue)->top = (void*)calloc((*ppMyqueue)->capability, elemLen);
    }
    int size = (*ppMyqueue)->size;
    (*ppMyqueue)->size++;
    if((*ppMyqueue)->size > (*ppMyqueue)->capability)
    {
        printf("extend the memory space\n");
        int capability = (*ppMyqueue)->capability;
        capability += (capability >> 1);
        void* top = calloc(capability, elemLen);
        for(int i=0;i<size;i++)
            memcpy(top + elemLen * i, (*ppMyqueue)->top + elemLen * i, elemLen);
        free((*ppMyqueue)->top);
        (*ppMyqueue)->capability = capability;
        (*ppMyqueue)->top = top;
        top = '\0';
    }
//    void* newTop = (*ppMyqueue)->top +  elemLen * (*ppMyqueue)->size;
    void* newTop = (*ppMyqueue)->top +  elemLen * size;
    memcpy(newTop, data, elemLen);

//    printf("queuePush: size==%d\n", (*ppMyqueue)->size);
}

void* queueTop(myQueue* pMyqueue)
{
    if(!pMyqueue)
    {
        printf("function top: queue is null\n");
        return '\0';
    }
    return pMyqueue->top;
}

void* queuePop(myQueue* pMyqueue, int elemLen)
{
    if(!pMyqueue||!pMyqueue->capability||!pMyqueue->size)
    {
        printf("function queuePop: queue is null\n");
        return '\0';
    }
    void* top = pMyqueue->top;

    pMyqueue->size--;
    if(pMyqueue->size)
        pMyqueue->top += elemLen;
//    printf("queuePop: size==%d\n", pMyqueue->size);
    return top;
//    printf("pop successfully\n");
}

void freeQueue(myQueue** ppMyqueue)
{
    if(ppMyqueue)
    {
        if(*ppMyqueue)
        {
            if((*ppMyqueue)->top)
            {
                free((*ppMyqueue)->top);
                (*ppMyqueue)->top = '\0';
            }
            free(*ppMyqueue);
            *ppMyqueue = '\0';
//            printf("queue free successfully\n");
        }
    }
    printf("function freeQueue: queue is null\n");
}

int main(void)
{

    srand(time(0));
    int size = 0;
    while(size>=0)
    {
        printf("please input the size:\n");
        scanf("%d", &size);
        if(size == 0)
        {
            printf("cannot be 0\n");
            continue;
        }
        int a[size];
        myQueue** ppMyqueue = (myQueue**)calloc(1, sizeof(myQueue*));
        for(int i=0;i<size;i++)
        {
            a[i] = rand()%size;
            printf("push==%d\n", a[i]);
            queuePush(ppMyqueue, &a[i], sizeof(int));
        }
    //    printf("size===%d\n",(*ppMyqueue)->size);
        printf("\n");
        int* top = '\0';
        int* top2 = '\0';
        while((*ppMyqueue)->size)
        {
            int ram = rand()%size;
            printf("push==%d\n", ram);
            queuePush(ppMyqueue, &ram, sizeof(int));
            if(!(*ppMyqueue)->size)
            {
                printf("queue is empty111");
                break;
            }
            top = (int*)queuePop(*ppMyqueue, sizeof(int));
            printf("pop1: %d\n", *top);
            if(!(*ppMyqueue)->size)
            {
                printf("queue is empty222");
                break;
            }
            top2 = queuePop(*ppMyqueue, sizeof(int));
            printf("pop2: %d\n", *top2);
        }
        if(ppMyqueue)
        {
            if(*ppMyqueue)
            {
                freeQueue(*ppMyqueue);
                *ppMyqueue = '\0';
            }
            free(ppMyqueue);
            ppMyqueue = '\0';
        }
    }


    return 0;
}


