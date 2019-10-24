#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"binary_tree_breadth_first_search.h"
#include "../binary_tree/binary_tree.h"
#include "../queue/my_queue_linkedlist.h"


void binaryTreeBreadthFirstTree(myBinrayTreeNode* pRoot)
{
    if(!pRoot)
    {
        printf("tree is null\n");
        return;
    }
    myQueue** ppMyQueue = (myQueue**)calloc(1, sizeof(myQueue*));
    queuePush(ppMyQueue, pRoot, sizeof(myBinrayTreeNode));
//    myQueueElem* bottom = queueBottom(*ppMyQueue);
    myQueueElem* top = '\0';
    myBinrayTreeNode* root = '\0';
    myBinrayTreeNode* left ='\0';
    myBinrayTreeNode* right ='\0';
    while((*ppMyQueue)->bottom)
    //myQueueElem* pMove = queueTop(*ppMyQueue);
    //while(pMove != (*ppMyQueue)->bottom)
    {
        top = queueTop(*ppMyQueue);
        root = (myBinrayTreeNode*)(top->data);
        printf("top=%d\n",root->data);
        left = root->left;
        right = root->right;
        if(left)queuePush(ppMyQueue, left, sizeof(myBinrayTreeNode));
        if(right)queuePush(ppMyQueue, right, sizeof(myBinrayTreeNode));
        //pMove = pMove->pNext;
        queuePop(*ppMyQueue);
    }
    freeQueue(ppMyQueue);
}
