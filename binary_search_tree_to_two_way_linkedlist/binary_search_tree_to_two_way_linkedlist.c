#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree_to_two_way_linkedlist.h"
#include "../queue/my_queue_linkedlist.h"
#include "../binary_tree/binary_tree.h"


myBinrayTreeNode* convert(myBinrayTreeNode* pRoot)
{
	myBinrayTreeNode* pLastNode = NULL;
	convertNode(pRoot, &pLastNode);

	myBinrayTreeNode* pHeadNode = pLastNode;
	while(pHeadNode && pHeadNode->left)
		pHeadNode = pHeadNode->left;
	return pHeadNode;
}


void convertNode(myBinrayTreeNode* pNode, myBinrayTreeNode** ppLastNode)
{
	if(!pNode)return;
	myBinrayTreeNode* pCurrent = pNode;
	//get the minumum node
	if(pCurrent->left)
		convertNode(pCurrent->left, ppLastNode);
	//form the two-way linkedlist
	pCurrent->left = *ppLastNode;
	if(*ppLastNode)
		(*ppLastNode)->right = pCurrent;
	*ppLastNode = pCurrent;

	if(pCurrent->right)
		convertNode(pCurrent->right, ppLastNode);
}





void bstTo2WayLinkedlist(myBinrayTreeNode* pRoot, myBinrayTreeNode** pLast)
{
	if(!pRoot)return;
	myBinrayTreeNode* pMove = pRoot;
	myBinrayTreeNode* pLeft = pRoot->left;
	if(pLeft)
		bstTo2WayLinkedlist(pLeft, pLast);
	
}


