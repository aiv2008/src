#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <limits.h>
#include"../stack/my_stack.h"
#include "my_queue.h"
#define BOOL int
#define TRUE 1
#define FALSE 0

int main(void)
{
    srand(time(NULL));
    size_t size = 0;
    int a[size];

//    int a[] = {8,8,1,1,6,8,3,2,9,2};
//    int a[] = {8,8,1,1,6,8,3,2,9,11,12,14,25,55,32,89,1};
//    int* p = a;
//    int size = sizeof(a)/sizeof(a[0]);


//    pp_myStack ppmystack = (pp_myStack)calloc(1, sizeof(p_myStack));
//    for(int i=0;i<size;i++,p++)
//    {
//        a[i] = rand()%size;
//        printf("%d,",a[i]);
//        push(ppmystack, a[i]);
//    }
//    printf("\n");
//
//    while(!stackIsNillOrEmpty(ppmystack))
//    {
//        printf("program in");
//        pop(ppmystack);
//    }
//    pop(ppmystack);
//    freeStack(ppmystack);
//    ppmystack = NULL;

    pp_myQueue ppmyQueue = (pp_myQueue)calloc(1, sizeof(p_myQueue));
    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,",a[i]);
        q_push(ppmyQueue, a[i]);
    }
    printf("\n");

    for(int i=0;i<size;i++)
    {
        printf("aaa");
        q_pop(ppmyQueue);
    }

    size_t size_2 = 10;
    int b[size_2];

    for(int i=0;i<size_2;i++)
    {
        b[i] = rand()%size_2;
        printf("%d,",b[i]);
        q_push(ppmyQueue, b[i]);
    }
    printf("\n");

    for(int i=0;i<size_2+3;i++)
    {
        q_pop(ppmyQueue);
    }

    freeQueue(ppmyQueue);
    ppmyQueue = NULL;

    return 0;
}
