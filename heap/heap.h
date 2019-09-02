#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct
{
    int *heap_header;
    size_t heap_size;
    size_t length;
} Heap;

void max_heapify(Heap* heap, size_t index);

size_t left(size_t index);

size_t right(size_t index);

size_t parent(size_t index);

void build_max_heap(Heap* heap);

Heap* heap_init(int* a, size_t size);

void print_node(int* header, size_t index, size_t size);

/**
** Priority sorted(from smallest to biggest)
** step: 1.build max heap
** 2.exchange the pos 1st to the last
** 3.keep the max heap of the new heap (from 1st to n-1)
**/
void heap_sort(Heap* heap);

/**
** Priority sorted(from smallest to biggest)
** operation must be based on the max heap
**/
void max_heap_insert(Heap* heap, int key);

/**
**
** operation must be based on the max heap
**/
int heap_extract_max(Heap* heap);

/**
**
** operation must be based on the max heap
**/
void heap_increase_key(Heap* heap, size_t index, int key);

/**
**
** operation must be based on the max heap
**/
int heap_maximum(Heap* heap);

void print_heap(Heap* heap);

/**
** initialize the max heap
**/
Heap* max_heap_init(int* a, size_t size);

/**
** initialize the min heap
**/
Heap* min_heap_init(int* a, size_t size);

#endif // HEAP_H_INCLUDED
