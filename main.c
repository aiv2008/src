#include <stdio.h>
#include <stdlib.h>
#include "balance_binary_tree.h"

int main()
{
    srand(time(NULL));

//    int a[size];
    int a[] = {3,4,2,6,9,0,1,6,7,2};

    size_t size = sizeof(a)/sizeof(a[0]);
//    for(int i=0;i<size;i++)
//    {
//        a[i] = rand()%size;
//        printf("%d,",a[i]);
//    }

//    system("pause");

    NODE* root = NULL;
//    int len = sizeof(a)/sizeof(a[0]);
    for( int i=0;i<size;i++ )
    {
        if( i == 0 )
//            root = node_init(a[0]);
            root = balanced_node_init(a[0]);
        else
//            tree_add(root, a[i]);
            root = balanced_tree_add(root,a[i]);
    }

//    printf("\n");

    tree_forward_all(root);
    printf("\n");
    tree_backward_all(root);
    printf("\n");
//    tree_search(root, 5);
    return 0;
}
