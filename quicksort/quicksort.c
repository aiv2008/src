#include <stdio.h>
#include "../common/list_i.h"

size_t partition_ex(plist_i p, size_t start, size_t end)
{
    if( p->size == 0 )printf("list cannot be null");
    int* header = p->header;
    int* p_i = header;
    int* p_j = header;
    int* p_r = header+end - 1;


}
