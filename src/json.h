#include "define.h"

#ifndef json_h
#define json_h
#include <time.h>
#include <json-c/json.h>

// #region addCategory
int addCategory(Category cate)
{
    FILE *fp;
    char buffer[MAX_BUFFER];
    struct json_object *parsed_json;
    struct json_object *id;
    struct json_object *name;
    struct json_object *data;
    struct json_object *objCate = json_object_new_object();
    size_t length;
    fp = fopen(PATH_CATEGORY, "r");
    if (fp == NULL)
        return;
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    name = json_object_new_string(cate.name);
    id = json_object_new_int(cate.id);

    json_object_object_add(objCate, "id", id);
    json_object_object_add(objCate, "name", name);

    json_object_array_add(data, objCate);
    json_object_to_file(PATH_CATEGORY, parsed_json);
    return 1;
}
// #endregion
// #region getCategory
Category *getCategory(size_t *sizeCate)
{

    FILE *fp;
    char buffer[MAX_BUFFER];

    struct json_object *parsed_json;
    struct json_object *id;
    struct json_object *name;
    struct json_object *data;
    struct json_object *objCate = json_object_new_object();
    Category *listCate;
    size_t length;
    fp = fopen(PATH_CATEGORY, "r");

    if (fp == NULL)
        return;

    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    listCate = (Category *)calloc(length, sizeof(Category));
    *sizeCate = length;
    for (size_t i = 0; i < length; i++)
    {
        objCate = json_object_array_get_idx(data, i);
        json_object_object_get_ex(objCate, "name", &name);
        json_object_object_get_ex(objCate, "id", &id);
        (listCate + i)->id = json_object_get_int(id);
        (listCate + i)->name = json_object_get_string(name);
        // printf("%d = >> %s", (listCate + i)->id, (listCate + i)->name);
    }
    return listCate;
}
// #endregion
// #region deleteCategory
Category *deleteCategory(char *nameCate, size_t *sizeArray)
{
    FILE *fp;
    char buffer[MAX_BUFFER];
    struct json_object *parsed_json;
    struct json_object *id;
    struct json_object *name;
    struct json_object *data;
    struct json_object *objCate = json_object_new_object();
    Category *listCate;
    size_t length;
    fp = fopen(PATH_CATEGORY, "r");
    if (fp == NULL)
        return;
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);
    //reset category file
    fp = fopen(PATH_CATEGORY, "w+");
    fprintf(fp, "%s", "{\"data\": []}");
    fclose(fp);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    listCate = (Category *)calloc(length, sizeof(Category));
    size_t i = 0, j = 0;
    while (i < length)
    {
        objCate = json_object_array_get_idx(data, i);
        json_object_object_get_ex(objCate, "name", &name);
        json_object_object_get_ex(objCate, "id", &id);
        size_t flag = strcmp(json_object_get_string(name), nameCate);
        if (flag != 0)
        {
            (listCate + j)->id = json_object_get_int(id);
            (listCate + j)->name = json_object_get_string(name);
            //low performance
            addCategory(*(listCate + j));
            j++;
        }
        i++;
    }
    *sizeArray = j;
    return listCate;
}
// #endregion

