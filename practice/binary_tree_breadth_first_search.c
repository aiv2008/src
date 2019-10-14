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
    myQueue** ppMyQueue = (myQueue**)calloc(1, sizeof(myQueue*));
    int binaryTreeSize = 3*sizeof(myBinrayTreeNode*) + sizeof(unsigned int);
    queuePush(ppMyQueue, pRoot, binaryTreeSize);
    while((*ppMyQueue)->size)
    {
        myBinrayTreeNode* top = (myBinrayTreeNode*)queueTop(*ppMyQueue);
        printf("top=%d\n",top->data);
        myBinrayTreeNode* left = top->left;
        myBinrayTreeNode* right = top->right;
        printf("size11=%d\n",(*ppMyQueue)->size);
        if(left)queuePush(ppMyQueue, left, binaryTreeSize);
        if(right)queuePush(ppMyQueue, right, binaryTreeSize);
        printf("size22=%d\n",(*ppMyQueue)->size);
        queuePop(*ppMyQueue, binaryTreeSize);

    }
    free((*ppMyQueue)->top);
    (*ppMyQueue)->top = '\0';
    free(*ppMyQueue);
    *ppMyQueue = '\0';
    free(ppMyQueue);
    ppMyQueue = '\0';
}

int main(void)
{
    srand(time(0));
    int size = 23;
    int a[size];

    myQueue** ppMyqueue = (myQueue**)calloc(1, sizeof(myQueue*));
    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,", a[i]);
        queuePush(ppMyqueue, &a[i], sizeof(int));
    }
    printf("\n");
    while((*ppMyqueue)->size)
    {
        int* top = (int*)queueTop(*ppMyqueue);
        printf("top=%d\n",*top);
        queuePop(*ppMyqueue, sizeof(int));
    }

//    myBinrayTreeNode** ppRoot = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));
////    myBinrayTreeNode** ppRoot = '\0';
//    for(int i=0;i<size;i++)
//    {
//        binaryTreeAdd(ppRoot, a[i]);
//    }
//    binaryTreeBreadthFirstTree(ppRoot?*ppRoot:'\0');
//    if(ppRoot)
//    {
//        freeBinaryTree(ppRoot);
//        free(ppRoot);
//        ppRoot = '\0';
//    }


    return 0;
}
