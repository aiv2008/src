#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binary_search_tree_to_two_way_linkedlist.h"
#include "../queue/my_queue_linkedlist"

void binarySearchTreeToTwoWayLinkedList(myBinaryTreeNode* root)
{
	if(root == NULL)
	{
		printf("tree root cannot be null\n");
		return;
	}
	myQueue** ppMyQueue = (myQueue**)calloc(1, sizeof(myQueue*));
	myQueueElem* top = NULL;
	myQueueElem* bottom = NULL;
	do
	{
		myBinaryTreeNode* left = root->left;
		myBinaryTreeNode* right = root->right;
		queuePush(ppMyQueue, root, sizeof(myBinaryTreeNode*));
		
		if(left)queuePush(ppMyQueue, left , sizeof(myBinaryTreeNode*));
		if(right)queuePush(ppMyQueue, right , sizeof(myBinaryTreeNode*));
		queuePop(ppMyQueue);
		top = queueTop(ppMyQueue);
		bottom = queueBottom(ppMyQueue);
	}
	while(top != bottom);

}