// #region getAllGoods
Goods *getAllGoods(size_t *sizeGoods)
{

    FILE *fp;
    char buffer[MAX_BUFFER];

    struct json_object *parsed_json;
    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();

    struct json_object *id;
    struct json_object *name;
    struct json_object *ownerID;
    struct json_object *categoryID;
    struct json_object *price;
    struct json_object *discount;

    Goods *listGoods;
    size_t length;
    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    listGoods = (Goods *)calloc(length, sizeof(Goods));
    *sizeGoods = length;
    for (size_t i = 0; i < length; i++)
    {
        objGoods = json_object_array_get_idx(data, i);
        json_object_object_get_ex(objGoods, "name", &name);
        json_object_object_get_ex(objGoods, "categoryID", &categoryID);
        json_object_object_get_ex(objGoods, "price", &price);
        json_object_object_get_ex(objGoods, "ownerID", &ownerID);
        json_object_object_get_ex(objGoods, "discount", &discount);
        json_object_object_get_ex(objGoods, "id", &id);

        (listGoods + i)->id = json_object_get_int(id);
        (listGoods + i)->name = json_object_get_string(name);
        (listGoods + i)->categoryID = json_object_get_int(categoryID);
        (listGoods + i)->price = json_object_get_int(price);
        (listGoods + i)->ownerID = json_object_get_int(ownerID);
        (listGoods + i)->discount = json_object_get_int(discount);
    }
    return listGoods;
}
// #endregion
// #region addGoods
int addGoods(Goods goods)
{
    FILE *fp;
    char buffer[MAX_BUFFER];
    struct json_object *parsed_json;
    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();

    struct json_object *id;
    struct json_object *name;
    struct json_object *price;
    struct json_object *ownerID;
    struct json_object *discount;
    struct json_object *categoryID;

    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);

    name = json_object_new_string(goods.name);
    id = json_object_new_int(goods.id);
    price = json_object_new_int(goods.price);
    ownerID = json_object_new_int(goods.ownerID);
    categoryID = json_object_new_int(goods.categoryID);
    discount = json_object_new_int(goods.discount);

    json_object_object_add(objGoods, "id", id);
    json_object_object_add(objGoods, "name", name);
    json_object_object_add(objGoods, "price", price);
    json_object_object_add(objGoods, "ownerID", ownerID);
    json_object_object_add(objGoods, "categoryID", categoryID);
    json_object_object_add(objGoods, "discount", discount);

    json_object_array_add(data, objGoods);
    json_object_to_file(PATH_GOODS, parsed_json);
    return 1;
}
// #endregion
// #region deleteGoods
Goods *deleteGoods(int goodsID, size_t *sizeArray)
{
    FILE *fp;
    char buffer[MAX_BUFFER];
    struct json_object *parsed_json;

    struct json_object *id;
    struct json_object *name;
    struct json_object *categoryID;
    struct json_object *price;
    struct json_object *ownerID;
    struct json_object *discount;

    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();
    Goods *listGoods;
    size_t length;
    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return;
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);
    //reset file
    fp = fopen(PATH_GOODS, "w+");
    fprintf(fp, "%s", "{\"data\": []}");
    fclose(fp);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    listGoods = (Goods *)calloc(length, sizeof(Goods));
    size_t i = 0, j = 0;
    while (i < length)
    {
        objGoods = json_object_array_get_idx(data, i);
        json_object_object_get_ex(objGoods, "id", &id);
        if (json_object_get_int(id) != goodsID)
        {

            json_object_object_get_ex(objGoods, "name", &name);
            json_object_object_get_ex(objGoods, "categoryID", &categoryID);
            json_object_object_get_ex(objGoods, "price", &price);
            json_object_object_get_ex(objGoods, "ownerID", &ownerID);
            json_object_object_get_ex(objGoods, "discount", &discount);
            (listGoods + j)->id = json_object_get_int(id);
            (listGoods + j)->name = json_object_get_string(name);
            (listGoods + j)->discount = json_object_get_int(discount);
            (listGoods + j)->price = json_object_get_int(price);
            (listGoods + j)->ownerID = json_object_get_int(ownerID);
            (listGoods + j)->categoryID = json_object_get_int(categoryID);
            //low performance
            addGoods(*(listGoods + j));
            j++;
        }
        i++;
    }
    *sizeArray = j;
    return listGoods;
}
// #endregion
// #region editGoods
Goods *editGoods(Goods goods, size_t *sizeArray)
{
    FILE *fp;
    char buffer[MAX_BUFFER];
    struct json_object *parsed_json;

    struct json_object *id;
    struct json_object *name;
    struct json_object *categoryID;
    struct json_object *price;
    struct json_object *ownerID;
    struct json_object *discount;

    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();
    Goods *listGoods;
    size_t length;
    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "data", &data);
    //reset file
    fp = fopen(PATH_GOODS, "w");
    fprintf(fp, "%s", "{\"data\": []}");
    fclose(fp);

    length = json_object_array_length(data);
    listGoods = (Goods *)calloc(length, sizeof(Goods));
    size_t i = 0;
    while (i < length)
    {
        objGoods = json_object_array_get_idx(data, i);
        json_object_object_get_ex(objGoods, "id", &id);
        if (json_object_get_int(id) != goods.id)
        {
            json_object_object_get_ex(objGoods, "name", &name);
            json_object_object_get_ex(objGoods, "categoryID", &categoryID);
            json_object_object_get_ex(objGoods, "price", &price);
            json_object_object_get_ex(objGoods, "ownerID", &ownerID);
            json_object_object_get_ex(objGoods, "discount", &discount);
            (listGoods + i)->id = json_object_get_int(id);
            (listGoods + i)->name = json_object_get_string(name);
            (listGoods + i)->discount = json_object_get_int(discount);
            (listGoods + i)->price = json_object_get_int(price);
            (listGoods + i)->ownerID = json_object_get_int(ownerID);
            (listGoods + i)->categoryID = json_object_get_int(categoryID);
        }
        else
        {
            (listGoods + i)->id = goods.id;
            (listGoods + i)->name = goods.name;
            (listGoods + i)->discount = goods.discount;
            (listGoods + i)->price = goods.price;
            (listGoods + i)->ownerID = goods.ownerID;
            (listGoods + i)->categoryID = goods.categoryID;
        }
        //low performance
        addGoods(*(listGoods + i));
        i++;
    }
    *sizeArray = i;
    return listGoods;
}
// #endregion

