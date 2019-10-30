#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"binary_tree.h"

int main(void)
{
	srand(time(0));
	int i;
	int size=10;
	int a[size];
	for(i=0;i<size;i++)
	{
		a[i]=rand()%size;
		printf("%d,", a[i]);
	}
	myBinrayTreeNode** ppRoot = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*)); 
	//simHash** ppsimHash = (simHash**)calloc(1, sizeof(simHash*));	
	for(i=0;i<size;i++)
	{
		binaryTreeAdd(ppRoot, a[i]);
	}
	myBinrayTreeNode *pMax = NULL;
	pMax = binaryTreeMaximum(*ppRoot);
	myBinrayTreeNode *pMin = NULL;
	pMin = binaryTreeMinimum(*ppRoot);
	printf("max=%d, min=%d\n", pMax->data, pMin->data);
	
	return 0;
}
