#include<stdio.h>
#include<stdlib.h>

#define HASH_SIZE 17

typedef struct
{

	int val;
	struct *linkedList pNext;
} linkedList;


typedef struct
{
	struct *linkedList pVal;
	int size;
} myHash;

int myHash(int key)
{
	return (key+HASH_SIZE)%HASH_SIZE;
}

void myHashPush(myHash **ppMyHash, int key, int val)
{
	if(!ppMyHash)return;
	if(!*ppMyHash)
	{

		*ppMyHash = (myHash*)calloc(1, sizeof(myHash));
		(*ppMyHash)->size = HASH_SIZE;
		//(*ppMyHash)->pValue = (linkedList*)calloc(1, sizeof(linkedList))
	}
	if(!(*ppMyHash)->pVal)
		(*ppMyHash)->pVal = (linkedList*)calloc(1, sizeof(linkedList));

}

int main(void)
{

	
	return 0;
}
