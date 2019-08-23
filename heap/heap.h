#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct
{
    size_t *heap_header;
    int heap_size;
} Heap;

void max_heapify(Heap* heap, int index);

signed int left(int index);

signed int right(int index);

signed int parent(int index);

void build_max_heap(Heap* heap);

Heap* heap_init(size_t* a, int size);

void print_node(size_t* header, int index, int size);

#endif // HEAP_H_INCLUDED
