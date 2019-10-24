#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../common/common.h"
#include "quicksort.h"

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
/**
	int k;
	printf("\n---before swap---\n");
	for(k=0;k<=end;k++)printf("%d,", *(array+k));
	printf("\n");
**/
	if(j < end)
	{
		while(j < end)
		{			
			if(*(array+j) <= *(array+end))
			{
				i++;
				if(i != j)
				{
					swap_1(array+j, array+i);
				}		
			}				
			j++;
		}
		if(i+1 != end)
		{			
			swap_1(array+i+1, array+end);	
/**
			printf("\n---after swap111---\n");
			for(k=0;k<=end;k++)printf("%d,", *(array+k));
			printf("\n");	
**/
			return i+1;
		}
		else
		{
/**
			printf("\n---after swap222---\n");
			for(k=0;k<=end;k++)printf("%d,", *(array+k));
			printf("\n");
**/
			return end;
		}	
		
	}
	return -1;
}

void myQuicksort(int* array, int start, int end)
{
	if(array == '\0')
	{
		printf("array cannot be null\n");
		return ;
	}
	if(start < end)
	{	    
		//printf("start=%d, end=%d\n", start, end);
		int partitionIndex = myPartition(array, start, end);
		//printf("partitionIndex=%d\n", partitionIndex);
		//printf("partitionValue=%d\n", *(array+partitionIndex));
		if(partitionIndex < 0)
		{
		    printf("partitionIndex must larger than 0\n");
		    return ;
		}
		myQuicksort(array, start, partitionIndex-1);
		myQuicksort(array, partitionIndex+1, end);
	}
}

int myRandomizedPartition(int* array, int start, int end)
{
	if(start < 0)
	{
		printf("quicksort myRandomizedPartition: index must begin with 1\n");
		return -1;
	}
	//printf("start=%d,end=%d\n", start, end);
	if(start > end)
	{
		printf("quicksort myRandomizedPartition: start must smaller than end\n");
		return -1;
	}
	srand(time(0));
	int randIndex = start + rand()%(end - start + 1);
	//printf("randIndex=%d\n", randIndex);
	if(randIndex != end)swap_1(array+randIndex, array+end);
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
		//printf("partition=%d\n", *(array + partitionIndex));
		if(partitionIndex < 0)
		{
		    printf("quicksort myRandomizedQuicksort: partitionIndex must larger than 0\n");
		    return ;
		}
		myRandomizedQuicksort(array, start, partitionIndex-1);
		myRandomizedQuicksort(array, partitionIndex+1, end);
	}
}
