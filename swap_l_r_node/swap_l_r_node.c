#include <stdio.h>
#include "swap_l_r_node.h"
#include <stdlib.h>
#include<math.h>
#include <time.h>

#define bool char
#define true 1
#define false 0

void swap_l_r_node(p_p_tree pptree)
{
    if(is_nul(pptree))printf("header cannot be null");
    size_t size = (*pptree)->size;
    size_t new_size = (size_t)my_log(2, size);
    int begin = 1;
    int end = 0;
//    printf("new_size===%d\n", new_size);
    for(int i=1;i<=new_size;i++)
    {
        if(begin > size)break;
        int range = pow(2,i);
        end = begin + range - 1;
        if(end > size)end=size-1;
        des_sort( pptree, begin, end);
        begin = end + 1;
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
    if(!header||!size||!pptree)printf("tree cannot be null");
    *pptree = (p_tree)calloc(1, sizeof(int*)+sizeof(size_t));
    (*pptree)->data = header;
    (*pptree)->size = size;
}

int main(void)
{
    srand(time(NULL));
    size_t size = 700000;
    size_t a[size];

    for(int i=0;i<size;i++)
    {
        a[i] = rand()%size;
//        printf("%d,",a[i]);
    }
    printf("\n");


//    int a[] = {4,5,2,6,7,8,2,1};
    p_p_tree pptree = (p_p_tree)calloc(1,sizeof(p_tree));
    p_tree ptree = *pptree;
    const int size_1 = sizeof(a)/sizeof(a[0]);
//    printf("size1===%d,",size_1);

    time_t t;    //time_t是一种类型，定义time_t类型的t
    time(&t);    //取得当前时间
    printf("%s\n",ctime(&t));// ctime(&t)将日期转为字符串并打印
    init_node(pptree, a, size_1);
//    printf("size2===%d,",size_1);
//    printf("header===%d\n",*((*pptree)->data));
    swap_l_r_node(pptree);
//    printf("size3===%d,",sizeof(a)/sizeof(a[0]));
    //size的值为啥会改变?
//    printf("size4===%d\n",size_1);
//    printf("%d,",a[2]);
    time(&t);    //取得当前时间
    printf("%s\n",ctime(&t));// ctime(&t)将日期转为字符串并打印
//    for(int i=0;i<size_1;i++)printf("%d,",a[i]);
    return 0;
}

void des_sort(p_p_tree pptree, size_t index_b, size_t index_e)
{
//    printf("index_b===%d,", index_b);
//    printf("index_e===%d\n", index_e);
    if(is_nul(pptree))printf("tree cannot be null");
    if(index_b < 0 || index_e > (*pptree)->size)
    {
        printf("begin and end index must be in the fair range");
        return;
    }
    int index = index_b + (index_e-index_b+1)/2;
//    printf("index===%d\n", index);
    while(index_b<index_e)
    {
//        printf("---before---\n");
//        printf("index_b_value===%d,", *((*pptree)->data+index_b));
//        printf("index_e_value===%d\n", *((*pptree)->data+index_e));
        swap_1((*pptree)->data+index_b, (*pptree)->data+index_e);
//        printf("---after---\n");
//        printf("index_b_value===%d,", *((*pptree)->data+index_b));
//        printf("index_e_value===%d\n", *((*pptree)->data+index_e));
        index_b++;
        index_e--;
    }

}

bool is_nul(p_p_tree pptree)
{
    return !pptree||!(*pptree)||!(*pptree)->data||!(*pptree)->size;
}

float my_log(int a, int b)
{
    return log(b)/log(a);
}
