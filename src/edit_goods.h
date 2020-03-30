#ifndef EDIT_GOODS_H
#define EDIT_GOODS_H

#include "define.h"
#include "edit_user.h"
#include "json.h"

#define MAX_GOODS 130

int addGoodsToFile(char goodName[MAX_GOODS], int price, int cateID, int ownerID);
int editGoodsToFile(int goodsID, char goodName[MAX_GOODS], int price, int cateID);
int addCategoryToFile(char cateName[120]);
int changeDiscount(int goodsID, int discount);
int isValidGoodsName(char str[MAX_GOODS]);
int isExistedCateID(int cateID);
int isValidCateName(char *str);
int getGoodsSaleCount(int ownerID, int goodsID);
int isExistedGoodsID(int id, Goods *ptrGood, int *pos);
void sortNameAscending(Goods *ptrGoods, int length);
void sortPriceAscending(Goods *ptrGoods, int length);
void sortPriceDecending(Goods *ptrGoods, int length);
void swap(char *ch1, char *ch2);
void reverseStr(char *str);
void addChar(char *str, char ch, int pos);
void addStr(char *str, char *ch, int pos);
char *formatNumber(long money);
char intToChar(int num);
char *getNameCategory(int cateID);
Goods *getGoods(int cateID, int size, int page, int *canNext, int *lengthArr, int typeSort);
Goods *getGoodsByName(char *str, int cateID, int size, int page, int *canNext, int *foundLength, int typeSort);
Goods getGoodsByID(int goodsID);
Goods *getGoodsByOwnerID(int ownerID, int *length);

int isValidGoodsName(char str[MAX_GOODS])
{
  int check = 1;
  int length = strlen(str);

  if (length < 6 || length > 120)
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

int addGoodsToFile(char goodsName[MAX_GOODS], int price, int cateID, int ownerID)
{
  int check = 1;
  size_t length;
  Goods goods;
  Goods *ptrGoods;
  char *lowerGoodsName;

  // removeExtraSpaces(goodsName); //error
  // ptrGoods = (Goods *) calloc (100, sizeof(Goods));
  lowerGoodsName = filterVietnamese(goodsName);
  if (!isValidGoodsName(lowerGoodsName))
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
    // ptrGoods = (Goods *) calloc (20, sizeof(Goods));
    ptrGoods = getAllGoods(&length);
    if (length == 0)
    {
      goods.id = 1;
    }
    else
    {
      goods.id = ptrGoods[length - 1].id + 1;
    }
    goods.categoryID = cateID;
    goods.price = price;
    goods.discount = 0;
    goods.name = goodsName;
    goods.ownerID = ownerID;
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
  char *lowerGoodsName;

  ptrGoods = getAllGoods(&length);
  // removeExtraSpaces(goodsName);
  lowerGoodsName = filterVietnamese(goodsName);

  if (!isExistedGoodsID(goodsID, ptrGoods, &pos))
  {
    check = 2;
  }
  else if (!isValidGoodsName(lowerGoodsName))
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

void sortNameAscending(Goods *ptrGoods, int length)
{
  char *lowStr1, *lowStr2;
  char *tmpStr1, *tmpStr2;
  Goods tmpGoods;

  tmpStr1 = (char *)calloc(120, sizeof(char));
  tmpStr2 = (char *)calloc(120, sizeof(char));
  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      //comparing after converting string to lowercase brings more exactly result
      lowStr1 = filterVietnamese((ptrGoods + i)->name);
      strcpy(tmpStr1, lowStr1);
      lowStr2 = filterVietnamese((ptrGoods + k)->name);
      strcpy(tmpStr2, lowStr2);
      lowerString(tmpStr1);
      lowerString(tmpStr2);
      if (strcmp(tmpStr1, tmpStr2) > 0)
      {
        tmpGoods = *(ptrGoods + i);
        *(ptrGoods + i) = *(ptrGoods + k);
        *(ptrGoods + k) = tmpGoods;
      }
    }
  }
}

void sortPriceAscending(Goods *ptrGoods, int length)
{
  int lastPrice1, lastPrice2;
  Goods tmpGoods;

  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      lastPrice1 = (ptrGoods + i)->price - (int)(((float)(ptrGoods + i)->discount / 100.0) * (ptrGoods + i)->price);
      lastPrice2 = (ptrGoods + k)->price - (int)(((float)(ptrGoods + k)->discount / 100.0) * (ptrGoods + k)->price);
      if (lastPrice1 > lastPrice2)
      {
        tmpGoods = *(ptrGoods + i);
        *(ptrGoods + i) = *(ptrGoods + k);
        *(ptrGoods + k) = tmpGoods;
      }
    }
  }
}

