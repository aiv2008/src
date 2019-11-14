#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include"all_domain_hash.h"

/**
int adHash(adHashFunc** ppAdHashFunc, int key, int* nums, int numsSize)
{
	if( !nums || !numsSize || !ppAdHashFunc )return -1;
	if(!*ppAdHashFunc)
	{

		*ppAdHashFunc = (adHashFunc*)calloc(1, sizeof(adHashFunc));
		int factorFlag = 0;
		int prime = max;
		while(1)
		{
		
			int i = (int)sqrt(1.0*prime);
			int j = 0;
			while(j++ < i)
				if(prime % j == 0)
				{
					factorFlag = 1;
					break;
				}
			if(factorFlag)break;
			prime++;	
		}
		(*ppAdHashFunc)->p = prime;
		(*ppAdHashFunc)->a = 1 + rand()%(prime-1);
		(*ppAdHashFunc)->b = rand()%prime;
	}
	return ((*ppAdHashFunc)->a*key + (*ppAdHashFunc)->b) % (*ppAdHashFunc)->p % n;
}

void adHashPush(adHash** ppAdHash, int key, int value)
{
	if(!ppAdHash)return ;
	if(!*ppAdHash)
	{
		*ppAdHash = (adHash*)calloc(1, sizeof(adHash));

	}
}
**/

void getMaxMin(int* nums, int numsSize, int* max, int* min)
{
	if(!nums||!numsSize)return;
	int i;
	if(numsSize%2 == 0)
	{
		*max = *nums <= *(nums+1) ? *(nums+1) : *nums;
		*min = *max == *nums ? *(nums+1) : *nums;
		i = 2;
	}
	else
	{
		*max = *nums;
		*min = *nums;
		i = 1;
	}
	for(;i<numsSize;i+=2)
	{		
		int maxLocal = *nums <= *(nums+i+1) ? *(nums+i+1) : *(nums+i);
		int minLocal = maxLocal == *(nums+i) ? *(nums+i+1) : *(nums+i);
		*max = *max < maxLocal ? maxLocal : *max;
		*min = *min > minLocal ? minLocal : *min;
	}	
}

int main(void)
{
	int a[] = {1};
	int size = sizeof(a)/sizeof(a[0]);
	int max = 0;
	int min = 0;
	getMaxMin(a, size, &max, &min);
	printf("max=%d, min=%d\n", max, min);
	return 0;

}
