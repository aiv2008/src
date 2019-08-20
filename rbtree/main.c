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

//    srand(time(NULL));
//    size_t size = 10;
//    int a[size];
//    size_t rand_size = size;

    int a[] = {5,4,1,8,4,1,4,1,4,8};
    size_t size = sizeof(a)/sizeof(a[0]);


    for(int i=0;i<size;i++)
    {
//        a[i] = rand()%rand_size;
        printf("%d,",a[i]);
    }

    NODE* root = tree_init();
    for(int i=0;i<size;i++)
        root = tree_insert(root, a[i]);
    printf("\nroot is :%d\n",root->data);

//    successor(root);
    successor_for_test(root);

//    int search_rand = rand()%rand_size;
//    printf("\n");
//    printf("search rand is :%d\n",search_rand);

//    NODE* node = tree_search(root, search_rand);
//    print_node(node);

    int search_rand = 4;
    printf("\ndelete data is:%d\n",search_rand);

    root = tree_delete(root, search_rand);
    printf("root after:%d\n",root->data);
//    print_node(root);
//    successor(root);
    successor_for_test(root);
    return 0;
}
