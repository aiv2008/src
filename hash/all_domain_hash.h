#ifndef ALL_DOMAIN_HASH_H_INCLUDED
#define ALL_DOMAIN_HASH_H_INCLUDED

typedef struct
{
	int a;
	int b;
	int m;
	int p;
} adHashFunc;

typedef struct
{
	int key;
	int value;
	int size;
} adHash;

int adPush(adHashFunc** ppAdHashFunc, int key, int m);

void getMaxMin(int* nums, int numsSize, int* max, int* min);

#endif
