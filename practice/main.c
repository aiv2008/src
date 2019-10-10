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

    int a[] = {8,7,6,5,4,3,2,1};
    int size = sizeof(a)/sizeof(a[0]);

    myBinrayTreeNode** pp_root = (myBinrayTreeNode**)calloc(1, sizeof(myBinrayTreeNode*));
//    myBinrayTreeNode** pp_root = '\0';

    for(int i=0;i<size;i++)
    {
//        a[i] = rand()%size;
        printf("%d,",a[i]);
        add(pp_root, a[i]);
    }
    printf("\n");

    if(pp_root)
    {
        printf("---before mirror begin---\n");
        inOrderIterator(*pp_root);
        printf("---before mirror end---\n");

        if(*pp_root)mirrorRecursively(*pp_root);

        printf("---after mirror begin---\n");
        inOrderIterator(*pp_root);
        printf("---after mirror end---\n");
    }

    return 0;
}
