#include <stdio.h>
#include <stdint.h>
// #include "authenticator.h"
// #include "edit_user.h"
#include "edit_goods.h"
#include "json.h"
int main()
{
    Goods goods = {650815873, "quan 2019", 2000, 3, 1, 0};
    addSalesHistory(goods, "huybui38");
    SalesHistory *list;
    int size = 0;
    list = getSalesHistory("huybui38", &size);
    printf("%d", size);

    return 0;
}