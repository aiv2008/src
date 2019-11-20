#include<stdio.h>
#include<stdlib.h>
#include"my_hash.h"

int main(void)
{
	int a[] = {1,1,2,17,18,17,19,20,18};
	//int a[] = {1,1,18,18};
	int size = sizeof(a)/sizeof(a[0]);
	int i;
	linkedListMap *pLinkedListMap = NULL;
	for(i=0;i<size;i++)
	{
		int count = getDivLinkedList(pLinkedListMap, a[i]);
//		printf("val=%d, count=%d\n", a[i], count);
		if(count==-1)
			pushDivLinkedList(&pLinkedListMap, a[i], 1);
		else
			pushDivLinkedList(&pLinkedListMap, a[i], count+1);
	}

	for(i=0;i<size;i++)
		printf("a=%d, count=%d\n",a[i],  getDivLinkedList(pLinkedListMap, a[i]));
	printf("\n");

	return 0;
}
