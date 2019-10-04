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
** 插入队列
**/
void push(pp_myQueue ppmyQueue);

/**
** 弹出队列
**/
void pop(pp_myQueue ppmyQueue);

/**
** 获取队列头元素
**/
int* top(pp_myQueue ppmyQueue);

void printQueue(pp_myQueue ppmyQueue);

BOOL queueIsNillOrEmpty(pp_myQueue ppmyQueue);

void freeQueue(pp_myQueue ppmyQueue);

#endif // MY_QUEUE_H_INCLUDED
