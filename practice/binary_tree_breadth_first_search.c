#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"binary_tree_breadth_first_search.h"
#include "../binary_tree/binary_tree.h"
#include "../queue/my_queue.h"


void binaryTreeBreadthFirstTree(myBinrayTreeNode* pRoot)
{
    if(!pRoot)
    {
        printf("tree is null\n");
        return;
    }
//    printf("pRoot=%d\n", pRoot->data);
    myQueue** ppMyQueue = (myQueue**)calloc(1, sizeof(myQueue*));
    int binaryTreeSize = 3*sizeof(myBinrayTreeNode*) + sizeof(unsigned int);
//    printf("size==%d\n", binaryTreeSize);
    queuePush(ppMyQueue, pRoot, binaryTreeSize);
//    void* topChar = queueTop(*ppMyQueue);
//    printf("binaryTreeBreadthFirstTree: top=%x\n", topChar);
//    myBinrayTreeNode* top = (myBinrayTreeNode*)queueTop(*ppMyQueue);
//    printf("top=%x\n",top);
//    printf("top=%d\n",top->data);
    while((*ppMyQueue)->size)
    {
        myBinrayTreeNode* top = (myBinrayTreeNode*)queueTop(*ppMyQueue);
        printf("top=%d\n",top->data);
        myBinrayTreeNode* left = top->left;
        myBinrayTreeNode* right = top->right;
        if(left)queuePush(ppMyQueue, left, binaryTreeSize);
//        printf("queue size after add left=%d\n",(*ppMyQueue)->size);
        if(right)queuePush(ppMyQueue, right, binaryTreeSize);
//        printf("queue size after add right=%d\n",(*ppMyQueue)->size);
        queuePop(*ppMyQueue, binaryTreeSize);
//        printf("queue size=%d\n",(*ppMyQueue)->size);
    }
}

int main(void)
{
    srand(time(0));
    int size = 8;
    int a[size];

    myQueue** ppMyqueue = (myQueue**)calloc(1, sizeof(myQueue*));

    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,", a[i]);
        queuePush(ppMyqueue, &a[i], sizeof(int));
        int* top = (int*)queueTop(*ppMyqueue);
        printf("top=%d\n",*top);
    }
    printf("\n");

    while((*ppMyqueue)->size)
    {
        int* top = (int*)queueTop(*ppMyqueue);
        printf("top=%d\n",*top);
        queuePop(*ppMyqueue, sizeof(int));
    }

//    myBinrayTreeNode** ppRoot = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));
//    for(int i=0;i<size;i++)
//    {
//        binaryTreeAdd(ppRoot, a[i]);
//    }
//    binaryTreeBreadthFirstTree(*ppRoot);



    return 0;
}
