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
//    int binaryTreeSize = 3*sizeof(myBinrayTreeNode*) + sizeof(unsigned int);
    int binaryTreeSize = sizeof(myBinrayTreeNode);
    queuePush(ppMyQueue, pRoot, binaryTreeSize);
    while((*ppMyQueue)->size)
    {
        myBinrayTreeNode* top =  (myBinrayTreeNode*)queuePop(*ppMyQueue, binaryTreeSize);
        if(!top)
        {
            printf("top is null\n");
            break;
        }
//        myBinrayTreeNode* top = (myBinrayTreeNode*)queueTop(*ppMyQueue);
        printf("top=%d\n",top->data);
        myBinrayTreeNode* left = top->left;
        myBinrayTreeNode* right = top->right;
        if(left)queuePush(ppMyQueue, left, binaryTreeSize);
        if(right)queuePush(ppMyQueue, right, binaryTreeSize);
//        queuePop(*ppMyQueue, binaryTreeSize);
//        printf("size33=%d\n",(*ppMyQueue)->size);
    }

//    if(ppMyQueue)
//    {
//        if(*ppMyQueue)
//        {
//            if((*ppMyQueue)->top)
//            {
//                free((*ppMyQueue)->top);
//                (*ppMyQueue)->top = '\0';
//            }
//            free(*ppMyQueue);
//            *ppMyQueue = '\0';
//        }
//        free(ppMyQueue);
//        ppMyQueue = '\0';
//    }

}

//int main(void)
//{
////    srand(time(0));
////    int size = 20;
////    int a[size];
//
//    int a[] = {9,7,18,9,8,14,16,17,3,3,12,6,10,7,6,17,5,14,11,9};
//    int size = sizeof(a)/sizeof(a[0]);
//
//    myBinrayTreeNode** ppRoot = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));
////    myBinrayTreeNode** ppRoot = '\0';
//    for(int i=0;i<size;i++)
//    {
////        a[i] = rand()%size;
////        printf("%d,", a[i]);
//        binaryTreeAdd(ppRoot, a[i]);
//    }
//    printf("\n");
//    binaryTreeBreadthFirstTree(ppRoot?*ppRoot:'\0');
////    if(ppRoot)
////    {
////        freeBinaryTree(ppRoot);
////        free(ppRoot);
////        ppRoot = '\0';
////    }
//    return 0;
//}
