#include<stdio.h>
#include<stdlib.h>

void assemble(int* nums, int numsSize)
{

}

void assembleRecursion(int* pBegin, int* pEnd, int* pSize)
{
	if(!*pSize)
	{
		int* pMove = pBegin;
		while(pMove!=pEnd)
			printf("%d,", *pMove);
		printf("\n");
	}
	else 
	{
		
	}

}
