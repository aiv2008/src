#include<stdio.h>
#include<stdlib.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if(!nums || !numsSize || !returnSize)return NULL;
	int size = calN(numsSize);
	int** result = (int**)calloc(size, sizeof(int*));
	int** resultMove = result;
	//permutation(nums, nums, numsSize, result, size, &result);
	permutation(nums, nums, numsSize, size, &resultMove);
	//printf("size=%d\n", size);
	*returnSize = size;
	return result;	
}

void permutation(int* pStr, int* pBegin, int size, int resultSize, int*** pppMove)
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
		//printf("\n");
		(*pppMove)++;
	}
	else
	{
		int* pMove ;
		for(pMove = pBegin; pMove - pStr < size; ++pMove)
		{
			//printf("---before---\n");
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			int temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			permutation(pStr, pBegin+1, size, resultSize, pppMove);
			//printf("---after---\n");
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
		}
	}				
}


int calN(int n)
{
	if(n>0)
		return n * calN(n-1);
	else
		return 1;
}

