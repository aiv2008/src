#include <stdio.h>
#include "swap_l_r_node.h"
#include <stdlib.h>

void swap_l_r_node(p_p_tree tree_param)
{
    if(!tree_param||!(*tree_param)->data||!(*tree_param)->size)printf("header cannot be null");
    p_tree ptree = *(tree_param);
//    printf("header===%d\n",ptree->data);
    size_t size = ptree->size;
    size_t index = size/2;
    for(int i=1;i<=index;i++)
    {
        size_t l_index = i << 1;
        size_t r_index = -~(i<<1);
//        printf("--before---\n");
//        printf("l_index=%d,",l_index);
//        printf("l_value=%d,",*(ptree->data+l_index-1));
//        printf("r_index=%d,",r_index);
//        printf("r_value=%d\n",*(ptree->data+r_index-1));
        if(r_index<=size)
            swap_1(ptree->data+l_index-1, ptree->data+r_index-1);
//        printf("--after---\n");
//        printf("l_index=%d,",l_index);
//        printf("l_value=%d,",*(ptree->data+l_index-1));
//        printf("r_index=%d,",r_index);
//        printf("r_value=%d\n",*(ptree->data+r_index-1));
    }
}

void swap_1(int* x, int* y)
{
    *x = *x^*y;
	*y = *x^*y;//(*x^*y)^*y=*x(原值)
	*x = *x^*y;//(*x^*y)^((*x^*y)^*y)=*y（原值）
}

void init_node(p_p_tree pptree, int* header, size_t size)
{
    if(!header)printf("header cannot be null");
    if(!size)printf("size cannot be zero");
    if(!pptree)printf("pptree cannot be null");
//    printf("header===%d\n",*(header+1));
    *pptree = (p_tree)calloc(1, sizeof(int*)+sizeof(size_t));
    (*pptree)->data = header;
    (*pptree)->size = size;
}

int main(void)
{
    int a[] = {4,5,2,6,7,8,2,1};
    p_p_tree pptree = (p_p_tree)calloc(1,sizeof(p_tree));
    p_tree ptree = *pptree;
    const int size_1 = sizeof(a)/sizeof(a[0]);
    printf("size1===%d,",size_1);
    init_node(pptree, a, size_1);
    printf("size2===%d,",size_1);
//    printf("header===%d\n",*((*pptree)->data));
    swap_l_r_node(pptree);
//    printf("size3===%d,",sizeof(a)/sizeof(a[0]));
    //size的值为啥会改变?
//    printf("size4===%d\n",size_1);
//    printf("%d,",a[2]);

    for(int i=0;i<size_1;i++)printf("%d,",a[i]);
    return 0;
}
