#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree_to_two_way_linkedlist.h"
#include "../queue/my_queue_linkedlist.h"
#include "../binary_tree/binary_tree.h"

void binarySearchTreeToTwoWayLinkedList(myBinrayTreeNode* root)
{
	if(!root)
	{
		printf("tree root cannot be null\n");
		return;
	}
	myQueue** ppMyQueue = (myQueue**)calloc(1, sizeof(myQueue*));
	myQueueElem* top = NULL;
	myQueueElem* bottom = NULL;
	do
	{
		myBinrayTreeNode* left = root->left;
		myBinrayTreeNode* right = root->right;
		queuePush(ppMyQueue, root, sizeof(myBinrayTreeNode*));
		if(left)
		{
			queuePush(ppMyQueue, left , sizeof(myBinrayTreeNode*));
			myBinrayTreeNode* pMax = binaryTreeMaximum(left);
			root->left = pMax;
			if(pMax)pMax->right = root;
		}
		if(right)
		{
			queuePush(ppMyQueue, right , sizeof(myBinrayTreeNode*));
			myBinrayTreeNode* pMin = binaryTreeMinimum(right);
			root->right = pMin;
			if(pMin)pMin->left = root;
		}
		queuePop(ppMyQueue);
		top = queueTop(ppMyQueue);
		bottom = queueBottom(ppMyQueue);
	}
	while(top != bottom);

}
void printTwoWayLinkedList(myBinrayTreeNode* root)
{
	
	if(!root)
	{
		printf("tree root cannot be null\n");
		return;
	}
	myQueue** ppMyQueue = (myQueue**)calloc(1, sizeof(myQueue*));
	myQueueElem* top = NULL;
	myQueueElem* bottom = NULL;
	do
	{
		myBinrayTreeNode* left = root->left;
		myBinrayTreeNode* right = root->right;
		queuePush(ppMyQueue, root, sizeof(myBinrayTreeNode*));
		printf("root=%d,", root->data);
		if(left)
		{
			printf("left=%d,", left->data);
			queuePush(ppMyQueue, left , sizeof(myBinrayTreeNode*));
		}
		if(right)
		{
			printf("right=%d,", right->data);
			queuePush(ppMyQueue, right , sizeof(myBinrayTreeNode*));
		}
		printf("\n");
		queuePop(ppMyQueue);
		top = queueTop(ppMyQueue);
		bottom = queueBottom(ppMyQueue);
	}
	while(top != bottom);
}
