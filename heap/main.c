#include<stdio.h>
#include<stdlib.h>
#include "../common/common.h"
#include "heap.h"

int main(void)
{
    size_t a[] = {4,1,3,2,16,9,10,14,8,7};
    int size = sizeof(a)/sizeof(a[0]);
    printf("--before build_max_heap begin--\n");
    for(int i=0;i<size;i++)
        printf("%d,",a[i]);
    printf("\n--before build_max_heap end--\n");
    Heap* heap = heap_init(a, size);
    heap_sort(heap);
//    build_max_heap(heap);
    printf("--after build_max_heap begin--\n");
    for(int i=0;i<size;i++)
        printf("%d,",a[i]);
    printf("\n--after build_max_heap end--\n");

    return 0;
}
