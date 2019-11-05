#include<stdio.h>
#include<stdlib.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if(!nums || !numsSize)return NULL;
	int size = calN(numsSize);
	int** result = (int**)calloc(size, sizeof(int*));
	int** ppMove = (int**)calloc(size, sizeof(int*));
	permutation(nums, nums, numsSize, result, size, &ppMove);
	returnSize = &size;
	return result;	
}

void permutation(int* pStr, int* pBegin, int size, int** result,int resultSize, int*** pppMove)
{
	printf("ggg\n");
	if(*pppMove - result > resultSize)return;
	printf("hhh\n");
	if(pBegin - pStr == size)
	{
		printf("aaa\n");
		if(!*pppMove)printf("*pppMove is null\n");
		**pppMove  = (int*)calloc(size, sizeof(int));
		printf("bbb\n");
		int i;
		int* pMove = **pppMove;
		int* p = pStr;
		printf("ccc\n");
		for(i=0;i<size;i++)	
		{
			*(pMove+i) = *(p+i);
			printf("%d,",*(pMove+i));
		}
		printf("\n");
		printf("ddd\n");
		(*pppMove)++;
		printf("fff\n");
	}
	else
	{
		int* pMove ;
		int i;
		for(pMove = pBegin; pMove - pBegin < size; ++pMove)
		{
			printf("---before---\n");
			printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			int temp = *pMove;
			*pMove = *pBegin;
			*pBegin = temp;
			printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			permutation(pStr, pBegin+1, size, result,resultSize, pppMove);
			printf("---after---\n");
			printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
			temp = *pBegin;
			*pMove = *pBegin;
			*pBegin = temp;
			printf("*pMove=%d,*pBegin=%d\n", *pMove, *pBegin);
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

int main(void)
{
	int nums[] = {1,2,3};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int* size = NULL;
	int** result = permute(nums, numsSize, size, NULL);
	int i;
	for(i=0;i<size;i++)
	{
		int j;
		for(j=0;j<numsSize;j++)
			printf("", *(*(result+i)+j));
		printf("\n");
	}
	return 0;
}