// #region getPurchaseHistory
PurchaseHistory *getPurchaseHistory(char userName[100], size_t *sizeArr)
{
    FILE *fp;
    char buffer[MAX_BUFFER];

    struct json_object *parsed_json;
    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();

    struct json_object *listGoods;
    struct json_object *ObjListGoods;
    struct json_object *name;
    struct json_object *phone;
    struct json_object *address;
    struct json_object *purchaseType;
    struct json_object *totalPrice;
    struct json_object *time;

    char path_history[100];
    strcpy(path_history, PATH_PURCHASE_HISTORY);
    strcat(path_history, userName);
    strcat(path_history, ".json");
    PurchaseHistory *listPurchaseHistory;
    size_t length;

    fp = fopen(path_history, "r");
    if (fp == NULL)
    {
        *sizeArr = -1;
        return listPurchaseHistory;
    }
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    *sizeArr = length;
    listPurchaseHistory = (PurchaseHistory *)calloc(length, sizeof(PurchaseHistory));
    for (size_t i = 0; i < length; i++)
    {
        objGoods = json_object_array_get_idx(data, i);
        json_object_object_get_ex(objGoods, "name", &name);
        json_object_object_get_ex(objGoods, "listGoods", &listGoods);
        json_object_object_get_ex(objGoods, "phone", &phone);
        json_object_object_get_ex(objGoods, "address", &address);
        json_object_object_get_ex(objGoods, "purchaseType", &purchaseType);
        json_object_object_get_ex(objGoods, "totalPrice", &totalPrice);
        json_object_object_get_ex(objGoods, "time", &time);

        int lengthListGoods = json_object_array_length(listGoods);
        for (size_t j = 0; j < lengthListGoods; j++)
        {
            ObjListGoods = json_object_array_get_idx(listGoods, j);
            // printf("%s\n", json_object_get_string(ObjListGoods));

            strcpy(((listPurchaseHistory + i)->listGoods) + j, json_object_get_string(ObjListGoods));
            // scanf(, json_object_get_string(ObjListGoods));
            //= ;
        }

        (listPurchaseHistory + i)->name = json_object_get_string(name);
        (listPurchaseHistory + i)->sizeListGoods = lengthListGoods;

        (listPurchaseHistory + i)->phone = json_object_get_string(phone);
        (listPurchaseHistory + i)->address = json_object_get_string(address);
        (listPurchaseHistory + i)->purchaseType = json_object_get_string(purchaseType);
        (listPurchaseHistory + i)->totalPrice = json_object_get_int64(totalPrice);
        (listPurchaseHistory + i)->time = json_object_get_int64(time);
    }
    return listPurchaseHistory;
}
// #endregion
// #region addPurchaseHistory
int addPurchaseHistory(char *userName, PurchaseHistory history)
{

    FILE *fp;
    char buffer[MAX_BUFFER];
    struct json_object *parsed_json;

    struct json_object *name;
    struct json_object *phone;
    struct json_object *address;
    struct json_object *purchaseType;
    struct json_object *totalPrice;
    struct json_object *time;
    struct json_object *listGoods = json_object_new_array();

    struct json_object *objGoods;
    struct json_object *data;
    struct json_object *objPurchaseHistory = json_object_new_object();
    size_t length;

    char path_history[100];
    strcpy(path_history, PATH_PURCHASE_HISTORY);
    strcat(path_history, userName);
    strcat(path_history, ".json");
    fp = fopen(path_history, "r");
    if (fp == NULL)
    {
        // todo create file
        fp = fopen(path_history, "w+");
        fprintf(fp, "%s", "{\"data\": []}");
        fclose(fp);
    }
    fp = fopen(path_history, "r");
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);

    name = json_object_new_string(history.name);
    phone = json_object_new_string(history.phone);
    address = json_object_new_string(history.address);
    purchaseType = json_object_new_string(history.purchaseType);
    totalPrice = json_object_new_int64(history.totalPrice);
    time = json_object_new_int64(history.time);
    for (size_t i = 0; i < history.sizeListGoods; i++)
    {
        objGoods = json_object_new_string(history.listGoods[i]);
        json_object_array_add(listGoods, objGoods);
    }
    json_object_object_add(objPurchaseHistory, "name", name);
    json_object_object_add(objPurchaseHistory, "phone", phone);
    json_object_object_add(objPurchaseHistory, "address", address);
    json_object_object_add(objPurchaseHistory, "purchaseType", purchaseType);
    json_object_object_add(objPurchaseHistory, "totalPrice", totalPrice);
    json_object_object_add(objPurchaseHistory, "time", time);
    json_object_object_add(objPurchaseHistory, "listGoods", listGoods);

    json_object_array_add(data, objPurchaseHistory);

    json_object_to_file(path_history, parsed_json);
    return 1;
}
// #endregion

