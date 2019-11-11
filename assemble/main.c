#include<stdio.h>
#include<stdlib.h>
#include"assemble.h"

int main(void)
{

	int a[] = {5,34,6,3,2};
	int n = sizeof(a)/sizeof(a[0]);
	assemble(a, n);

	return 0;
}
