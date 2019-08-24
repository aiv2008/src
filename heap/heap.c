#include<stdio.h>
#include<stdlib.h>
#include "../common/common.h"
#include "heap.h"

void max_heapify(Heap* heap, int index)
{
    if( index >= 0 && index < heap->heap_size )
    {
        int l_index = left(index);
        int r_index = right(index);
        size_t* heap_header = heap->heap_header;
        int heap_size = heap->heap_size;
        printf("---before swap---");
        print_node(heap_header, index, heap_size);
        printf("---/before swap---\n");
        int largest = index;
        if(l_index < heap_size && *(heap_header + l_index) > *(heap_header + largest))
            largest = l_index;
        if(r_index < heap_size && *(heap_header + r_index) > *(heap_header + largest))
            largest = r_index;
        if(largest != index)
        {
            swap_1(heap_header+largest, heap_header+index);
            printf("---after swap---");
            print_node(heap_header, index, heap_size);
            printf("---/after swap---\n");
            max_heapify(heap, largest);
        }
    }
}

signed int left(int index)
{
//    return index<<1;
    return -~(index<<1);
}

signed int right(int index)
{
//    return -~(index<<1);
    return -~(-~(index<<1));
}

signed int parent(int index)
{
//    return index>>1;
    return (index&1) == 0 ? (index - 1) >> 1 : index >> 1;
}

void build_max_heap(Heap* heap)
{
    size_t* heap_header = heap->heap_header;
    int heap_size = heap->heap_size;
    for(int i = parent(heap_size-1);i > 0;i--)
    {
        printf("i===%d\n",i);
        max_heapify(heap, i);
    }
}

Heap* heap_init(size_t* a, int size)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->heap_header = a;
    heap->heap_size = size;
    return heap;
}

void print_node(size_t* header, int index, int size)
{
    if(index < size)
    {
        printf("\n  ");
        int p = parent(index);
        int l = left(index);
        int r = right(index);
        if(p < size)
            printf("%d",*(header + p));
        else
            printf("nil");
        printf("\n");
        printf("   |\n");
        printf(" ");
        printf("%d",*(header + index));
        printf("\n");
        printf(" /   \\\n");
        if(l < size)
            printf("%d",*(header + l));
        else
            printf("nil");
        printf("   ");
        if(r < size)
            printf("%d",*(header + r));
        else
            printf("nil");
        printf("\n");
    }
}
