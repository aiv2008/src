#include <stdio.h>
#include <stdlib.h>
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
			return i+1;
		}
		else
		{
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
