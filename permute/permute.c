#include<stdio.h>
#include<stdlib.h>
#include"permute.h"

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if(!nums)return NULL;

}

void permution(int* nums, int numsSize,int beginIndex, int** result)
{
	if(NULL == nums)return;
					
}

int calN(int n)
{
	printf("n=%d,", n);
	if(n > 0)
	{
		printf("aaa\n");
		return n * calN(n-1);	
	}
	printf("bbb\n");
	return 1;
}

int main(void)
{
	int n=20;
	printf("%d\n", calN(n));
	return 0;
}
