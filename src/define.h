#ifndef define_struct
#define define_struct
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
#endif
