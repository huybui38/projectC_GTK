#include <stdio.h>
#include <stdint.h>
// #include "authenticator.h"
// #include "edit_user.h"
#include "edit_goods.h"
#include "json.h"
// #include "shopping_cart.h"
#include <stddef.h>
#include <time.h>
#include <stdio.h>
int randomNumber(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}
int getRandom(ItemRandom *data, int length)
{
    int total = 0;
    int distribution[length];
    for (int i = 0; i < length; i++)
    {
        total += data[i].weight;
        distribution[i] = total;
    }
    for (int i = 0; i < length; i++)
    {
        printf("goodsID:%d\n", data[i].goodsID);
    }
    int rand = randomNumber(0, total - 1);
    for (int i = 0; i < length; i++)
    {
        if (rand < distribution[i])
        {
            return i;
            break;
        }
    }
    return -1;
}
void randomAds(int count, ItemRandom *arrRandom, int lengthArr, int result[])
{
    for (int i = 0; i < count; i++)
    {
        if (!lengthArr)
            break;
        result[i] = getRandom(arrRandom, lengthArr);
    }
}
int main()
{
    srand((int)time(0));
    ItemRandom list[3];
    list[0].goodsID = 1;
    list[1].goodsID = 2;
    list[2].goodsID = 3;
    list[1].weight = 60;
    list[0].weight = 30;
    list[2].weight = 20;
    int lengthList = 3;
    int count = 100;
    int result[count];
    randomAds(count, list, lengthList, result);
    int frequency[lengthList];
    for (int i = 0; i < lengthList; i++)
    {
        frequency[i] = 0;
    }

    for (int i = 0; i < count; i++)
    {
        frequency[result[i]] += 1;
    }
    for (int i = 0; i < lengthList; i++)
    {
        printf("So lan xuat hien cua goodsID %d la: %d\n", list[i].goodsID, frequency[i]);
    }
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
    // deleteCoupon("XINCHAO", 8);
    // struct tm startTimeStruct;
    // time_t startTimestamp;
    // if (strptime("2000-12-2 1:30:30", "%Y-%m-%e %H:%M:%S", &startTimeStruct) != NULL)
    // {
    //     startTimestamp = mktime(&startTimeStruct);
    // }
    // printf("time2: %ld", startTimestamp);
    return 0;
}