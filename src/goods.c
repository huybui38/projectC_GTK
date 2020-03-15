#include <stdio.h>
#include <json-c/json.h>
#include "json.h"

int main(int argc, char **argv)
{
    Category cate;
    cate.name = "hello Worlds";
    cate.id = 3;
    // addCategory(cate);
    Category *listCate;
    size_t length = 0;
    listCate = getCategory(&length);
    for (size_t i = 0; i < length; i++)
    {
        printf("%d =>>> %s \n", (listCate + i)->id, (listCate + i)->name);
    }
    printf("\n");
    listCate = deleteCategory("Quan Ao2", &length);
    for (size_t i = 0; i < length; i++)
    {
        printf("%d =>>> %s \n", (listCate + i)->id, (listCate + i)->name);
    }
}