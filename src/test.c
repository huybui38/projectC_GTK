#include <stdio.h>
#include <json-c/json.h>
#include "json.h"

int main(int argc, char **argv)
{
    Goods goods;
    goods.id = 2;
    goods.name = "Áo Thun";
    goods.categoryID = 2;
    goods.discount = 10;
    goods.price = 900000;

    Goods *listGoods;
    size_t length = 0;
    listGoods = getAllGoods(&length);
    for (size_t i = 0; i < length; i++)
    {
        printf("%d =>>> %s \n", (listGoods + i)->id, (listGoods + i)->name);
    }
    editGoods(goods, &length);
    // deleteCategory("hello Worlds", &length);
    printf("Hello =>> %d\n", length);
}