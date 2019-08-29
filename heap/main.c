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
//
////    size_t a[] = {4,1,3,2,16,9,10,14,8,7};
////    int size = sizeof(a)/sizeof(a[0]);
////    for(int i=0;i<size;i++)
////        printf("%d,",a[i]);
//
////    printf("\n--before build_max_heap end--\n");
//    Heap* heap = heap_init(a, size);
////    heap_sort(heap);
//////    build_max_heap(heap);
////    printf("--after build_max_heap begin--\n");
////    for(int i=0;i<size;i++)
////        printf("%d,",a[i]);
////    printf("\n--after build_max_heap end--\n");
//
//    printf("\nmax=%d\n",heap_extract_max(heap));
//    for(int i=0;i<heap->heap_size;i++)
//        printf("%d,",a[i]);

    int a[] = {2,3,4,5,6,7,8};
    int* p = a;
    *(p+1) = 8;
    printf("%d",*(p+1));
    return 0;
}
