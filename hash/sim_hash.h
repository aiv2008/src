#ifndef SIM_HASH_H_INCLUDED
#define SIM_HASH_H_INCLUDED

#define BOOL char
#define TRUE 1
#define FALSE 0

typedef struct
{
    int* hash_array;
    int size;
} simHash;

void simHashPush(simHash** ppsimHash, char key, int value);

int simHashGet(simHash** ppsimHash, char key);

int simHashGetSize(simHash** ppsimHash);

BOOL simHashIsNull(simHash** ppsimHash);

BOOL simHashIsNullOrEmpty(simHash** ppsimHash);

#endif // SIM_HASH_H_INCLUDED
