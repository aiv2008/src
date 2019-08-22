#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

typedef struct Heap
{
    size_t *heap_header;
    signed heap_size;
}

void max_heapify(size_t* a, signed int index);

signed int left(signed int index);

signed int right(signed int index);

signed int parent(signed int index);

#endif // HEAP_H_INCLUDED
