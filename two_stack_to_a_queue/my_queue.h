#ifndef MY_QUEUE_H_INCLUDED
#define MY_QUEUE_H_INCLUDED

#include<stdio.h>
#include"../stack/my_stack.h"

typedef struct
{
    p_myStack stack_a;
    p_myStack stack_b;
} myQueue, *p_myQueue, **pp_myQueue;

/**
** �������
**/
void push(pp_myQueue ppmyQueue);

/**
** ��������
**/
void pop(pp_myQueue ppmyQueue);

/**
** ��ȡ����ͷԪ��
**/
int* top(pp_myQueue ppmyQueue);

void printQueue(pp_myQueue ppmyQueue);

BOOL queueIsNillOrEmpty(pp_myQueue ppmyQueue);

void freeQueue(pp_myQueue ppmyQueue);

#endif // MY_QUEUE_H_INCLUDED