void sortPriceDecending(Goods *ptrGoods, int length)
{
  int lastPrice1, lastPrice2;
  Goods tmpGoods;

  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      lastPrice1 = (ptrGoods + i)->price - (int)(((float)(ptrGoods + i)->discount / 100.0) * (ptrGoods + i)->price);
      lastPrice2 = (ptrGoods + k)->price - (int)(((float)(ptrGoods + k)->discount / 100.0) * (ptrGoods + k)->price);
      if (lastPrice1 < lastPrice2)
      {
        tmpGoods = *(ptrGoods + i);
        *(ptrGoods + i) = *(ptrGoods + k);
        *(ptrGoods + k) = tmpGoods;
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

  if (cateID == 0)
  {                        //cate = 0: show all Goods
    foundGoods = allGoods; //de xem co ok ko
    foundCount = length;
  }
  else
  {
    for (int i = 0; i < length; i++)
    {
      if (cateID == (allGoods + i)->categoryID)
      {
        // assignGoods(foundGoods, allGoods, foundCount, i);
        *(foundGoods + foundCount) = *(allGoods + i);
        foundCount++;
      }
    }
  }

  //sort the foundGoods
  switch (typeSort)
  {
  case 1:
    sortNameAscending(foundGoods, foundCount);
    break;
  case 2:
    sortPriceDecending(foundGoods, foundCount);
    break;
  case 3:
    sortPriceAscending(foundGoods, foundCount);
    break;
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
    startShow = 0;
    endShow = 0;
    showTotal = 0;
  }
  else
  {
    if (page == totalPage)
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
      // assignGoods(showGoods, foundGoods, count, i);
      *(showGoods + count) = *(foundGoods + i);
      count++;
    }
    showTotal = endShow - startShow + 1;
  }

  *lengthArr = showTotal;

  free(foundGoods);
  return showGoods;
}

Goods *getGoodsByName(char *findStr, int cateID, int size, int page, int *canNext, int *lengthArr, int typeSort)
{
  Goods *allGoods;
  Goods *showGoods;
  Goods *foundGoods;
  size_t allLength;
  char *tmpName, *tmpFind;
  char *t1, *t2;
  int showTotal, totalPage;
  int foundCount = 0;
  *canNext = 0;

  t1 = (char *)calloc(120, sizeof(char));
  t2 = (char *)calloc(120, sizeof(char));
  allGoods = getAllGoods(&allLength);
  foundGoods = (Goods *)calloc(allLength, sizeof(Goods));

  if (cateID == 0)
  {
    for (int i = 0; i < allLength; i++)
    {
      tmpName = filterVietnamese((allGoods + i)->name);
      strcpy(t1, tmpName); //vi van de trong filterVnmese nen cop ra nhu v
      lowerString(t1);
      tmpFind = filterVietnamese(findStr);
      strcpy(t2, tmpFind);
      lowerString(t2);
      if (strstr(t1, t2) != '\0')
      {
        // assignGoods(foundGoods, allGoods, foundCount, i);
        *(foundGoods + foundCount) = *(allGoods + i);
        foundCount++;
      }
    }
  }
  else
  {
    for (int i = 0; i < allLength; i++)
    {
      tmpName = filterVietnamese((allGoods + i)->name);
      strcpy(t1, tmpName); //vi van de trong filterVnmese nen cop ra nhu v
      lowerString(t1);
      tmpFind = filterVietnamese(findStr);
      strcpy(t2, tmpFind);
      lowerString(t2);
      if ((strstr(t1, t2) != '\0') && (cateID == (allGoods + i)->categoryID))
      {
        // assignGoods(foundGoods, allGoods, foundCount, i);
        *(foundGoods + foundCount) = *(allGoods + i);
        foundCount++;
      }
    }
  }

  //sort the foundGoods
  switch (typeSort)
  {
  case 1:
    sortNameAscending(foundGoods, foundCount);
    break;
  case 2:
    sortPriceDecending(foundGoods, foundCount);
    break;
  case 3:
    sortPriceAscending(foundGoods, foundCount);
    break;
  }

  //count total page found
  totalPage = foundCount / size;
  if (foundCount % size != 0)
  {
    totalPage++;
  }

  //assign values fo showgoods
  showGoods = (Goods *)calloc(foundCount, sizeof(Goods));
  int startShow, endShow;
  if ((page > totalPage) || foundCount == 0)
  {
    *canNext = 0;
    startShow = 0;
    endShow = 0;
    showTotal = 0;
  }
  else
  {
    if (page == totalPage)
    {
      endShow = foundCount - 1;
      startShow = (page - 1) * size;
      canNext = 0;
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
      // assignGoods(showGoods, foundGoods, count, i);
      *(showGoods + count) = *(foundGoods + i);
      count++;
    }
    showTotal = endShow - startShow + 1;
  }

  *lengthArr = showTotal;

  free(foundGoods);
  return showGoods;
}

char intToChar(int num)
{
  switch (num)
  {
  case 1:
    return '1';
  case 2:
    return '2';
  case 3:
    return '3';
  case 4:
    return '4';
  case 5:
    return '5';
  case 6:
    return '6';
  case 7:
    return '7';
  case 8:
    return '8';
  case 9:
    return '9';
  case 0:
    return '0';
  }
}

