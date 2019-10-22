#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"/home/anson/git-resp/src/quicksort/quicksort.h"
#include"../hash/sim_hash.h"

int main(void)
{
	int i;
	
	srand(time(0));
	simHash** ppsimHash = (simHash**)calloc(1, sizeof(simHash*));	
	int size = 20;
	int a[size];	
	while(i<size)
	{
		a[i] = rand()%size;
		//avoid the repeating
		if(!simHashGet(ppsimHash, a[i]))
		{
			simHashPush(ppsimHash, a[i], 1);
			i++;
		}
		//printf("%d is repeated,", a[i]);
	}
	
	for(i=0;i<size;i++)
	{
		printf("%d,", a[i]);
	}
	printf("\n");

/**
	int a[] = {1,0,2,3,4};
	int size = sizeof(a)/sizeof(a[0]);
**/

	myQuicksort(a, 0, size-1);
	
	for(i=0;i<size;i++)
	{
		printf("%d,", a[i]);
	}
	printf("\n");
	return 0;
}
