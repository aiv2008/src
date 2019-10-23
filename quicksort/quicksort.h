#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

#include "../common/list_i.h"

//默认以集合里的最后一个元素作为主元素
int myPartition(int* array, int start, int end);

void myQuicksort(int* array, int start, int end);

//随机从集合里选择一个元素作为主元素
int myRandomizedPartition(int* array, int start, int end);

void myRandomizedQuicksort(int* array, int start, int end);

#endif // QUICKSORT_H_INCLUDED
