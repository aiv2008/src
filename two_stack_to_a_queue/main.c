#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <limits.h>
#include"two_stack_to_a_queue.h"
#define BOOL int
#define TRUE 1
#define FALSE 0

int main(void)
{
    srand(time(NULL));
    size_t size = 0;
    int a[size];


//    int a[] = {4,5,6,89,0,0,2,1,3,4,5,6,7,5};
    int* p = a;
//    int size = sizeof(a)/sizeof(a[0]);
    pp_myStack ppmystack = (pp_myStack)calloc(1, sizeof(p_myStack));
    for(int i=0;i<size;i++,p++)
    {
        a[i] = rand()%size;
        printf("%d,",a[i]);
        push(ppmystack, a[i]);
    }
    printf("\n");

//    printStack(ppmystack);
    printf("top=%d\n",*(top(ppmystack)));

//    BOOL b = stackIsNillOrEmpty(ppmystack);
//    printf("stack is null or empty %d\n",b);

//    while(!stackIsNillOrEmpty(ppmystack))
//    {
//        pop(ppmystack);
//    }
//    pop(ppmystack);

    return 0;
}
