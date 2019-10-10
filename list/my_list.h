#ifndef MY_LIST_H_INCLUDED
#define MY_LIST_H_INCLUDED

#define my_bool int
#define TRUE 1
#define FALSE 0

typedef struct
{
    void* header;
    int size;
    int capability;
} myList;

void add(myList** ppMyList, void* p_data, int elemSize);

my_bool listIsNullOrEmpty(myList** ppMyList);

my_bool listIsNull(myList** ppMyList);

my_bool listIsEmpty(myList** ppMyList);

#endif // MY_LIST_H_INCLUDED
