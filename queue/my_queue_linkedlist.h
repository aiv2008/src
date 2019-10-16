#ifndef MY_QUEUE_LINKEDLIST_H_INCLUDED
#define MY_QUEUE_LINKEDLIST_H_INCLUDED

typedef struct
{
    void* data;
    struct myQueueElem* pNext;
} myQueueElem;

typedef struct
{
    struct myQueueElem* top;
    struct myQueueElem* bottom;
} myQueue;


void queuePush(myQueue** ppMyqueue, void* data, int elemLen);

myQueueElem* queueTop(myQueue* pMyqueue);

myQueueElem* queueBottom(myQueue* pMyqueue);

void queuePop(myQueue* pMyqueue);

void freeQueue(myQueue** ppMyqueue);

#endif // MY_QUEUE_LINKEDLIST_H_INCLUDED
