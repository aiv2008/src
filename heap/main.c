#include<stdio.h>
#include<stdlib.h>
#include "../common/common.h"
#include "heap.h"
#define NIL -50000

int main(void)
{
//    printf("--before build_max_heap begin--\n");
//    srand(time(NULL));
//    size_t size = 50;
//    size_t a[size];
//
//    for(int i=0;i<size;i++)
//    {
//        a[i] = rand()%size;
//        printf("%d,",a[i]);
//    }


    int a[] = {4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(a)/sizeof(a[0]);
    printf("---before heap operation begin---\n");
    for(int i=0;i<size;i++)
        printf("%d,",a[i]);
    printf("---before heap operation end---\n");
    Heap* heap = max_heap_init(a, size);
    max_heap_insert(heap, 25);
    print_heap(heap);


    return 0;
}
