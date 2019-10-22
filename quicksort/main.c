#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"/home/anson/git-resp/src/quicksort/quicksort.h"

int main(void)
{
	
	srand(time(0));
	int size = 20;
	int a[size];
	int i;
	for(i=0;i<size;i++)
	{
		a[i] = rand()%size;
		printf("%d,", a[i]);
	}
	printf("\n");
	


	//int a[] = {6,3,10,10,17,8,18,2,18,2,1,8,16,16,0,13,13,0,1,17};
	//int size = sizeof(a)/sizeof(a[0]);


	myQuicksort(a, 0, size-1);
	int i;	
	for(i=0;i<size;i++)
	{
		printf("%d,", a[i]);
	}
	printf("\n");
	return 0;
}
