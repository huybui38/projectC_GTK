#ifndef define_struct
#define define_struct
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
} Goods;
typedef struct purchaseHistory
{
    char listGoods[99][99];
    int sizeListGoods;
    char *name;
    char *address;
    char *phone;
    int64_t totalPrice;
    int64_t time;
    char *purchaseType;
} PurchaseHistory;
typedef struct user
{
    int id;
    char userName[MAX];
    char password[MAX];
    char name[MAX];
    char address[MAX];
    char phoneNum[MAX];
    int role;
    unsigned long balance;
} User;
const char *PATH_USER = "data//user.txt";
const char *PATH_CATEGORY = "data//category.json";
const char *PATH_GOODS = "data//goods.json";
const char *PATH_PURCHASE_HISTORY = "data//purchase_history//";
const int MAX_BUFFER = 1024 * 1024;
#endif
