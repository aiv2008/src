#include<stdio.h>
#include<stdlib.h>
#include"my_list.h"

int main(void)
{
    int a[] = {3,4,56,7,78,4,3,5,76,7,8,6,4,3,0};
    int size = sizeof(a)/sizeof(a[0]);
    myList** ppMyList = (myList**)calloc(1, sizeof(myList*));
    for(int i=0;i<size;i++)
    {
        add(ppMyList, a[i] , sizeof(int));
    }
    return 0;
}
