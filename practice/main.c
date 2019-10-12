#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"mirror_recursively_binaryTree.h"

#define BOOL int
#define TRUE 1
#define FALSE 0

int main(void)
{
//    srand(time(0));
//    size_t size = 2000;
//    int a[size];

    int a[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(a)/sizeof(a[0]);

    myBinrayTreeNode** pp_root = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));
    myBinrayTreeNode** pp_root2 = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));

    for(int i=0;i<size;i++)
    {
//        a[i] = rand()%size;
//        printf("%d,",a[i]);
        add(pp_root, a[i]);
        add(pp_root2, a[i]);
    }
    printf("\n");

    printf("---use loop begin---\n");
    mirrorLooply( *pp_root);
    inOrderIterator( *pp_root);
    printf("\n---use loop end---\n");

    printf("---use Recursive begin---\n");
    mirrorRecursively(*pp_root2);
    inOrderIterator( *pp_root2);
    printf("\n---use Recursive end---\n");
    return 0;
}
