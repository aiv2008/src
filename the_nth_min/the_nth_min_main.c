#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"../hash/sim_hash.h"
#include"the_nth_min.h"

int main(void)
{
	int i;
	int iMin = 6;
	srand(time(0));
	int size = 10;
	int a[size];
	simHash** ppsimHash = (simHash**)calloc(1, sizeof(simHash*));
	for(i=0;i<size;i++)
	{
		a[i] = rand()%size;
		while(simHashGet(ppsimHash, a[i]))
			a[i] = rand()%size;
		simHashPush(ppsimHash, a[i], 1);
		printf("%d,",a[i]);
	}


/**
	int a[] = {0,2,8,7,5,1,3,4,6,9};
	//int a[] = {0,2,1,7,5};
	int size = sizeof(a)/sizeof(a[0]);
**/
	printf("\n");
	int r = randomizedSelect(a, 0, size-1, iMin);
	//theTopNthMin(a, 0, size-1, iMin);
	printf("iMin=%d\n", r);
	for(i=0;i<size;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
}
