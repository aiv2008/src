#include<stdio.h>
#include<stdlib.h>
#include"sim_hash.h"


void simHashPush(simHash** ppsimHash, char key, int value)
{
    if(!ppsimHash)
    {
        printf("hash pointer is null\n");
        return;
    }
    if(!*ppsimHash)
    {
        *ppsimHash = (simHash*)calloc(1, sizeof(simHash));
        (*ppsimHash)->size = 256;
        (*ppsimHash)->hash_array = (int*)calloc((*ppsimHash)->size, sizeof(int));
    }
    *((*ppsimHash)->hash_array + (int)key ) = value;
}

int simHashGet(simHash** ppsimHash, char key)
{
    if(simHashIsNullOrEmpty(ppsimHash)) return 0;
    return *((*ppsimHash)->hash_array + (int)key );
}

BOOL simHashIsNull(simHash** ppsimHash)
{
    return !ppsimHash || !*ppsimHash ;
}

BOOL simHashIsNullOrEmpty(simHash** ppsimHash)
{
    return !ppsimHash || !*ppsimHash || !(*ppsimHash)->size;
}
