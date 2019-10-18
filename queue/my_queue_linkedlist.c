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
	printf("enter p1\n");
	printf("elemLen=%d\n",elemLen);
        (*ppMyqueue)->bottom = (myQueueElem*)calloc(1, sizeof(myQueueElem));
        myQueueElem* bottom = (*ppMyqueue)->bottom;
        bottom->data = calloc(1, sizeof(elemLen));
        memcpy(bottom->data, data, elemLen);
        (*ppMyqueue)->top = (*ppMyqueue)->bottom;
    }
    else
    {
printf("enter p2\n");
	//new bottom
myQueueElem* elem;
printf("00000\n");
printf("elemLen22=%d\n",elemLen);
        if((elem = (myQueueElem*)calloc(1, sizeof(myQueueElem)))=='\0')
	{
		printf("malloc memory unsuccessful\n");
		exit(1);
	}
	else
	{
		printf("calloc successfully\n");
	}
printf("aaa\n");
        if((elem->data = calloc(1, sizeof(elemLen)))=='\0')
	{
		printf("malloc memory unsuccessful\n");
		exit(1);
	}
	else
	{
		printf("calloc successfully\n");
	}
printf("bbb\n");
        memcpy(elem->data, data, elemLen);
printf("ccc\n");
	//old bottom, new bottom-1
        myQueueElem* tmp = (*ppMyqueue)->bottom;
printf("ddd\n");
        (*ppMyqueue)->bottom = elem;	
printf("eee\n");
        tmp->pNext = elem;
printf("fff\n");
	elem = '\0';
	tmp = '\0';;
    }
	return ;
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
	return;
}

void freeQueue(myQueue** ppMyqueue)
{
    if(*ppMyqueue)
    {
        free(*ppMyqueue);
        *ppMyqueue = '\0';
    }
return ;
}
/**
int main(void)
{
    srand(time(0));
    int size = 10;
    int a[size];
    myQueue** ppMyqueue = (myQueue**)calloc(1, sizeof(myQueue*));
    myQueueElem* bottom = '\0';
    int i;
    for(i=0;i<size;i++)
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
**/
