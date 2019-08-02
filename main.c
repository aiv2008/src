#include <stdio.h>
#include <stdlib.h>
#include "balance_binary_tree.h"

#define ONE 1
int main()
{
    srand(time(NULL));

//    size_t size = 50;
//    int a[size];

//    int a[] = {37,27,14,20,20,17,35,20,1,22,26,42,39,23,15,23,14,37,37,5,5,6,20,28,41,25,9,10,15,23,46,25,35,44,13,31,25,1,37,17,33,40,18,38,29,46,23,46,6,36};
    int a[] = {37,27,14,20,20,17,35,20,1,22,26,42,39,23,15,23,14,37,37,5};
    size_t size = sizeof(a)/sizeof(a[0]);


    for(int i=0;i<size;i++)
    {
//        a[i] = rand()%size;
        printf("%d,",a[i]);
    }

//    system("pause");

    NODE* root = NULL;
//    int len = sizeof(a)/sizeof(a[0]);
    for( int i=0;i<size;i++ )
    {
        if( i == 0 )
        {
            root = balanced_node_init(a[0]);
            root->count = ONE;
        }
        else
//            tree_add(root, a[i]);
            root = balanced_tree_add(root,a[i]);
    }

    printf("\n");

    printf("root data is :%d",root->data);
    printf("\n");

    tree_forward_all(root);
    printf("\n");
    tree_backward_all(root);
    printf("\n");
//    tree_search(root, 5);
    return 0;
}
