#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"two_stack_to_a_queue.h"

int main(void)
{
    int a[] = {};
    int* p = a;
    int size = sizeof(a)/sizeof(a[0]);
    pp_myStack ppmystack = (pp_myStack)calloc(1, sizeof(p_myStack));
    for(int i=0;i<size;i++,p++)
    {
        push(ppmystack, a[i]);
    }

    printStack(ppmystack);
//    printf("size=%d\n",(*ppmystack)->size);
    while(!stackIsNillOrEmpty(ppmystack))
    {
        printf("aaaaa");
        pop(ppmystack);
    }
//    pop(ppmystack);

    return 0;
}
