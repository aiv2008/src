#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <limits.h>
#include"../stack/my_stack.h"
#define BOOL int
#define TRUE 1
#define FALSE 0

int main(void)
{
    srand(time(NULL));
    size_t size = 10;
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
    while(!stackIsNillOrEmpty(ppmystack))
    {
        printf("program in");
        pop(ppmystack);
    }
    pop(ppmystack);
    freeStack(ppmystack);
    ppmystack = NULL;


    return 0;
}
