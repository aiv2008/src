#include<stdio.h>
#include<stdlib.h>
#include "heap.h"

void max_heapify(Heap* heap, signed int index)
{
    signed int l_index = left(index);
    signed int r_index = right(index);
    signed int largest = *(a+index);
    size_t* heap_header = heap->heap_header;
    signed int heap_size = heap->heap_size;
    if(l_index <= heap_size && *(heap_header + l_index) > largest)
        largest = *(heap_header + l_index);
    if(r_index <= heap_size && *(heap_header + r_index) > largest)
        largest = *(heap_header + r_index);
    if(largest != index)
    {

    }
}

signed int left(signed int index)
{
    return index<<1;
}

signed int right(signed int index)
{
    return -~(index<<1);
}

signed int parent(signed int index)
{
    return index>>1;
}
