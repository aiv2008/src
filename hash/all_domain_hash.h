#ifndef ALL_DOMAIN_HASH_H_INCLUDED
#define ALL_DOMAIN_HASH_H_INCLUDED

<<<<<<< HEAD
void allDomainHash(int key, int n, int** ppA, int** ppB, int** ppPrime);
=======
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
>>>>>>> c41eff4eadc04a2c65be13926a9025a73be780b7

#endif
