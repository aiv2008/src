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

int adHash(adHashFunc** ppAdHashFunc, int key, int m);

#endif
