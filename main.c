#include <stdio.h>
#include <stdlib.h>
#include "balance_binary_tree.h"

#define ONE 1

int main()
{
    srand(time(NULL));
    size_t size = 50;
    int a[size];

//    int a[] = {32,18,22,46,23,13,12,7,35,18,30,3,32,7,49,22,26,9,5,20,18,21,8,38,11,14,22,3,13,49,4,5,46,36,27,19,14,30,10,49,24,19,3,20,24,35,13,36,35,9};
//    int a[] = {32,18,22,46,5};
//    size_t size = sizeof(a)/sizeof(a[0]);

    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,",a[i]);
    }

    NODE* root = balanced_tree_init(a,size);

    printf("\n");
    printf("---before delete begin---");
    printf("root data is :%d",root->data);
    printf("\n");
    tree_forward_all(root);
    printf("\n");
    tree_backward_all(root);
    printf("\n");
    printf("---before delete end---");

    root = delete_node(root, 15);

    printf("\n");
    printf("---after delete begin---");
    printf("root data is :%d",root->data);
    printf("\n");
    tree_forward_all(root);
    printf("\n");
    tree_backward_all(root);
    printf("\n");
    printf("---after delete end---");

//    unsigned int rand_variable = rand()%size;
//    printf("rand_variable===%d\n",rand_variable);
//    printf("the count of the input data is %d\n",tree_search(root,rand_variable));



    return 0;
}
