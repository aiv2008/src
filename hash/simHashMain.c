#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sim_hash.h"


int calN(int n)
{
	int sum = 1;
	while(n)
	{
		sum *= n--;
	}
	return sum;
}

int main(void)
{
    srand(time(0));

	int a[] = {-1,2,-1};
	int size = sizeof(a)/sizeof(a[0]);
	int totalSize = calN(size);
	simHash* pHash = NULL;
	int i;
	for(i=0;i<size;i++)
	{
		simHashPush(&pHash, a[i], simHashGet(&pHash, a[i])+1);
	}	
	for(i=0;pHash!=NULL&&i<pHash->size;i++)
	{
		int count = simHashGet(&pHash, i);
		if(count>0)
		{
			totalSize = totalSize/calN(count);
		}
	}
	free(pHash);
	pHash = NULL;	
	return 0;
}
