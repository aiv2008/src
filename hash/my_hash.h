#ifndef MY_HASH_H_INCLUDED
#define MY_HASH_H_INCLUDED

typedef struct
{
	int val;
	struct linkedList *pNext;
} linkedList;

typedef struct
{
	struct linkedList **key;
	struct linkedList **val;
	int size;
} linkedListMap;

int hashDiv(int key);

int hashMul(int key);

int hashAllDom(int key);

void pushDivLinkedList(linkedListMap **ppLinkedList,  int key, int val);

int getDivLinkedList(linkedListMap *pLinkedList, int key);

#endif

