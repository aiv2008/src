#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct
{
    size_t *heap_header;
    int heap_size;
    int length;
} Heap;

void max_heapify(Heap* heap, int index);

int left(int index);

int right(int index);

int parent(int index);

void build_max_heap(Heap* heap);

Heap* heap_init(size_t* a, int size);

void print_node(size_t* header, int index, int size);

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
void max_heap_insert(Heap* heap, size_t key);

/**
**
** operation must be based on the max heap
**/
size_t heap_extract_max(Heap* heap);

/**
**
** operation must be based on the max heap
**/
void heap_increase_key(Heap* heap, int index, int key);

/**
**
** operation must be based on the max heap
**/
size_t heap_maximum(Heap* heap);

void print_heap(Heap* heap);

/**
** initialize the max heap
**/
Heap* max_heap_init(size_t* a, int size);

/**
** initialize the min heap
**/
Heap* min_heap_init(size_t* a, int size);

#endif // HEAP_H_INCLUDED
