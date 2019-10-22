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
				printf("*(array+j)=%d, *(array+end)=%d\n", *(array+j), *(array+end));
				i++;
				if(i != j)
				{
					int k;
					printf("\n---begin swap j and end---\n");
					//printf("a[%d]=%d,a[%d]=%d\n",i, *(array+i), j, *(array+j));
					for(k=0;k<end-start+1;k++)printf("%d," , *(array+k));
					printf("\n");
					swap_1(array+j, array+i);
					printf("---after swap j and end---\n");
					//printf("a[%d]=%d,a[%d]=%d\n",i, *(array+i), j, *(array+j));
					for(k=0;k<end-start+1;k++)printf("%d," , *(array+k));
				}		
			}				
			j++;
		}
		if(i+1 != end)
		{
			int k;
			printf("\n---begin swap i+1 and end---\n");
			//printf("a[%d]=%d,a[%d]=%d\n",i+1, *(array+i+1), end, *(array+end));
			for(k=0;k<end-start+1;k++)printf("%d," , *(array+k));
			printf("\n");
			printf("i+1=%d,end=%d\n", i+1, end);
			swap_1(array+i+1, array+end);
			printf("---after swap i+1 and end---\n");
			//printf("a[%d]=%d,a[%d]=%d\n",i+1, *(array+i+1), end, *(array+end));
			for(k=0;k<end-start+1;k++)printf("%d," , *(array+k));		
			return i+1;
		}
		else
		{
			return end;
		}
			
		
	}
	printf("\n");
	return -1;
}

void myQuicksort(int* array, int start, int end)
{
    if(array == '\0')
    {
	printf("array cannot be null\n");
	return ;
    }
    if(end - start + 1 <= 2 && *(array+start) > *(array+end))
	swap_1(array+start, array+end);
    else
    {	
	if(start < end)
	{	    
		printf("start=%d, end=%d\n", start, end);
		int partitionIndex = myPartition(array, start, end);
		printf("partitionIndex=%d\n", partitionIndex);
		if(partitionIndex < 0)
		{
		    printf("partitionIndex must larger than 0\n");
		    return ;
		}
		myQuicksort(array, start, partitionIndex-1);
		myQuicksort(array, partitionIndex+1, end);
	}
    }
    
}
