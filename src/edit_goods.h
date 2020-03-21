#ifndef EDIT_GOODS_H
#define EDIT_GOODS_H

#include <string.h>
// #include <conio.h>
#include <stdio.h>
#include <stdint.h>
#include "define.h"
#include "edit_user.h"
#include "json.h"

#define MAX_GOODS 130
// #define PATH_GOOD "shopee\\data\\goods.json"
// #define PATH_CATEGORY "shopee\\data\\category.json"
// #define PATH_TEST "shopee\\data\\test.json"

int addGoodsToFile(char goodName[MAX_GOODS], int price, int cateID);
int editGoodsToFile(int goodsID, char goodName[MAX_GOODS], int price, int cateID);
int changeDiscount(int goodsID, int discount);
int isValidGoodsName(char str[MAX_GOODS]);
int isExistedCateID(int cateID);
int isValidDiscount(char str[20]);
int isExistedGoodsID(int id, Goods *ptrGood, int *pos);
void sortNameAscending(Goods *ptrGoods, int length);
void sortPriceAscending(Goods *ptrGoods, int length);
void sortPriceDecending(Goods *ptrGoods, int length);
void assignGoods(Goods *ptrG1, Goods *ptrG2, int pos1, int pos2);
Goods *getGoods(int cateID, int size, int page, int *canNext, int *lengthArr, int typeSort);

int isValidGoodsName(char str[MAX_GOODS])
{
  int check = 1;
  int length = strlen(str);

  if (length < 8 || length > 120)
  {
    check = 0;
  }
  else
  {
    for (int i = 0; i < length; i++)
    {
      if (!isNum(str[i]) && !isChar(str[i]) && str[i] != ' ' && str[i] != '.' && str[i] != ',' && str[i] != '-' && str[i] != '(' && str[i] != ')')
      {
        check = 0;
        break;
      }
    }
  }
  return check;
}

int isExistedCateID(int cateID)
{
  int check = 0;
  Category *ptrCate;
  size_t length;
  ptrCate = getCategory(&length);

  for (int i = 0; i < length; i++)
  {
    if ((ptrCate + i)->id == cateID)
    {
      check = 1;
      break;
    }
  }
  return check;
}

int isValidDiscount(char str[20])
{
  int check = 1;
  int i = 0;

  while (str[i] != '\0')
  {
    if (!isNum(str[i]))
    {
      check = 0;
      break;
    }
    i++;
  }
  if (check == 1)
  {
    int tmp = atoi(str);
    if (tmp < 0 || tmp > 100)
    {
      check = 0;
    }
  }
  return check;
}

int isExistedGoodsID(int id, Goods *ptrGoods, int *pos)
{
  int check = 0;
  int length;
  ptrGoods = getAllGoods(&length);

  for (int i = 0; i < length; i++)
  {
    if (id == (ptrGoods + i)->id)
    {
      check = 1;
      *pos = i;
      break;
    }
  }
  return check;
}

int addGoodsToFile(char goodsName[MAX_GOODS], int price, int cateID)
{
  int check = 1;
  size_t length;
  Goods goods;
  Goods *ptrGoods;

  if (!isValidGoodsName(goodsName))
  {
    check = 2;
  }
  else if (price < 0)
  {
    check = 3;
  }
  else if (!isExistedCateID(cateID))
  {
    check = 4;
  }
  if (check == 1)
  {
    ptrGoods = (Goods *)calloc(20, sizeof(Goods));
    ptrGoods = getAllGoods(&length);
    goods.categoryID = cateID;
    goods.price = price;
    goods.discount = 0;
    goods.id = ptrGoods[length - 1].id + 1;
    goods.name = goodsName;
    addGoods(goods);
  }
  free(ptrGoods);
  return check;
}

int editGoodsToFile(int goodsID, char goodsName[MAX_GOODS], int price, int cateID)
{
  int check = 1;
  int tmp, pos;
  size_t length;
  Goods goods;
  Goods *ptrGoods;

  ptrGoods = getAllGoods(&length);
  if (!isExistedGoodsID(goodsID, ptrGoods, &pos))
  {
    check = 2;
  }
  else if (!isValidGoodsName(goodsName))
  {
    check = 3;
  }
  else if (price < 0)
  {
    check = 4;
  }
  else if (!isExistedCateID(cateID))
  {
    check = 5;
  }

  if (check == 1)
  {
    (ptrGoods + pos)->id = goodsID;
    (ptrGoods + pos)->categoryID = cateID;
    (ptrGoods + pos)->discount = 0;
    (ptrGoods + pos)->price = price;
    (ptrGoods + pos)->name = goodsName;
    goods = *(ptrGoods + pos);
    editGoods(goods, &length);
  }
  return check;
}

