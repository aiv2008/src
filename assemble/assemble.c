#include<stdio.h>
#include<stdlib.h>

void assemble(int* nums, int numsSize)
{
	if(!nums||!numsSize)return;
	int i;
	for(i=0;i<numsSize;i++)
	{
		assembleRecursion(nums, nums, i+1, numsSize, i+1);
	}	
}

void assembleRecursion(int* pBegin, int* pEnd, int m, int n,int totalM)
{
	if(!m )
	{
//		printf("aaaa\n");
//		int* pMove = pBegin;
		int i;
		for(i=0;i<totalM;i++)
			printf("%d,", *(pBegin+i));
		printf("\n");
	}

	else if(m == n)
	{
//		printf("bbbb\n");
//		printf("m=%d, n=%d\n", m, n);
//		printf("pBegin=%d, pEnd=%d\n", *pBegin, *pEnd);
//		int* pMove = pBegin;
		int i;
		for(i=0;i<totalM;i++)
			printf("%d,", *(pBegin+i));
		printf("\n");
	}

	else 
	{
		assembleRecursion(pBegin, pEnd+1, m-1, n-1,totalM);
/**
		printf("--begin1---\n");
		printf("pEnd+1=%d ,pBegin+%d-1=%d\n", *(pEnd+1), n, *(pBegin+n-1));
**/
		swap(pEnd, pEnd+n-1);
/**
		printf("--after1---\n");
		printf("pEnd+1=%d ,pBegin+%d-1=%d\n", *(pEnd+1), n, *(pBegin+n-1));
**/
		assembleRecursion(pBegin, pEnd, m, n-1,totalM);
/**
		printf("--begin2---\n");
		printf("pEnd+1=%d ,pBegin+%d-1=%d\n", *(pEnd+1), n, *(pBegin+n-1));
**/
		swap(pEnd, pEnd+n-1);
/**
		printf("--after2---\n");
		printf("pEnd+1=%d ,pBegin+%d-1=%d\n", *(pEnd+1), n, *(pBegin+n-1));
**/
	}

}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
