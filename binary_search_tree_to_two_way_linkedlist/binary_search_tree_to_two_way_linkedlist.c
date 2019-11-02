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

void myBstTo2WayLinkedlist(myBinrayTreeNode* pRoot)
{	
	if(!pRoot)return;
	myBinrayTreeNode* pMove = NULL;
	myConvert(pRoot, &pMove);
	while(pMove && pMove->left)
		pMove = pMove->left;
	while(pMove)
	{
		printf("%d", pMove->left? ((myBinrayTreeNode*)(pMove->left))->data : -1);
		printf("<-->");
		printf("%d", pMove->data);
		printf("\n");
		pMove = pMove->right;
	}		
}

void myConvert(myBinrayTreeNode* pRoot, myBinrayTreeNode** pMoveLast)
{
	if(!pRoot)return;
	myBinrayTreeNode* pCurr = pRoot;
	myBinrayTreeNode* pLeft = pCurr->left;
	myBinrayTreeNode* pRight = pCurr->right;
	if(pLeft)
		myConvert(pLeft, pMoveLast);
	pCurr->left = *pMoveLast;
	if(*pMoveLast)
		(*pMoveLast)->right = pCurr;
	(*pMoveLast) = pCurr;
	if(pRight)
		myConvert(pRight, pMoveLast);
}


