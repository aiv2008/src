#include<stdio.h>
#include<stdlib.h>


void permutation(char* pStr, char* pBegin)
{
	if(*pBegin == '\0')
			printf("%s\n", pStr);
	else
	{
		char* pCh;
		for(pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			printf("---befor---\n");
			printf("*pCh=%c,*pBegin=%c\n", *pCh, *pBegin);
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			printf("*pCh=%c,*pBegin=%c\n", *pCh, *pBegin);
			permutation(pStr, pBegin + 1);
			printf("---after---\n");
			printf("*pCh=%c,*pBegin=%c\n", *pCh, *pBegin);
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			printf("*pCh=%c,*pBegin=%c\n", *pCh, *pBegin);
		}
	}		
}



int calN(int n)
{
	printf("n=%d,", n);
	if(n > 0)
	{
		printf("aaa\n");
		return n * calN(n-1);	
	}
	printf("bbb\n");
	return 1;
}

int main(void)
{
	char pCh[] = "ABC";
	permutation(pCh, pCh);
	return 0;
}
