#include<stdio.h>
#include<stdlib.h>

int logSearch(int* nums, int beginIndex, int endIndex, int data)
{
	if(endIndex < beginIndex)return 0;	
	int index = beginIndex + (endIndex - beginIndex)/2;
//	printf("%d\n", index);
	if(*(nums+index) == data)return 1;
	return logSearch(nums, beginIndex, index-1, data) || logSearch(nums, index+1, endIndex, data);
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
/**
	if(!nums || !numsSize)return NULL;
	int size = calN(numsSize);
	simHash* pHash = NULL;
	int i;
	for(i=0;i<numsSize;i++)
	{
		simHashPush(&pHash, *(nums+i), simHashGet(&pHash, *(nums+i))+1);
	}
	for(i=0;i<pHash->size;i++)
	{
		int count = simHashGet(&pHash, i);
		if(count>0)
			size = size/calN(count);
	}
	free(pHash);
	pHash = NULL;
	int** result = (int**)calloc(size, sizeof(int*));
	int** resultMove = result;
	int* columnSizes = (int*)calloc(size, sizeof(int));
	int* columnSizesMove = columnSizes;
	permutation(nums, nums, numsSize, &resultMove, &columnSizesMove );
	*returnSize = size;
	*returnColumnSizes = columnSizes;
	return result;	
**/
}

void permutation(int* pStr, int* pBegin, int size, int*** pppMove, int** columnSizesMove)
{
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
		//	printf("%d,",*(**pppMove+i));
		}
		**columnSizesMove = size;
	//	printf("\n");
		(*pppMove)++;
		(*columnSizesMove)++;
	}
	else
	{
		
		int* pMove ;
		for(pMove = pBegin; pMove - pStr < size; ++pMove)
		{
			int temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
			permutation(pStr, pBegin+1, size, pppMove, columnSizesMove);
			temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
		}
//		free(pHash);
//		pHash = NULL;
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

