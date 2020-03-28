#include <stdio.h>
#include <stdint.h>
// #include "authenticator.h"
// #include "edit_user.h"
#include "edit_goods.h"
#include "json.h"
#include "shopping_cart.h"
#include <stddef.h>
#include <time.h>
#include <stdio.h>

int main()
{
    // FILE *fp;
    // char path_history[100];
    // strcpy(path_history, PATH_SALES_HISTORY);
    // strcat(path_history, "huybui382");
    // strcat(path_history, ".json");
    // fp = fopen(path_history, "w+");
    // fprintf(fp, "%s", "{\"data\": []}");
    // fclose(fp);
    // Goods goods = {650815873, "quan 2019", 2000, 3, 1, 0};
    // addSalesHistory(goods, "asdasd");
    // SalesHistory *list;
    // int size = 0;
    // list = getSalesHistory("huybui382", &size);
    // printf("%d", size);
    deleteCoupon("XINCHAO", 8);
    // struct tm startTimeStruct;
    // time_t startTimestamp;
    // if (strptime("2000-12-2 1:30:30", "%Y-%m-%e %H:%M:%S", &startTimeStruct) != NULL)
    // {
    //     startTimestamp = mktime(&startTimeStruct);
    // }
    // printf("time2: %ld", startTimestamp);
    return 0;
}