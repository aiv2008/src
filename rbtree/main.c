#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "rbtree.h"

int main(void)
{
//    unsigned int i=0;
//    i = ~i;//直接把值取反.就是二进制最大可表示的值
//    printf("unsigned int最大值:%u\n", UINT_MAX );
//    printf("unsigned int最小值:%u\n", i );

//    srand(time(NULL));
//    size_t size = 10;
//    int a[size];

//    int a[] = {32,18,22,46,23,13,12,7,35,18,30,3,32,7,49,22,26,9,5,20,18,21,8,38,11,14,22,3,13,49,4,5,46,36,27,19,14,30,10,49,24,19,3,20,24,35,13,36,35,9};
    int a[] = {7,3,1};
    size_t size = sizeof(a)/sizeof(a[0]);

    NODE* root = tree_init();

    for(int i=0;i<size;i++)
    {
//        a[i] = rand()%size;
        root = tree_insert(root, a[i]);
        printf("%d,",a[i]);
    }

    printf("root is :%d\n",root->data);

    rbtree_successor(root);
    return 0;
}
