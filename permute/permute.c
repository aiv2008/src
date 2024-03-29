#include<stdio.h>
#include<stdlib.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if(!nums || !numsSize)return NULL;
	int size = calN(numsSize);
	int** result = (int**)calloc(size, sizeof(int*));
	int** resultMove = result;
	int* columnSizes = (int*)calloc(size, sizeof(int));
	int* columnSizesMove = columnSizes;
	permutation(nums, nums, numsSize, &resultMove, &columnSizesMove);
	//printf("size=%d\n", size);
	int i;
	for(i=0;i<size;i++)
		printf("%d,", *(columnSizes+i));
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
			//printf("---before---\n");
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			int temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
			//printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			permutation(pStr, pBegin+1, size, pppMove, columnSizesMove);
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
	int sum=1;
	while(n)
	{
		sum *= n--;
	}
	return sum;
}

