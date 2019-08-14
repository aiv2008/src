#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "rbtree.h"

int main(void)
{
//    unsigned int i=0;
//    i = ~i;//ֱ�Ӱ�ֵȡ��.���Ƕ��������ɱ�ʾ��ֵ
//    printf("unsigned int���ֵ:%u\n", UINT_MAX );
//    printf("unsigned int��Сֵ:%u\n", i );

    srand(time(NULL));
    size_t size = 10;
    int a[size];

//    int a[] = {5,6,2,0,3,5,0,0,4,4,5,6,2,0};
//    int a[] = {5,6,2,0};
//    size_t size = sizeof(a)/sizeof(a[0]);


    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,",a[i]);
    }

    NODE* root = tree_init();
    for(int i=0;i<size;i++)
        root = tree_insert(root, a[i]);
    printf("root is :%d\n",root->data);

    successor(root);
    return 0;
}
