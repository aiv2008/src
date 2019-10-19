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
	bottom->data = data;
        //bottom->data = calloc(1, sizeof(elemLen));
        //memcpy(bottom->data, data, elemLen);
        (*ppMyqueue)->top = (*ppMyqueue)->bottom;
    }
    else
    {
	//new bottom
	myQueueElem* elem = (myQueueElem*)calloc(1, sizeof(myQueueElem));
	elem->data = data;
	//old bottom
        myQueueElem* tmp = (*ppMyqueue)->bottom;
        (*ppMyqueue)->bottom = elem;	
        tmp->pNext = elem;
	elem = '\0';
	tmp = '\0';;
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
    if(pMyqueue->top == pMyqueue->bottom)//队列只剩一个元素
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
