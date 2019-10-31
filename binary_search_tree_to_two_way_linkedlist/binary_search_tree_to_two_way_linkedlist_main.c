#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "binary_search_tree_to_two_way_linkedlist.h"
#include "../binary_tree/binary_tree.h"

int main(void)
{
	int i;
/**
	srand(time(0));
	int size = 10;
	int a[100];
	**/
	int a[] = {2,7,6,5,1,4,5,6,0,7};
	int size = sizeof(a)/sizeof(a[0]);
	for(i=0;i<size;i++)
	{
		//a[i] = rand()%size;
		printf("%d,", a[i]);
	}
	printf("\n");
	myBinrayTreeNode** ppRoot = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));
	for(i=0;i<size;i++)
	{
		binaryTreeAdd(ppRoot, a[i]);
	}
	
	//binarySearchTreeToTwoWayLinkedList(*ppRoot);
	//printTwoWayLinkedList(*ppRoot);

	myBinrayTreeNode* pNode = convert(*ppRoot);
	printf("node=%d\n", pNode->data);
	
	myBinrayTreeNode* pMove = pNode;
	while(pMove)
	{
		myBinrayTreeNode* pLeft = pMove->left;
		if(pLeft)printf("%d", pLeft->data);
		else printf("NULL");		
		printf("<-->");
		printf("%d",pMove->data);
		printf("\n");
		pMove = pMove->right;
	}	
	return 0;
}
