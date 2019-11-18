#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HASH_SIZE 17

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

int h(int key)
{
	return (key+256) % HASH_SIZE;
}

void push(linkedListMap **ppLinkedListMap,  int key, int val)
{
	if(!ppLinkedListMap)return;
	if(!*ppLinkedListMap)
	{
		*ppLinkedListMap = (linkedListMap*)calloc(1, sizeof(linkedListMap));
		(*ppLinkedListMap)->size = HASH_SIZE;	
		(*ppLinkedListMap)->key = (linkedList**)calloc(HASH_SIZE, sizeof(linkedList*));
		(*ppLinkedListMap)->val = (linkedList**)calloc(HASH_SIZE, sizeof(linkedList*));
	}
	int hashCode = h(key);
	linkedList* pKeyIndex = *((*ppLinkedListMap)->key + hashCode);
	linkedList* pValIndex = *((*ppLinkedListMap)->val + hashCode);
	if(!pKeyIndex)
	{
		pKeyIndex = (linkedList*)calloc(1, sizeof(linkedList));
		pValIndex = (linkedList*)calloc(1, sizeof(linkedList));
		pKeyIndex->val = key;
		pValIndex->val = val;
		*((*ppLinkedListMap)->key + hashCode) = pKeyIndex;
		*((*ppLinkedListMap)->val + hashCode) = pValIndex;
	}
	else
	{
		linkedList* pKeyMove = pKeyIndex;
		linkedList* pValMove = pValIndex;
		while(pKeyMove->pNext)
		{
			pKeyMove = pKeyMove->pNext;
			pValMove = pValMove->pNext;
		}
		linkedList *pKeyNode = (linkedList*)calloc(1, sizeof(linkedList));	
		linkedList *pValNode = (linkedList*)calloc(1, sizeof(linkedList));
		pKeyNode->val = key;
		pValNode->val = val;
		pKeyMove->pNext = pKeyNode;
		pValMove->pNext = pValNode;
		pKeyMove = NULL;
		pValMove = NULL;
		pKeyNode = NULL;
		pValNode = NULL;
	}	
}

int get(linkedListMap *pLinkedListMap, int key)
{
	if(!pLinkedListMap)
	{
		printf("map is null\n");
		return -1;
	}
	int hashCode = h(key);
	//printf("hashCode=%d\n", hashCode);
	if(!pLinkedListMap->key)
	{
		printf("plinkedlistkey is null\n");
		return;
	}
	linkedList **ppKeyIndex = pLinkedListMap->key + hashCode;
	if(!ppKeyIndex)
	{
		printf("key is null\n");
		return -1;
	}
	
	linkedList *pKeyMove = (*ppKeyIndex);	
	linkedList *pValMove = *(pLinkedListMap->val + hashCode);
	int val = -1;
	while(pKeyMove)
	{
		if(pKeyMove->val == key)
		{
			val = pValMove->val;		
			break;
		}
		pKeyMove = pKeyMove->pNext;
		pValMove = pValMove->pNext;
	}
	return val;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if(!nums || !numsSize)return NULL;
	myRandomizedQuicksort(nums, 0, numsSize-1);
	int size = calN(numsSize);
	int i;
	int tmp = -10000;
	int count = 1;
	for(i=0;i<numsSize;i++)
	{
		if(i==0)
		{
			tmp = *(nums+i);
		}
		else
		{
			if(tmp == *(nums+i))
				count++;
			else
			{
				size = size / calN(count);
				tmp = *(nums+i);
				count = 1;
			}	
		}
	}
	if(count)size = size / calN(count);
	printf("size=%d\n", size);
	int** result = (int**)calloc(size, sizeof(int*));
	int** resultMove = result;
	int* columnSizes = (int*)calloc(size, sizeof(int));
	int* columnSizesMove = columnSizes;
	permutation(nums, nums, numsSize, &resultMove, &columnSizesMove );
	//for(i=0;i<size;i++)
	//	printf("%d,", *(columnSizes+i));
	printf("\n");
	*returnSize = size;
	*returnColumnSizes = columnSizes;
	return result;	
}

void permutation(int* pStr, int* pBegin, int size, int*** pppMove, int** columnSizesMove)
{
	//if(*pppMove - result > resultSize)return;
	if(pBegin - pStr == size)
	{
		if(!*pppMove)printf("*pppMove is null\n");
		**pppMove  = (int*)calloc(size, sizeof(int));
		int i;
		int* pMove = **pppMove;
		int* p = pStr;
		for(i=0;i<size;i++)	
		{
			*(**pppMove+i) = *(p+i);
			printf("%d,", *(**pppMove+i));
		}
		**columnSizesMove = size;
		printf("\n");
		(*pppMove)++;
		(*columnSizesMove)++;
	}
	else
	{
		int* pMove ;
		linkedListMap *pLinkedListMap = NULL;
		for(pMove = pBegin; pMove - pStr < size; ++pMove)
		{
			if(get(pLinkedListMap, *pMove) == -1)
			{
				push(&pLinkedListMap, *pMove, *pMove);
				printf("enter\n");
				int temp = *pMove;
				*pMove = *pBegin;
				*pBegin = temp;
				permutation(pStr, pBegin+1, size, pppMove, columnSizesMove);
				temp = *pMove;
				*pMove = *pBegin;
				*pBegin = temp;
			}
		}
		free(pLinkedListMap);
		pLinkedListMap = NULL;
	}				
}

int calN(int n)
{
	int sum=1;
	while(n)
	{
		sum *= n--;
	}
	return sum;
}

