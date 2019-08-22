#include<stdio.h>
#include<stdlib.h>
#include"common.h"

void swap_1(int* x, int* y)
{
    *x = *x^*y;
	*y = *x^*y;//(*x^*y)^*y=*x(ԭֵ)
	*x = *x^*y;//(*x^*y)^((*x^*y)^*y)=*y��ԭֵ��
}

void swap_2(int* x, int* y)
{
    *x = *x + *y;//�˴��п���Խ��
	*y = *x - *y;
	*x = *x - *y;
}

size_t plus_bit(size_t num1, size_t num2)
{

	int nOne = 0;
	int nTwo =0;
	do
    {
        nOne = num1^num2;
        nTwo = (num1&num2)<<1;
        num1 = nOne;
        num2 = nTwo;
	}while(nTwo != 0);
    return num1;
}

size_t minus_bit(size_t num1, size_t num2)
{
    return plus_bit(num1, plus_bit(~num2,1));
}