// #region addSalesHistory
int addSalesHistory(Goods goods, char *userName)
{

    FILE *fp;
    char buffer[MAX_BUFFER];
    time_t now;
    time(&now);
    struct json_object *parsed_json;

    struct json_object *goodsId;
    struct json_object *name;
    struct json_object *categoryID;
    struct json_object *time;
    struct json_object *price;

    struct json_object *data;
    struct json_object *objSales = json_object_new_object();
    size_t length;
    char path_history[100];
    strcpy(path_history, PATH_SALES_HISTORY);
    strcat(path_history, userName);
    strcat(path_history, ".json");
    fp = fopen(path_history, "r");
    if (fp == NULL)
    {
        // todo create file
        fp = fopen(path_history, "w+");
        fprintf(fp, "%s", "{\"data\": []}");
        fclose(fp);
    }
    fp = fopen(path_history, "r");
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);
    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    name = json_object_new_string(goods.name);
    goodsId = json_object_new_int(goods.id);
    categoryID = json_object_new_int(goods.categoryID);
    price = json_object_new_int64(goods.price * (100 - goods.discount) / 100);
    time = json_object_new_int64(now);

    json_object_object_add(objSales, "name", name);
    json_object_object_add(objSales, "goodsId", goodsId);
    json_object_object_add(objSales, "categoryID", categoryID);
    json_object_object_add(objSales, "price", price);
    json_object_object_add(objSales, "time", time);

    json_object_array_add(data, objSales);
    json_object_to_file(path_history, parsed_json);
    return 1;
}
// #endregion
// #region getSalesHistory
SalesHistory *getSalesHistory(char userName[100], size_t *sizeArr)
{
    FILE *fp;
    char buffer[MAX_BUFFER];

    struct json_object *parsed_json;
    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();

    struct json_object *goodsId;
    struct json_object *name;
    struct json_object *categoryID;
    struct json_object *time;
    struct json_object *price;

    char path_history[100];
    strcpy(path_history, PATH_SALES_HISTORY);
    strcat(path_history, userName);
    strcat(path_history, ".json");
    SalesHistory *listSalesHistory;
    size_t length;

    fp = fopen(path_history, "r");

    if (fp == NULL)
    {
        *sizeArr = -1;
        return listSalesHistory;
    }
    fread(buffer, MAX_BUFFER, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);
    length = json_object_array_length(data);
    *sizeArr = length;
    listSalesHistory = (SalesHistory *)calloc(length, sizeof(SalesHistory));
    for (size_t i = 0; i < length; i++)
    {
        objGoods = json_object_array_get_idx(data, i);
        json_object_object_get_ex(objGoods, "goodsId", &goodsId);
        json_object_object_get_ex(objGoods, "name", &name);
        json_object_object_get_ex(objGoods, "categoryID", &categoryID);
        json_object_object_get_ex(objGoods, "time", &time);
        json_object_object_get_ex(objGoods, "price", &price);

        (listSalesHistory + i)->name = json_object_get_string(name);
        (listSalesHistory + i)->categoryID = json_object_get_int(categoryID);
        (listSalesHistory + i)->goodsId = json_object_get_int64(goodsId);
        (listSalesHistory + i)->time = json_object_get_int64(time);
        (listSalesHistory + i)->price = json_object_get_int64(price);
    }
    return listSalesHistory;
}
// #endregion
#endif
