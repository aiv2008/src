#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int myPartition(int* array, int start, int end)
{
	if(array == '\0')
	{
		printf("array cannot be null\n");
		return -1;
	}
	if(start < 0)
	{
		printf("index must begin with 1\n");
		return -1;
	}
	int i = start - 1;
	int j = start;
	if(j < end)
	{
		while(j < end)
		{
			if(*(array+j) <= *(array+end))
			{
				i++;
				if(i != j)
				{
					swap(array+j, array+i);
				}
			}
			j++;
		}
		if(i+1 != end)
		{
			swap(array+i+1, array+end);
			return i+1;
		}
		else
		{
			return end;
		}

	}
	return -1;
}

int myRandomizedPartition(int* array, int start, int end)
{
	if(start < 0)
	{
		printf("quicksort myRandomizedPartition: index must begin with 1\n");
		return -1;
	}
	if(start > end)
	{
		printf("quicksort myRandomizedPartition: start must smaller than end\n");
		return -1;
	}
	srand(time(0));
    	int randIndex = start + rand()%(end - start);
	if(randIndex != end)swap(array+randIndex, array+end);
	return myPartition(array, start, end);
}

void myRandomizedQuicksort(int* array, int start, int end)
{
	if(array == '\0')
	{
		printf("quicksort myRandomizedQuicksort: array cannot be null\n");
		return ;
	}
	if(start < end)
	{
		int partitionIndex = myRandomizedPartition(array, start, end);
		if(partitionIndex < 0)
		{
		    printf("quicksort myRandomizedQuicksort: partitionIndex must larger than 0\n");
		    return ;
		}
		myRandomizedQuicksort(array, start, partitionIndex-1);
		myRandomizedQuicksort(array, partitionIndex+1, end);
	}
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
			//*(pMove+i) = *(p+i);
			*(**pppMove+i) = *(p+i);
			//printf("%d,",*(pMove+i));
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
		int i=0;
		for(pMove = pBegin; pMove - pStr < size; ++pMove, i++)
		{
			if(i == 0  || *pMove != *pBegin)
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

