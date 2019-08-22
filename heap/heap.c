#include<stdio.h>
#include<stdlib.h>
#include "../common/common.h"
#include "heap.h"

void max_heapify(Heap* heap, int index)
{
    if( index >= 0 && index <= heap->heap_size )
    {
        int l_index = left(index);
        int r_index = right(index);
        size_t* heap_header = heap->heap_header;
        int heap_size = heap->heap_size;
        int largest = index;
        if(l_index <= heap_size && *(heap_header + l_index) > *(heap_header + largest))
            largest = l_index;
        if(r_index <= heap_size && *(heap_header + r_index) > largest)
            largest = r_index;
        if(largest != index)
        {
            swap_1(heap_header+largest, heap_header+index);
            max_heapify(heap, largest);
        }
    }
}

signed int left(int index)
{
    return index<<1;
}

signed int right(int index)
{
    return -~(index<<1);
}

signed int parent(int index)
{
    return index>>1;
}

void build_max_heap(Heap* heap)
{
    size_t* heap_header = heap->heap_header;
    int heap_size = heap->heap_size;
    for(int i = (heap_size%2==0 ? heap_size/2 : (heap_size-1)/2)-1;i >= 0;i--)
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
