#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "rbtree.h"
#define NIL -50000000

int main(void)
{
//    unsigned int i=0;
//    i = ~i;//直接把值取反.就是二进制最大可表示的值
//    printf("unsigned int最大值:%u\n", UINT_MAX );
//    printf("unsigned int最小值:%u\n", i );

    srand(time(NULL));
    size_t size = 100000;
    int a[size];
    size_t rand_size = size;

//    int a[] = {1};
//    size_t size = sizeof(a)/sizeof(a[0]);


    for(int i=0;i<size;i++)
    {
        a[i] = rand()%rand_size;
//        printf("%d,",a[i]);
    }

    NODE* root = tree_init();
    for(int i=0;i<size;i++)
        root = tree_insert(root, a[i]);
    printf("\nroot is :%d\n",root->data);

//    successor(root);
//    successor_for_test(root);

    int search_rand = rand()%rand_size;
    printf("\n");
    printf("search rand is :%d\n",search_rand);

//    NODE* node = tree_search(root, search_rand);
//    print_node(node);

//    int search_rand = 0;
//    printf("\ndelete data is:%d\n",search_rand);

    root = tree_delete(root, search_rand);
//    printf("root after:%d\n",root->data);
//    print_node(root);
//    successor(root);
//    successor_for_test(root);
    NODE* node = tree_search(root, search_rand);
    if(NIL != node->data)
        printf("data hasn`t been deleted!!");
    else
        printf("data deleted!!!");

    return 0;
}