int changeDiscount(int goodsID, int discount)
{
  int check = 1;
  int tmp, pos;
  size_t length;
  Goods goods;
  Goods *ptrGoods;

  ptrGoods = getAllGoods(&length);
  if (!isExistedGoodsID(goodsID, ptrGoods, &pos))
  {
    check = 2;
  }
  else if (discount < 0 || discount > 100)
  {
    check = 3;
  }

  if (check == 1)
  {
    (ptrGoods + pos)->discount = discount;
    goods = *(ptrGoods + pos);
    editGoods(goods, &length);
  }
  return check;
}

void assignGoods(Goods *ptrG1, Goods *ptrG2, int pos1, int pos2)
{
  (ptrG1 + pos1)->categoryID = (ptrG2 + pos2)->categoryID;
  (ptrG1 + pos1)->discount = (ptrG2 + pos2)->discount;
  (ptrG1 + pos1)->id = (ptrG2 + pos2)->id;
  (ptrG1 + pos1)->name = (ptrG2 + pos2)->name;
  (ptrG1 + pos1)->price = (ptrG2 + pos2)->price;
}

void sortNameAscending(Goods *ptrGoods, int length)
{
  char tmp[MAX_GOODS];
  char lowStr1[MAX_GOODS], lowStr2[MAX_GOODS];

  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      //comparing after converting string to lowercase brings more exactly result
      strcpy(lowStr1, (ptrGoods + i)->name);
      strcpy(lowStr2, (ptrGoods + k)->name);
      lowerString(lowStr1);
      lowerString(lowStr2);
      if (strcmp(lowStr1, lowStr2) > 0)
      {
        strcpy(tmp, (ptrGoods + i)->name);
        strcpy((ptrGoods + i)->name, (ptrGoods + k)->name);
        strcpy((ptrGoods + k)->name, tmp);
      }
    }
  }
}

void sortPriceAscending(Goods *ptrGoods, int length)
{
  int tmp;
  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      if ((ptrGoods + i)->price > (ptrGoods + k)->price)
      {
        tmp = (ptrGoods + i)->price;
        (ptrGoods + i)->price = (ptrGoods + k)->price;
        (ptrGoods + k)->price = tmp;
      }
    }
  }
}

void sortPriceDecending(Goods *ptrGoods, int length)
{
  int tmp;
  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      if ((ptrGoods + i)->price < (ptrGoods + k)->price)
      {
        tmp = (ptrGoods + i)->price;
        (ptrGoods + i)->price = (ptrGoods + k)->price;
        (ptrGoods + k)->price = tmp;
      }
    }
  }
}

Goods *getGoods(int cateID, int size, int page, int *canNext, int *lengthArr, int typeSort)
{
  Goods *foundGoods;
  Goods *showGoods;
  Goods *allGoods;
  size_t length;
  int showTotal;
  int totalPage;
  int foundCount = 0;
  *canNext = 0;

  allGoods = getAllGoods(&length);
  foundGoods = (Goods *)calloc(length, sizeof(Goods));
  //cap bo nho thi chuong trinh moi chay duoc, t chua hieu cho nay lam
  for (int i = 0; i < length; i++)
  {
    if (cateID == (allGoods + i)->categoryID)
    {
      assignGoods(foundGoods, allGoods, foundCount, i);
      foundCount++;
    }
  }

  //count total page found
  totalPage = (foundCount / size);
  if (foundCount % size != 0)
  {
    totalPage++;
  }

  //assign values for showGoods
  showGoods = (Goods *)calloc(foundCount, sizeof(Goods));
  int startShow, endShow;
  if (page > totalPage)
  {
    *canNext = 0;
  }
  else if (page == totalPage)
  { //means at the last page
    endShow = foundCount - 1;
    startShow = (page - 1) * size;
    *canNext = 0;
  }
  else
  {
    endShow = size * page - 1;
    startShow = endShow - size + 1;
    *canNext = 1;
  }
  int count = 0;
  for (int i = startShow; i <= endShow; i++)
  {
    assignGoods(showGoods, foundGoods, count, i);
    count++;
  }
  //sorting the result
  showTotal = endShow - startShow + 1;
  *lengthArr = showTotal;

  //sort the result
  switch (typeSort)
  {
  case 1:
    sortNameAscending(showGoods, showTotal);
    break;
  case 2:
    sortPriceDecending(showGoods, showTotal);
    break;
  case 3:
    sortPriceAscending(showGoods, showTotal);
    break;
  }
  free(foundGoods);
  return showGoods;
}

#endif
// tmpGoods.id = (allGoods + 0)->id;
// (foundGoods +2)->id = (allGoods + 2)->id;
// printf("value tmpgood is: %d\n", tmpGoods.id);
// printf("address tmpgood is: %d\n", &tmpGoods.id);
// // *(foundGoods[0]).id = tmpGoods.id;
// printf("value foundgood id: %d\n", (foundGoods + 2)->id);
// printf("address foundgood id: %d\n", &(foundGoods + 2)->id);
// printf("e\n");