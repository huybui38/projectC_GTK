#ifndef json_h
#define json_h

#include <json-c/json.h>

const char *PATH_CATEGORY = "data//category.json";
typedef struct category
{
    int id;
    char *name;
} Category;
typedef struct goods
{
    int id;
    char *name;
    int categoryID;
    int price;
    int discount;
} Goods;

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
    fp = fopen(PATH_CATEGORY, "w+");
    if (fp == NULL)
        return -1;
    fread(buffer, 1024, 1, fp);
    fprintf(fp, "%s", "{\"data\": []}");
    fclose(fp);
    parsed_json = json_tokener_parse(buffer);
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

#endif
