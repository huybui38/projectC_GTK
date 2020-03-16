#include "define.h"

#ifndef json_h
#define json_h

#include <json-c/json.h>

const char *PATH_CATEGORY = "data//category.json";
const char *PATH_GOODS = "data//goods.json";

// #region addCategory
int addCategory(Category cate)
{
    FILE *fp;
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *id;
    struct json_object *name;
    struct json_object *data;
    struct json_object *objCate = json_object_new_object();
    size_t length;
    fp = fopen(PATH_CATEGORY, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, 1024, 1, fp);
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
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *id;
    struct json_object *name;
    struct json_object *data;
    struct json_object *objCate = json_object_new_object();
    Category *listCate;
    size_t length;
    fp = fopen(PATH_CATEGORY, "r");

    if (fp == NULL)
        return -1;

    fread(buffer, 1024, 1, fp);
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
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *id;
    struct json_object *name;
    struct json_object *data;
    struct json_object *objCate = json_object_new_object();
    Category *listCate;
    size_t length;
    fp = fopen(PATH_CATEGORY, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, 1024, 1, fp);
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
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();

    struct json_object *id;
    struct json_object *name;
    struct json_object *categoryID;
    struct json_object *price;
    struct json_object *discount;

    Goods *listGoods;
    size_t length;

    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, 1024, 1, fp);
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
        json_object_object_get_ex(objGoods, "discount", &discount);
        json_object_object_get_ex(objGoods, "id", &id);

        (listGoods + i)->id = json_object_get_int(id);
        (listGoods + i)->name = json_object_get_string(name);
        (listGoods + i)->categoryID = json_object_get_int(categoryID);
        (listGoods + i)->price = json_object_get_int(price);
        (listGoods + i)->discount = json_object_get_int(discount);
    }
    return listGoods;
}
// #endregion
// #region addGoods
int addGoods(Goods goods)
{
    FILE *fp;
    char buffer[1024];
    struct json_object *parsed_json;
    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();

    struct json_object *id;
    struct json_object *name;
    struct json_object *price;
    struct json_object *discount;
    struct json_object *categoryID;

    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, 1024, 1, fp);
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "data", &data);

    name = json_object_new_string(goods.name);
    id = json_object_new_int(goods.id);
    price = json_object_new_int(goods.price);
    categoryID = json_object_new_int(goods.categoryID);
    discount = json_object_new_int(goods.discount);

    json_object_object_add(objGoods, "id", id);
    json_object_object_add(objGoods, "name", name);
    json_object_object_add(objGoods, "price", price);
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
    char buffer[1024];
    struct json_object *parsed_json;

    struct json_object *id;
    struct json_object *name;
    struct json_object *categoryID;
    struct json_object *price;
    struct json_object *discount;

    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();
    Goods *listGoods;
    size_t length;
    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, 1024, 1, fp);
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
            json_object_object_get_ex(objGoods, "discount", &discount);
            (listGoods + j)->id = json_object_get_int(id);
            (listGoods + j)->name = json_object_get_string(name);
            (listGoods + j)->discount = json_object_get_int(discount);
            (listGoods + j)->price = json_object_get_int(price);
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
    char buffer[1024];
    struct json_object *parsed_json;

    struct json_object *id;
    struct json_object *name;
    struct json_object *categoryID;
    struct json_object *price;
    struct json_object *discount;

    struct json_object *data;
    struct json_object *objGoods = json_object_new_object();
    Goods *listGoods;
    size_t length;
    fp = fopen(PATH_GOODS, "r");
    if (fp == NULL)
        return -1;
    fread(buffer, 1024, 1, fp);
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
            json_object_object_get_ex(objGoods, "discount", &discount);
            (listGoods + i)->id = json_object_get_int(id);
            (listGoods + i)->name = json_object_get_string(name);
            (listGoods + i)->discount = json_object_get_int(discount);
            (listGoods + i)->price = json_object_get_int(price);
            (listGoods + i)->categoryID = json_object_get_int(categoryID);
        }
        else
        {
            (listGoods + i)->id = goods.id;
            (listGoods + i)->name = goods.name;
            (listGoods + i)->discount = goods.discount;
            (listGoods + i)->price = goods.price;
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

#endif
