#include<stdio.h>
#include<stdlib.h>
#include"two_stack_to_a_queue.h"

int main(void)
{
    int a[] = {4,6,8,89,3,2,4,5};
    int* p = a;
    pp_myStack ppmystack = (pp_myStack)calloc(1, sizeof(p_myStack));
    for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++,p++)
    {
        push(ppmystack, a[i]);
    }

    printStack(ppmystack);

    while((*ppmystack)->size)
    {
        printf("top=%d\n", *(top(ppmystack)));
        pop(ppmystack);
    }
    return 0;
}
