#ifndef define_struct
#define define_struct
#include <time.h>
typedef struct category
{
    int id;
    char *name;
} Category;
#define MAX 40
typedef struct goods
{
    int id;
    char *name;
    int categoryID;
    int price;
    int discount;
    int ownerID;
} Goods;
typedef struct purchaseHistory
{
    char listGoods[99][99];
    int sizeListGoods;
    char *name;
    char *address;
    char *phone;
    int64_t totalPrice;
    time_t time;
    char *purchaseType;
} PurchaseHistory;
typedef struct salesHistory
{
    char *name;
    int64_t goodsId;
    int64_t categoryID;
    int64_t price;
    time_t time;
} SalesHistory;
typedef struct user
{
    int id;
    char userName[MAX];
    char password[MAX];
    char name[MAX];
    char address[MAX];
    char phoneNum[MAX];
    int role;
    long balance;
} User;
typedef struct coupon
{
    int ownerID;
    int discount;
    char *couponName;
} Coupon;
typedef struct itemRandom
{
    int goodsID;
    int weight;
} ItemRandom;
typedef struct adItem
{
    int ownerID;
    int goodID;
    long budget;
    long money;
} AdsItem;

const char *PATH_ADS = "data//ads.txt";
const char *PATH_USER = "data//user.txt";
const char *PATH_CATEGORY = "data//category.json";
const char *PATH_GOODS = "data//goods.json";
const char *PATH_PURCHASE_HISTORY = "data//purchase_history//";
const char *PATH_SALES_HISTORY = "data//sales_history//";
const char *PATH_COUPON = "data//coupon.txt";
const int MAX_BUFFER = 1024 * 1024;
#endif
