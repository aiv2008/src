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
	printf("start=%d, end=%d, iMin=%d\n", start, end, iMin);
	printf("iMin > 0 ? %d\n", iMin > 0);
	printf("iMin <= end - start + 1 ? %d\n", iMin <= end - start + 1);
	//if(start <= iMin && iMin <= end)
    if(iMin > 0 && iMin <= end - start + 1)
	{
		int partitionIndex = myRandomizedPartition(array, start, end);
		printf("\n---after partition---\n");
		printf("partitionIndex=%d\n", partitionIndex);
		for(k=0;k<=end;k++)printf("%d,", *(array+k));
		printf("\n");
		//k is the index of the elem between the interval start to partitionIndex
//		int k = partitionIndex - start + 1;
		int coef = partitionIndex - start + 1;
		if(iMin < coef)
		{
			printf("enter111\n");
//			printf("start=%d, end=%d, iMin=%d\n", start, partitionIndex-1, iMin);
			randomizedSelect(array, start, partitionIndex - 1, iMin);
		}
		else if(iMin > coef)
		{
			printf("enter222\n");
//			printf("start=%d, end=%d, iMin=%d\n", partitionIndex + 1, end, iMin - coef);
			randomizedSelect(array, partitionIndex + 1, end, iMin - coef );
		}
		else
            printf("iMin=%d\n", *(array+iMin-1));
	}
	else
    {
        printf("overflow\n");
    }


}
