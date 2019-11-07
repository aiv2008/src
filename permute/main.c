#include<stdio.h>
#include<stdlib.h>
#include"permute.h"

int main(void)
{
	int nums[] = {2,1,2,3,7,21};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int size = 0;
	
	printf("aaa\n");
	int** result = permute(nums, numsSize, &size, NULL);
	printf("aaa\n");
	if(!result)
	{
		printf("result is null\n");
	}
	else
	{
		if(!*result)printf("*result is null\n");
	}
	printf("%d\n", size);
	int i;
	for(i=0;i<size;i++)
	{
		int j;
		for(j=0;j<numsSize;j++)
			printf("%d,", *(*(result+i)+j));
		printf("\n");
	}
	return 0;
}
