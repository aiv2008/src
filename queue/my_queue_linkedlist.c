#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"my_queue_linkedlist.h"

void queuePush(myQueue** ppMyqueue, void* data, int elemLen)
{
    if(!ppMyqueue)
    {
        printf("function queuePush: queue is null\n");
        return;
    }
    if(!data)
    {
        printf("function queuePush: data is null\n");
        return;
    }
    if(!elemLen)
    {
        printf("function queuePush: elemLen is zero\n");
        return;
    }
    if(!*ppMyqueue)
        *ppMyqueue = (myQueue*)calloc(1, sizeof(myQueue));
    if(!(*ppMyqueue)->bottom)
    {
        (*ppMyqueue)->bottom = (myQueueElem*)calloc(1, sizeof(myQueueElem));
        myQueueElem* bottom = (*ppMyqueue)->bottom;
        bottom->data = calloc(1, sizeof(elemLen));
        memcpy(bottom->data, data, elemLen);
        (*ppMyqueue)->top = (*ppMyqueue)->bottom;
    }
    else
    {
        myQueueElem* elem = (myQueueElem*)calloc(1, sizeof(myQueueElem));
        elem->data = calloc(1, sizeof(elemLen));
        memcpy(elem->data, data, elemLen);
        myQueueElem* tmp = (*ppMyqueue)->bottom;
        (*ppMyqueue)->bottom = elem;
        tmp->pNext = elem;
    }
}

myQueueElem* queueTop(myQueue* pMyqueue)
{
    return pMyqueue ? pMyqueue->top : '\0';
}

myQueueElem* queueBottom(myQueue* pMyqueue)
{
    return pMyqueue ? pMyqueue->bottom : '\0';
}

void queuePop(myQueue* pMyqueue)
{
    if(!pMyqueue)
    {
        printf("function queuePop: queue is null\n");
        return;
    }
    if(!pMyqueue->top)
    {
        printf("function queuePop: queue is empty\n");
        return;
    }
    if(pMyqueue->top == pMyqueue->bottom)//����ֻʣһ��Ԫ��
    {
        free(pMyqueue->top);
        pMyqueue->top = '\0';
        pMyqueue->bottom = '\0';
    }
    else
    {
        myQueueElem* top = pMyqueue->top;
        pMyqueue->top = top->pNext;
        free(top);
        top = '\0';
    }
}

void freeQueue(myQueue** ppMyqueue)
{
    if(*ppMyqueue)
    {
        free(*ppMyqueue);
        *ppMyqueue = '\0';
    }
}

int main(void)
{
    srand(time(0));
    int size = 10;
    int a[size];
    myQueue** ppMyqueue = (myQueue**)calloc(1, sizeof(myQueue*));
    myQueueElem* bottom = '\0';
    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,", a[i]);
        queuePush(ppMyqueue, &a[i], sizeof(int));
        bottom = queueBottom(*ppMyqueue);
        printf("%d\n", *((int*)(bottom->data)));
    }
    printf("\n");
//    int* top = (*ppMyqueue)->top;
//    int* bottom = (*ppMyqueue)->bottom;
//    printf("top=%d\n", *top);
//    printf("bottom=%d\n", *bottom);

    myQueueElem* top = '\0';
//    top = (myQueueElem*)queueTop(*ppMyqueue);
//    myQueueElem* pMove = top;
//    while(pMove)
//    {
//        printf("%d,", *((int*)(pMove->data)));
//        pMove = pMove->pNext;
//    }


    while((*ppMyqueue)->bottom)
    {
        top = (myQueueElem*)queueTop(*ppMyqueue);
        printf("%d,", *((int*)(top->data)));
        queuePop(*ppMyqueue);
    }

    freeQueue(ppMyqueue);
    ppMyqueue = '\0';
}
