#include<stdio.h>
#include<stdlib.h>
#include "../common/common.h"
#include "heap.h"

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


    size_t a[] = {4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(a)/sizeof(a[0]);
    printf("---before heap operation begin---\n");
    for(int i=0;i<size;i++)
        printf("%d,",a[i]);
    printf("---before heap operation end---\n");
    Heap* heap = max_heap_init(a, size);
    heap = max_heap_insert(heap, 15);
    printf("---after heap operation begin---\n");

    printf("header===%d\n",*(heap->heap_header));
//    for(int i=0;i<heap->length;i++)
//        printf("%d,",*(heap->heap_header+i));
    print_heap(heap);
    printf("---after heap operation end---\n");

    return 0;
}
