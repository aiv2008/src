#include<stdio.h>
#include<stdlib.h>
#include"../quicksort/quicksort.h"

void randomizedSelect(int* array, int start, int end, int iMin)
{
	if(array == '\0')
	{
		printf("randomizedSelect: array cannot be null\n");
		return;
	}
	printf("\n---before partition---\n");
	int k;
	for(k=0;k<=end;k++)printf("%d,", *(array+k));
	printf("\n");
	if(start <= iMin && iMin <= end)
	{
		int partitionIndex = myRandomizedPartition(array, start, end);
		printf("\n---after partition---\n");
		printf("partitionIndex=%d\n", partitionIndex);
		for(k=0;k<=end;k++)printf("%d,", *(array+k));
		printf("\n");
		//k is the count of the elem between the interval start to partitionIndex
		int k = partitionIndex - start + 1;
		if(iMin < k)
		{
			printf("enter111\n");
			printf("start=%d, end=%d, iMin=%d\n", start, partitionIndex-1, iMin);
			randomizedSelect(array, start, partitionIndex - 1, iMin);
		}		
		else if(iMin > k)
		{
			printf("enter222\n");
			printf("start=%d, end=%d, iMin=%d\n", partitionIndex + 1, end, iMin - k);
			randomizedSelect(array, partitionIndex + 1, end, iMin - k);
		}
		else
			printf("enter333\n");
	}
	else
		printf("iMin must in the right interval\n");		
	
}