void swap(char *ch1, char *ch2)
{
  char tmp;
  tmp = *ch1;
  *ch1 = *ch2;
  *ch2 = tmp;
}

void reverseStr(char *str)
{
  int length = strlen(str);

  for (int i = 0; i < length / 2; i++)
    swap(&str[i], &str[length - i - 1]);
}

void addChar(char *str, char ch, int pos)
{
  for (int i = strlen(str); i > pos; i--)
    str[i] = str[i - 1];
  str[pos] = ch;
}

void addStr(char *str, char *ch, int pos)
{
  for (int i = strlen(str) + strlen(ch) - 1; i >= pos + strlen(ch); i--)
  {
    str[i] = str[i - 1];
  }
  int k = 0;
  for (int i = pos; i < strlen(ch) + pos; i++)
  {
    str[i] = ch[k];
    k++;
  }
}

char *formatNumber(long money)
{
  long tmp = money;
  char *str;
  int i = 0;

  str = (char *)calloc(20, sizeof(char));
  if (tmp == 0)
  {
    strcpy(str, "0 đ");
  }
  else
  {
    while (tmp != 0)
    {
      char tmpCh = intToChar(tmp % 10);
      str[i] = tmpCh;
      tmp /= 10;
      i++;
    }
    int length = strlen(str);
    int count = 1;
    if (length > 3)
    {
      for (int i = 0; i < length; i++)
      {
        if (count == 3 && i != (length - 1))
        {
          addChar(str, '.', i + 1);
          length++;
          count = -1;
        }
        count++;
      }
    }
    reverseStr(str);
    char *tmpp = " đ";
    addStr(str, tmpp, length);
  }
  return str;
}

int isValidCateName(char *str)
{
  int check = 1;
  int i = 0;
  int length = strlen(str);

  if (length < 2 || length > 100)
  {
    check = 0;
  }
  else
  {
    while (str[i] != '\0')
    {
      if (!isNum(str[i]) && !isChar(str[i]) && str[i] != ' ')
      {
        check = 0;
        break;
      }
      i++;
    }
  }
  return check;
}

int addCategoryToFile(char cateName[120])
{
  int check = 1;
  size_t length;
  char *filterCateName;
  Category *listCate;
  Category cate;

  // removeExtraSpaces(cateName);
  filterCateName = filterVietnamese(cateName);
  if (!isValidCateName(filterCateName))
  {
    check = 2;
  }
  else
  {
    listCate = getCategory(&length);
    if (length == 0)
    {
      cate.id = 1;
    }
    else
    {
      cate.id = listCate[length - 1].id + 1;
    }
    cate.name = cateName;
    addCategory(cate);
  }
  return check;
}

Goods *getGoodsByOwnerID(int ownerID, int *length)
{
  Goods *allGoods;
  Goods *foundGoods;
  size_t allLength;
  int foundCount = 0;
  allGoods = getAllGoods(&allLength);
  foundGoods = (Goods *)calloc(allLength, sizeof(Goods));

  for (int i = 0; i < allLength; i++)
  {
    if ((allGoods + i)->ownerID == ownerID)
    {
      *(foundGoods + foundCount) = *(allGoods + i);
      foundCount++;
    }
  }

  *length = foundCount;

  return foundGoods;
}

Goods getGoodsByID(int goodID)
{
  Goods *ptrGoods;
  size_t length;
  int i;

  ptrGoods = getAllGoods(&length);
  for (i = 0; i < length; i++)
  {
    if (goodID == (ptrGoods + i)->id)
    {
      return *(ptrGoods + i);
    }
  }
}

char *getNameCategory(int cateID)
{
  Category *ptrCate;
  size_t *length;
  char *result;
  result = (char *)calloc(120, sizeof(char));

  ptrCate = getCategory(&length);
  for (int i = 0; i < length; i++)
  {
    if (cateID == (ptrCate + i)->id)
    {
      strcpy(result, (ptrCate + i)->name);
      break;
    }
  }
  return result;
}

int getGoodsSaleCount(int ownerID, int goodsID)
{
  User *listUser;
  SalesHistory *listSale;
  size_t saleCount;
  char *username;
  int userCount = countLineInFile(PATH_USER);

  listUser = (User *)calloc(userCount, sizeof(User));
  getDataFromFile(listUser);
  username = (char *)calloc(20, sizeof(char));
  for (int i = 0; i < userCount; i++)
  {
    if (ownerID == (listUser + i)->id)
    {
      strcpy(username, (listUser + i)->userName);
      break;
    }
  }
  free(listUser);

  listSale = getSalesHistory(username, &saleCount);
  int count = 0;
  for (int i = 0; i < saleCount; i++)
  {
    if (goodsID == (listSale + i)->goodsId)
    {
      count++;
    }
  }
  free(listSale);
  return count;
}

#endif