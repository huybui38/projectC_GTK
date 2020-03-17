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
#endif
