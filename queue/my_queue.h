#ifndef MY_QUEUE_H_INCLUDED
#define MY_QUEUE_H_INCLUDED

typedef struct
{
//    int* top;
    void* top;
    int size;
    int capability;
} myQueue;

void queuePush(myQueue** ppMyqueue, void* data, int elemLen);

int* top(myQueue* pMyqueue);

void queuePop(myQueue* pMyqueue, int elemLen);

void freeQueue(myQueue** ppMyqueue);
#endif // MY_QUEUE_H_INCLUDED
