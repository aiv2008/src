#include<stdio.h>
#include"sim_hash.h"


void push(pp_simHash ppsimHash, char key, int value)
{
    if(!ppsimHash)
    {
        printf("hash pointer is null\n");
        return;
    }
    if(!*ppsimHash)
    {
        *ppsimHash = (p_simHash)calloc(1, sizeof(int)+sizeof(int*));
        (*ppsimHash)->size = 256;
        (*ppsimHash)->hash_array = (int*)calloc((*ppsimHash)->size, sizeof(int));
    }
    *((*ppsimHash)->hash_array + (int)key ) = value;
}

int get(pp_simHash ppsimHash, char key)
{
    if(hashIsNullOrEmpty(ppsimHash)) return 0;
    return *((*ppsimHash)->hash_array + (int)key );
}

BOOL hashIsNull(pp_simHash ppsimHash)
{
    return !ppsimHash || !*ppsimHash ;
}

BOOL hashIsNullOrEmpty(pp_simHash ppsimHash)
{
    return !ppsimHash || !*ppsimHash || !(*ppsimHash)->size;
}
