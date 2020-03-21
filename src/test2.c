#include <stdio.h>
#include <stdint.h>
#include "json.h"
int main()
{
    //printf("Hello World %d", isValidID("123123"));
    int length = 0;
    Goods *list;
    list = getAllGoods(&length);
    printf("%d", length);
    // for (size_t i = 0; i < length; i++)
    // {
    //     printf("%d \n", list[i].id);
    // }

    return 0;
}
