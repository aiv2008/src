#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"/home/anson/git-resp/src/quicksort/quicksort.h"
#include"../hash/sim_hash.h"

int main(void)
{
	int i;
	/**
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
**/

	int a[] = {9,4,17,7,13,19,3,1,14,15,10,16,6,18,0,11,5,12,2,8};
	int size = sizeof(a)/sizeof(a[0]);


//	myQuicksort(a, 0, size-1);
	myRandomizedQuicksort(a, 0, size-1);
	
	for(i=0;i<size;i++)
	{
		printf("%d,", a[i]);
	}
	printf("\n");
	return 0;
}
