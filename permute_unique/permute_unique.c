#include<stdio.h>
#include<stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct
{
    int* hash_array;
    int size;
} simHash;

void simHashPush(simHash** ppsimHash, int key, int value)
{
    if(!ppsimHash)
    {
        printf("hash pointer is null\n");
        return;
    }
    if(!*ppsimHash)
    {
        *ppsimHash = (simHash*)calloc(1, sizeof(simHash));
        (*ppsimHash)->size = 256;
        (*ppsimHash)->hash_array = (int*)calloc((*ppsimHash)->size, sizeof(int));
    }
    *((*ppsimHash)->hash_array + key ) = value;
}

int simHashGet(simHash** ppsimHash, int key)
{
    if(simHashIsNullOrEmpty(ppsimHash)) return 0;
    return *((*ppsimHash)->hash_array + key );
}

BOOL simHashIsNull(simHash** ppsimHash)
{
    return !ppsimHash || !*ppsimHash ;
}

BOOL simHashIsNullOrEmpty(simHash** ppsimHash)
{
    return !ppsimHash || !*ppsimHash || !(*ppsimHash)->size;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if(!nums || !numsSize)return NULL;
	int size = calN(numsSize);
	simHash* pHash = NULL;
	int i;
	for(i=0;i<numsSize;i++)
	{
	//	printf("%d,", *(nums+i));
		simHashPush(&pHash, *(nums+i), simHashGet(&pHash, *(nums+i))+1);
	}
	for(i=0;i<pHash->size;i++)
	{
		int count = simHashGet(&pHash, i);
	//	printf("count=%d,", count);
		if(count>0)
			size = size/calN(count);
	}
	printf("size=%d\n", size);
	int** result = (int**)calloc(size, sizeof(int*));
	int** resultMove = result;
	int* columnSizes = (int*)calloc(size, sizeof(int));
	int* columnSizesMove = columnSizes;
	simHash* pSimHash = NULL;
	permutation(nums, nums, numsSize, &resultMove, &columnSizesMove,&pSimHash );
	for(i=0;i<size;i++)
		printf("%d,", *(columnSizes+i));
	printf("\n");
	*returnSize = size;
	*returnColumnSizes = columnSizes;
	return result;	
}

void permutation(int* pStr, int* pBegin, int size, int*** pppMove, int** columnSizesMove, simHash** ppSimHash)
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
			//*(pMove+i) = *(p+i);
			*(**pppMove+i) = *(p+i);
			//printf("%d,",*(pMove+i));
			//printf("%d,", *(**pppMove+i));
		}
		**columnSizesMove = size;
		//printf("\n");
		(*pppMove)++;
		(*columnSizesMove)++;
	}
	else
	{
		int* pMove ;
		for(pMove = pBegin; pMove - pStr < size; ++pMove)
		{
			if(simHashGet(ppSimHash, *pMove) > 0)continue;
			//printf("---before---\n");
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			int temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			permutation(pStr, pBegin+1, size, pppMove, columnSizesMove,ppSimHash);
			//printf("---after---\n");
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
			simHashPush(ppSimHash, *pMove, 1);
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
		}
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

