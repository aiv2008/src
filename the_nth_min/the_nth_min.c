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
	if(iMin < 0 || iMin > end - start + 1) 
	{
		printf("iMin must in the right interval\n");
		return;
	}
	//printf("\n---before partition---\n");
	//int k;
	//for(k=0;k<=end;k++)printf("%d,", *(array+k));
	//printf("\n");
	//printf("start=%d, end=%d, iMin=%d\n", start, end, iMin);
    	if(iMin > 0 && iMin <= end - start + 1 && start < end)
	{
		int partitionIndex = myRandomizedPartition(array, start, end);
		//printf("\n---after partition---\n");
		//printf("partitionIndex=%d\n", partitionIndex);
		//for(k=0;k<=end;k++)printf("%d,", *(array+k));
		//printf("\n");
		//k is the index of the elem between the interval start to partitionIndex
		int coef = partitionIndex - start + 1;
		if(iMin < coef)
		{
			//printf("enter111\n");
			randomizedSelect(array, start, partitionIndex - 1, iMin);
		}
		else if(iMin > coef)
		{
			//printf("enter222\n");
			randomizedSelect(array, partitionIndex + 1, end, iMin - coef );
		}
	}
}
