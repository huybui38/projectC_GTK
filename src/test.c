#include <stdio.h>
// #include <json-c/json.h>
// #include "json.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to replace a string with another
// string
char *replaceWord(const char *s, const char *oldW,
                  const char *newW)
{
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
}

char *replaceMain(char *s, char *old, char *new)
{
    // char *token = strtok(old, "|");
    char result[999][999];
    // int i = 0;
    char *token = strtok(old, " ");
    // // loop through the string to extract all other tokens
    while (token != NULL)
    {
        printf(" %s\n", token); //printing each token
        token = strtok(NULL, " ");
    }
    return "sad";
    // return result[i];
}
int main(int argc, char **argv)
{
    // PurchaseHistory history;
    // history.name = "Hello world";
    // history.address = "Xuan Loc";
    // history.phone = "123123123";
    // history.purchaseType = "COD";
    // history.sizeListGoods = 2;
    // history.time = 123123123;
    // history.totalPrice = 999999;
    // strcpy(history.listGoods, "Quan the thao");
    // strcpy(history.listGoods + 1, "Ao the thao");
    char *name = "Xin chào 1 2";
    char *result = replaceMain(name, "1 2", "Ngoc");
    printf("%s", result);
    // printf("%s", replaceWord(name, "Huy", "Công"));
    // // printf("in");
    // addPurchaseHistory("123sad", history);
    // PurchaseHistory *listPurchaseHistory;
    // int length = 0;
    // listPurchaseHistory = getPurchaseHistory("test9", &length);
    // if (length > 0)
    // {
    //     for (size_t i = 0; i < length; i++)
    //     {
    //         for (size_t j = 0; j < (listPurchaseHistory + i)->sizeListGoods; j++)
    //         {
    //             printf("%s =>>> %s \n", ((listPurchaseHistory + i)->listGoods)[j], (listPurchaseHistory + i)->address);
    //         }
    //     }
    // }
    // else
    // {
    //     printf("\nNothing %d ", length);
    // }
}