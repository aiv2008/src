#include<stdio.h>
#include<stdlib.h>
#include"../quicksort/quicksort.h"

int randomizedSelect(int* array, int start, int end, int iMin)
{
	if(array == '\0')
	{
		printf("randomizedSelect: array cannot be null\n");
		return -1;
	}
    if(iMin > 0 && iMin <= end - start + 1)
	{
		if(start < end)
		{
			int partitionIndex = myRandomizedPartition(array, start, end);
			int coef = partitionIndex - start + 1;
			if(iMin < coef)
			{
				return randomizedSelect(array, start, partitionIndex - 1, iMin);
			}
			else if(iMin > coef)
			{
				return randomizedSelect(array, partitionIndex + 1, end, iMin - coef );
			}
			else
			{
				return *(array + partitionIndex);
			}
		}
		else
		{
			return *(array + end);	
		}
	}
	else
	{
		printf("iMin must in the right interval\n");
		return -1;
	}
}

int theNthMin(int* array, int start, int end, int iMin)
{
	return randomizedSelect(array, start, end, iMin);
}

