#include<stdio.h>
#include<stdlib.h>
#include "..\binary_tree\binary_tree.h"
#include "..\queue\my_queue.h"

void binaryTreeBreadthFirstTree(myBinrayTreeNode* pRoot)
{
    if(!pRoot)
    {
        printf("tree is null\n");
        return;
    }
    printf("%d,", pRoot->data);
    myQueue** ppMyQueue = (myQueue**)calloc(1, sizeof(myQueue*));
    queuePush(ppMyqueue, pRoot->data);
    while((*ppMyqueue)->size)
    {
        int* top = (*ppMyqueue)->top;

    }
}
