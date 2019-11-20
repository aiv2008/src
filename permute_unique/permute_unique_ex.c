#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define HASH_SIZE 17

typedef struct
{
	int val;
	struct linkedListNode *pNext;
} linkedListNode;


typedef struct
{
	struct linkedListNode **key;
	struct linkedListNode **val;
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
		(*ppLinkedListMap)->key = (linkedListNode**)calloc(HASH_SIZE, sizeof(linkedListNode*));
		(*ppLinkedListMap)->val = (linkedListNode**)calloc(HASH_SIZE, sizeof(linkedListNode*));
	}
	int hashCode = h(key);
	linkedListNode* pKeyIndex = *((*ppLinkedListMap)->key + hashCode);
	linkedListNode* pValIndex = *((*ppLinkedListMap)->val + hashCode);
	if(!pKeyIndex)
	{
		pKeyIndex = (linkedListNode*)calloc(1, sizeof(linkedListNode));
		pValIndex = (linkedListNode*)calloc(1, sizeof(linkedListNode));
		pKeyIndex->val = key;
		pValIndex->val = val;
		*((*ppLinkedListMap)->key + hashCode) = pKeyIndex;
		*((*ppLinkedListMap)->val + hashCode) = pValIndex;
	}
	else
	{
		linkedListNode* pKeyMove = pKeyIndex;
		linkedListNode* pValMove = pValIndex;
		int count = 0;
		linkedListNode *pKeyCur = NULL;
		linkedListNode *pValCur = NULL;
		while(pKeyMove)
		{
			if(pKeyMove->val == key)
			{
				pValMove->val = val;	
				count++;
				break;
			}
			pKeyCur = pKeyMove;
			pValCur = pKeyMove;
			pKeyMove = pKeyMove->pNext;
			pValMove = pValMove->pNext;
		}
		if(!count)
		{
			linkedListNode *pKeyNode = (linkedListNode*)calloc(1, sizeof(linkedListNode));	
			linkedListNode *pValNode = (linkedListNode*)calloc(1, sizeof(linkedListNode));
			pKeyNode->val = key;
			pValNode->val = val;
			pKeyMove->pNext = pKeyNode;
			pValMove->pNext = pValNode;
			pKeyNode = NULL;
			pValNode = NULL;
		}
		pKeyMove = NULL;
		pValMove = NULL;
		pKeyCur = NULL;
		pValCur = NULL;
	}	
}

int get(linkedListMap *pLinkedListMap, int key)
{
	if(!pLinkedListMap)
	{
		//printf("map is null\n");
		return -1;
	}
	int hashCode = h(key);
	if(!pLinkedListMap->key)
	{
		//printf("plinkedlistkey is null\n");
		return;
	}
	linkedListNode **ppKeyIndex = pLinkedListMap->key + hashCode;
	if(!ppKeyIndex)
	{
		printf("key is null\n");
		return -1;
	}
	
	linkedListNode *pKeyMove = (*ppKeyIndex);	
	linkedListNode *pValMove = *(pLinkedListMap->val + hashCode);
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
	int size = calN(numsSize);
	linkedListMap *pLinkedListMap = NULL;
	//linkedList *pLinkedList = NULL;
	linkedListNode *pHeader = NULL;
	linkedListNode *pMove = pHeader;
	int i;
	for(i=0;i<numsSize;i++)
	{
		int count = get(pLinkedListMap, nums[i]);
//		printf("nums=%d, count=%d\n",nums[i], count);
		if(count==-1)
		{
			push(&pLinkedListMap, nums[i], 1);
			if(!pHeader)
			{
				pHeader = (linkedListNode*)calloc(1, sizeof(linkedListNode));
				pHeader->val=nums[i];
				pMove = pHeader;
			}
			else
			{
				pMove->pNext = (linkedListNode*)calloc(1, sizeof(linkedListNode));
				((linkedListNode*)(pMove->pNext))->val = nums[i];
				//pMove->pNext = pMove;
				pMove = pMove->pNext;			
			}
	//		add(&pLinkedList, nums[i]);
		}
		else
		{	
		//	int count = get(pLinkedListMap, nums[i]);
		//	printf("nums=%d,count=%d\n",nums[i], count);
			push(&pLinkedListMap, nums[i], count+1);
		}
	}
	pMove = pHeader;
	while(pMove)
	{
		int count = get(pLinkedListMap, pMove->val);
	//	printf("val=%d,count=%d\n", pMove->val, count);
		size = size / calN(count);
		pMove = pMove->pNext;
	}
	printf("size=%d\n", size);
	int** result = (int**)calloc(size, sizeof(int*));
	int** resultMove = result;
	int* columnSizes = (int*)calloc(size, sizeof(int));
	int* columnSizesMove = columnSizes;
	permutation(nums, nums, numsSize, &resultMove, &columnSizesMove );
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
	//		printf("%d,", *(**pppMove+i));
		}
		**columnSizesMove = size;
	//	printf("\n");
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
				push(&pLinkedListMap, *pMove, 1);
	//			printf("enter\n");
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

