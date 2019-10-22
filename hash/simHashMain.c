#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"sim_hash.h"

int main(void)
{
    srand(time(0));
    int size = 100;
    char a[size];

//    char a[] = {'a','b','c','c','a','d','f'};
//    int size = sizeof(a)/sizeof(a[0]);

    int max = 122;
    int min = 48;

    simHash** ppsimHash = (simHash**)calloc(1, sizeof(simHash*));
//    pp_simHash ppsimHash = '\0';

	int i;
    for(i=0;i<size;i++)
    {
        a[i] = (char)(rand()%(max - min) + min);
        printf("%c,", a[i]);
        simHashPush(ppsimHash, a[i], simHashGet(ppsimHash, a[i])+1);
    }
    printf("\n");
    for(i=0; !simHashIsNullOrEmpty(ppsimHash) && i<(*ppsimHash)->size;i++)
    {
        if(*((*ppsimHash)->hash_array+i))
            printf("%c=%d,",(char)i , *((*ppsimHash)->hash_array+i));
    }
    printf("\n");
}
