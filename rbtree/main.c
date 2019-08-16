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
    size_t size = 100000;
    int a[size];
    size_t rand_size = 2*size;

//    int a[] = {1,6,9,6,3,3,8,5,3,2};
//    int a[] = {1,6,9,6,3};
//    size_t size = sizeof(a)/sizeof(a[0]);


    for(int i=0;i<size;i++)
    {
        a[i] = rand()%rand_size;
//        printf("%d,",a[i]);
    }

    NODE* root = tree_init();
    for(int i=0;i<size;i++)
        root = tree_insert(root, a[i]);
    printf("root is :%d\n",root->data);

//    successor(root);

    int search_rand = rand()%rand_size;
    printf("\n");
    printf("search rand is :%d",search_rand);
    NODE* node = tree_search(root, search_rand);
    print_node(node);
    return 0;
}
