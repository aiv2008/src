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

int main(void)
{
	int n = -1;
	printf("%d\n"(unsigned int)n);
	return 0;

}
