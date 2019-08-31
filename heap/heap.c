#include<stdio.h>
#include<stdlib.h>
#include "../common/common.h"
#include "heap.h"
#define NIL -50000

void max_heapify(Heap* heap, size_t index)
{
    if( index >= 0 && index < heap->heap_size )
    {
        size_t l_index = left(index);
        size_t r_index = right(index);
        int* heap_header = heap->heap_header;
        size_t heap_size = heap->heap_size;
        size_t largest = index;
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

size_t left(size_t index)
{
//    return index<<1;
    return -~(index<<1);
}

size_t right(size_t index)
{
//    return -~(index<<1);
    return -~(-~(index<<1));
}

size_t parent(size_t index)
{
//    return index>>1;
    return (index&1) == 0 ? (index - 1) >> 1 : index >> 1;
}

void build_max_heap(Heap* heap)
{
    int* heap_header = heap->heap_header;
    size_t heap_size = heap->heap_size;
    //子数组A[(⌊n/2⌋+1)...n]中的元素都是树中的叶子,因此每个都可以看做是只含有一个元素的堆.
    //循环从最后一个子树的根节点开始,即从i = ⌊length[A]/2⌋ 开始
    for(int i = parent(heap_size-1);i >= 0;i--)
        max_heapify(heap, i);
}

Heap* heap_init(int* a, size_t size)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->heap_header = a;
    heap->heap_size = size;
    heap->length = size;
    return heap;
}

void print_node(int* header, size_t index, size_t size)
{
    if(index < size)
    {
        printf("\n  ");
        size_t p = parent(index);
        size_t l = left(index);
        size_t r = right(index);
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
    int* header = heap->heap_header;
    size_t length = heap->length;
    for(int i=length-1;i>=1;i--)
    {
        swap_1(header, header+i);
        heap->heap_size--;
        max_heapify(heap, 0);
    }
}

int heap_maximum(Heap* heap)
{
//    build_max_heap(heap);
    return *heap->heap_header;
}

int heap_extract_max(Heap* heap)
{
//    build_max_heap(heap);
    int max = *heap->heap_header;
    swap_1(heap->heap_header, heap->heap_header+heap->length-1);
    heap->heap_size--;
    max_heapify(heap, 0);
    return max;
}

void heap_increase_key(Heap* heap, size_t index, int key)
{
    int* header = heap->heap_header;
    int old_key = *(header+index);
    printf("old_key=%d\n",old_key);
    if( old_key > key )
    {
        printf("increase key error: new key must be larger than old");
        return;
    }
    *(header+index) = key;
    size_t p_index = parent(index);
    while(index >=0 && index < heap->length && *(header+p_index) < *(header+index) )
    {
//        print_heap(heap);
        swap_1(header+p_index, header+index);
//        print_heap(heap);
        index = p_index;
        p_index = parent(index);
    }
}

void print_heap(Heap* heap)
{
    printf("\n---print heap begin---\n");
    int* header = heap->heap_header;
    size_t length = heap->length;
    for( int i=0;i<length;i++ )
        printf("%d,",*(header+i));
    printf("\n---print heap end---\n");
}

Heap* max_heap_init(int* a, size_t size)
{
    Heap* heap = heap_init(a, size);
    build_max_heap(heap);
    return heap;
}

Heap* max_heap_insert(Heap* heap, int key)
{
    heap->length++;
    int* old_header = heap->heap_header;
//    int new_length = heap->length+1;
    int new_array[heap->length];
    for(int i=0;i < heap->length;i++,old_header++)
        new_array[i] = *(old_header);
    new_array[heap->length-1] = NIL;
    free(heap->heap_header);
    heap->heap_header = new_array;
    heap_increase_key(heap, heap->length-1, key);
    printf("--new_array begin--\n");
    for(int i=0;i<sizeof(new_array)/sizeof(new_array[0]);i++)
        printf("%d,",new_array[i]);
    printf("--new_array end--\n");
    return heap_init(new_array, sizeof(new_array)/sizeof(new_array[0]));
//    return heap;
}
