#include<stdio.h>
#include<stdlib.h>
#include"my_hash.h"
#define HASH_SIZE 17

int hashDiv(int key)
{
	return (key+256) % HASH_SIZE;
}

void pushDivLinkedList(linkedListMap **ppLinkedListMap,  int key, int val)
{
	if(!ppLinkedListMap)return;
	if(!*ppLinkedListMap)
	{
		*ppLinkedListMap = (linkedListMap*)calloc(1, sizeof(linkedListMap));
		(*ppLinkedListMap)->size = HASH_SIZE;	
		(*ppLinkedListMap)->key = (linkedList**)calloc(HASH_SIZE, sizeof(linkedList*));
		(*ppLinkedListMap)->val = (linkedList**)calloc(HASH_SIZE, sizeof(linkedList*));
	}
	int hashCode = hashDiv(key);
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

int getDivLinkedList(linkedListMap *pLinkedListMap, int key)
{
	if(!pLinkedListMap)
	{
		printf("map is null\n");
		return -1;
	}
	int hashCode = hashDiv(key);
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
