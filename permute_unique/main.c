#include<stdio.h>
#include<stdlib.h>
#include"permute_unique_ex.h"

int main(void)
{

	int nums[] = {-1,2,-1,2,1,-1,2,1};
	int numsSize = sizeof(nums)/sizeof(nums[0]);
	int size = 0;
	int* columnSizes = NULL;
	int** result = permuteUnique(nums, numsSize, &size, &columnSizes);

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
