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

    pp_simHash ppsimHash = (pp_simHash)calloc(1, sizeof(p_simHash));
//    pp_simHash ppsimHash = '\0';

    for(int i=0;i<size;i++)
    {
        a[i] = (char)(rand()%(max - min) + min);
        printf("%c,", a[i]);
        push(ppsimHash, a[i], get(ppsimHash, a[i])+1);
    }
    printf("\n");
    for(int i=0; !hashIsNullOrEmpty(ppsimHash) && i<(*ppsimHash)->size;i++)
    {
        if(*((*ppsimHash)->hash_array+i))
            printf("%c=%d,",(char)i , *((*ppsimHash)->hash_array+i));
    }
    printf("\n");
}
