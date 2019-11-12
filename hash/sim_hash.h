#ifndef SIM_HASH_H_INCLUDED
#define SIM_HASH_H_INCLUDED

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct
{
    int* hash_array;
    int size;
} simHash;

void simHashPush(simHash** ppsimHash, int key, int value);

int simHashGet(simHash** ppsimHash, int key);

int simHashGetSize(simHash** ppsimHash);

BOOL simHashIsNull(simHash** ppsimHash);

BOOL simHashIsNullOrEmpty(simHash** ppsimHash);

#endif // SIM_HASH_H_INCLUDED
