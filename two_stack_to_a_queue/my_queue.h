#ifndef MY_QUEUE_H_INCLUDED
#define MY_QUEUE_H_INCLUDED
#include<stdio.h>
#include"../stack/my_stack.h"
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct
{
    pp_myStack stack_a;
    pp_myStack stack_b;
} myQueue, *p_myQueue, **pp_myQueue;

/**
** �������
**/
void q_push(pp_myQueue ppmyQueue, int data);

/**
** ��������
**/
void q_pop(pp_myQueue ppmyQueue);

/**
** ��ȡ����ͷԪ��
**/
int* q_top(pp_myQueue ppmyQueue);

void printQueue(pp_myQueue ppmyQueue);

BOOL queueIsNillOrEmpty(pp_myQueue ppmyQueue);

BOOL queueIsNill(pp_myQueue ppmyQueue);

BOOL queueIsEmpty(pp_myQueue ppmyQueue);

void freeQueue(pp_myQueue ppmyQueue);

#endif // MY_QUEUE_H_INCLUDED
