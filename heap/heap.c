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
        int largest = index;
        if(l_index < heap_size && *(heap_header + l_index) > *(heap_header + largest))
            largest = l_index;
        if(r_index < heap_size && *(heap_header + r_index) > *(heap_header + largest))
            largest = r_index;
        if(largest != index)
        {
            swap_1(heap_header+largest, heap_header+index);
            max_heapify(heap, largest);
        }
    }
}

int left(int index)
{
//    return index<<1;
    return -~(index<<1);
}

int right(int index)
{
//    return -~(index<<1);
    return -~(-~(index<<1));
}

int parent(int index)
{
//    return index>>1;
    return (index&1) == 0 ? (index - 1) >> 1 : index >> 1;
}

void build_max_heap(Heap* heap)
{
    size_t* heap_header = heap->heap_header;
    int heap_size = heap->heap_size;
    for(int i = parent(heap_size-1);i >= 0;i--)
        max_heapify(heap, i);
}

Heap* heap_init(size_t* a, int size)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->heap_header = a;
    heap->heap_size = size;
    heap->length = size;
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

void heap_sort(Heap* heap)
{
    build_max_heap(heap);
    size_t* header = heap->heap_header;
    int length = heap->length;
    for(int i=length-1;i>=1;i--)
    {
//        printf("heap[0]===%d,",*header);
//        printf("heap[i]===%d,",*(header+i));
        swap_1(header, header+i);
//        printf("heap[0]===%d,",*header);
//        printf("heap[i]===%d\n",*(header+i));
        heap->heap_size--;
        max_heapify(heap, 0);
    }
}

size_t heap_maximum(Heap* heap)
{
    build_max_heap(heap);
    return *heap->heap_header;
}

size_t heap_extract_max(Heap* heap)
{
    build_max_heap(heap);
    size_t max = *heap->heap_header;
    swap_1(heap->heap_header, heap->heap_header+heap->length-1);
    heap->heap_size--;
    max_heapify(heap, 0);
    return max;
}

void heap_increase_key(Heap* heap, int index, int key)
{
    build_max_heap(heap);
    size_t* header = heap->heap_header+index;
    size_t old_key = *header;
    if( old_key > key )
        printf("increase key error: new key must be larger than old");
    *(header+index) = key;
    int p_index = parent(index);
    size_t parent_key = *(header+p_index);
    while( parent_key > *(header+index) )
    {
        swap_1(header+p_index, header+index);
        index = p_index;
        p_index = parent(index);
        parent_key = *(header+p_index);
    }
}
