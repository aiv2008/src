#ifndef MY_QUEUE_H_INCLUDED
#define MY_QUEUE_H_INCLUDED

typedef struct
{
    int* top;
    int size;
    int capability;
} myQueue;

void queuePush(myQueue** ppMyqueue, int data);

int* top(myQueue* pMyqueue);

void queuePop(myQueue* pMyqueue);

void freeQueue(myQueue** ppMyqueue);
#endif // MY_QUEUE_H_INCLUDED
