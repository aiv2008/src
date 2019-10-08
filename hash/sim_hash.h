#ifndef SIM_HASH_H_INCLUDED
#define SIM_HASH_H_INCLUDED

#define BOOL char
#define TRUE 1
#define FALSE 0

typedef struct
{
    int* hash_array;
    int size;
} simHash, *p_simHash, **pp_simHash;

void push(pp_simHash ppsimHash, char key, int value);

int get(pp_simHash ppsimHash, char key);

int getSize(pp_simHash ppsimHash);

BOOL hashIsNull(pp_simHash ppsimHash);

BOOL hashIsNullOrEmpty(pp_simHash ppsimHash);

#endif // SIM_HASH_H_INCLUDED
