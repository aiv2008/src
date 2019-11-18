#include<stdio.h>
#include<stdlib.h>
#include"my_hash.h"

int main(void)
{
	int a[] = {17,1,2,3,18,20,19};
	int size = sizeof(a)/sizeof(a[0]);
	int i;
	linkedListMap *pLinkedListMap = NULL;
	for(i=0;i<size;i++)
		pushDivLinkedList(&pLinkedListMap, a[i], a[i]);

	for(i=0;i<size;i++)
		printf("%d,",getDivLinkedList(pLinkedListMap, a[i]));
	printf("\n");

	return 0;
}
