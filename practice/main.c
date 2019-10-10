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
//    size_t size = 10;
//    int a[size];

    int a[] = {4,3,2,1,8,7,6,5};
    int size = sizeof(a)/sizeof(a[0]);

    myBinrayTreeNode** pp_root = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));

    for(int i=0;i<size;i++)
    {
//        a[i] = rand()%size;
        printf("%d,",a[i]);
        add(pp_root, a[i]);
    }
    printf("\n");

    mirrorLooply( *pp_root);
    preOrderIterator( *pp_root);
    return 0;
}
