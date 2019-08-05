#include <stdio.h>
#include <stdlib.h>
#include "balance_binary_tree.h"

#define ONE 1

int main()
{
    srand(time(NULL));
    size_t size = 50;
    int a[size];

//    int a[] = {16,2,16,17,5,17,11,10,41,18,28,36,20,24,38,6,14,4,15,38,37,7,19,9,10,45,20,17,20,42,18,45,20,13,17,4,27,9,3,45,17,40,38,34,12,25,33,11,29,45};
//    size_t size = sizeof(a)/sizeof(a[0]);

    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
        printf("%d,",a[i]);
    }

    NODE* root = balanced_tree_init(a,size);

    printf("\n");
    printf("root data is :%d",root->data);
    printf("\n");
    tree_forward_all(root);
    printf("\n");
    tree_backward_all(root);
    printf("\n");
    unsigned int rand_variable = rand()%size;
    printf("rand_variable===%d\n",rand_variable);
    printf("the count of the input data is %d\n",tree_search(root,rand_variable));

    return 0;
}
