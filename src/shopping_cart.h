#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "edit_goods.h"

Coupon getCoupon(int ownerID);
SalesHistory *getSalesHistoryByTime(char *userName, int *sizeArr, time_t start, time_t end);
int isValidCoupon(char *str);
int isAvailableCoupon(char *couName, int ownerID, int *discount);
int processCart(char *cusName, char *address, char *phoneNum, int method, Goods *purchaseGoods, int cartLength, int userID, char *coupon);
void removeElementCart(Goods *listGoods, int *length, int goodsID);
void getCouponFromFile(Coupon *ptrCoupon);
void writeCouponToFile(Coupon *ptrCoupon, int length);
void addCoupon(int ownerID, int discount, char *couponName);
void deleteCoupon(char *couName, int ownerID);
void sortCouponDescending(Coupon *listCoupon, int length);

void removeElementCart(Goods *listGoods, int *length, int goodsID)
{
  for (int i = 0; i < *length; i++)
  {
    if (goodsID == (listGoods + i)->id)
    {
      *length -= 1;
      for (int k = i; k < *length; k++)
      {
        *(listGoods + k) = *(listGoods + k + 1);
      }
      break;
    }
  }
}

void getCouponFromFile(Coupon *ptrCoupon)
{
  char delim[] = ";";
  char tmpStr[100];

  FILE *fi;
  fi = fopen(PATH_COUPON, "r");
  if (fi == NULL)
  {
    exit(1);
  }
  else
  {
    int i = 0;
    while (fgets(tmpStr, 100, fi) != NULL)
    {
      char *ptr = strtok(tmpStr, delim);
      (ptrCoupon + i)->ownerID = atoi(ptr);
      ptr = strtok(NULL, delim);
      (ptrCoupon + i)->couponName = (char *)calloc(100, sizeof(char));
      strcpy((ptrCoupon + i)->couponName, ptr);
      ptr = strtok(NULL, delim);
      (ptrCoupon + i)->discount = atoi(ptr);
      i++;
    }
  }
  fclose(fi);
}

void writeCouponToFile(Coupon *ptrCoupon, int length)
{
  FILE *fo;
  fo = fopen(PATH_COUPON, "w");

  for (int i = 0; i < length; i++)
  {
    fprintf(fo, "%d;", (ptrCoupon + i)->ownerID);
    fputs((ptrCoupon + i)->couponName, fo);
    fprintf(fo, ";%d\n", (ptrCoupon + i)->discount);
    // fprintf(fo, ";");
  }
  fclose(fo);
}

void addCoupon(int ownerID, int discount, char *couponName)
{
  Coupon *ptrCoupon;
  int length = countLineInFile(PATH_COUPON);

  ptrCoupon = (Coupon *)calloc(length + 1, sizeof(Coupon));
  getCouponFromFile(ptrCoupon);
  (ptrCoupon + length)->ownerID = ownerID;
  (ptrCoupon + length)->discount = discount;
  (ptrCoupon + length)->couponName = (char *)calloc(100, sizeof(char));
  strcpy((ptrCoupon + length)->couponName, couponName);
  writeCouponToFile(ptrCoupon, ++length);
  // free(ptrCoupon);
}

void sortCouponDescending(Coupon *listCoupon, int length)
{
  Coupon tmpCoupon;

  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      if ((listCoupon + i)->discount < (listCoupon + k)->discount)
      {
        tmpCoupon = *(listCoupon + i);
        *(listCoupon + i) = *(listCoupon + k);
        *(listCoupon + k) = tmpCoupon;
      }
    }
  }
}

Coupon getCoupon(int ownerID)
{
  Coupon *listCoupon;
  Coupon *foundCoupon;
  int length = countLineInFile(PATH_COUPON);

  listCoupon = (Coupon *)calloc(length, sizeof(Coupon));
  foundCoupon = (Coupon *)calloc(length, sizeof(Coupon));
  getCouponFromFile(listCoupon);
  int count = 0;
  for (int i = 0; i < length; i++)
  {
    if (ownerID == (listCoupon + i)->ownerID)
    {
      *(foundCoupon + count++) = *(listCoupon + i);
    }
  }
  // free(listCoupon);
  sortCouponDescending(foundCoupon, count);
  return *(foundCoupon);
}

int isValidCoupon(char *str)
{
  int check = 1;
  int length = strlen(str);
  if (length < 2 || length > 20)
  {
    check = 0;
  }
  else
  {
    int i = 0;
    while (str[i] != '\0')
    {
      if (!isNum(str[i]) && !isChar(str[i]))
      {
        check = 0;
        break;
      }
      i++;
    }
  }
  return check;
}

int isAvailableCoupon(char *couName, int ownerID, int *discount)
{
  int check = 0;
  int length = countLineInFile(PATH_COUPON);
  *discount = 0;
  Coupon *listCoupon;

  // printf("dddd\n");
  listCoupon = (Coupon *)calloc(length, sizeof(Coupon));
  getCouponFromFile(listCoupon);
  if (ownerID == -1)
  {
    for (int i = 0; i < length; i++)
    {
      if (-1 == (listCoupon + i)->ownerID)
      {
        if (strcmp((listCoupon + i)->couponName, couName) == 0)
        {
          printf("a\n");
          check = 1;
          *discount = (listCoupon + i)->discount;
          break;
        }
      }
    }
  }
  else
  {
    for (int i = 0; i < length; i++)
    {
      if (ownerID == (listCoupon + i)->ownerID || (listCoupon + i)->ownerID == -1)
      {
        if (strcmp((listCoupon + i)->couponName, couName) == 0)
        {
          check = 1;
          *discount = (listCoupon + i)->discount;
          break;
        }
      }
    }
  }
  // free(listCoupon);
  return check;
}

void deleteCoupon(char *couName, int ownerID)
{
  Coupon *listCoupon;
  int length = countLineInFile(PATH_COUPON);
  printf("length: %d\n", length);

  listCoupon = (Coupon *)calloc(length, sizeof(Coupon));
  getCouponFromFile(listCoupon);
  for (int i = 0; i < length; i++)
  {
    if ((strcmp(couName, (listCoupon + i)->couponName) == 0) && (ownerID == (listCoupon + i)->ownerID))
    {
      length -= 1;
      for (int k = i; k < length; k++)
      {
        *(listCoupon + k) = *(listCoupon + k + 1);
      }
      i -= 1;
    }
  }
  writeCouponToFile(listCoupon, length);
  // free(listCoupon);
}

int processCart(char *cusName, char *address, char *phoneNum, int method, Goods *purchaseGoods, int cartLength, int userID, char *coupon)
{
  int check = 1;
  int couponDiscount = 0;
  int sizeGoods;
  char *tmpStr;

  tmpStr = (char *)calloc(120, sizeof(char));
  tmpStr = filterVietnamese(cusName);
  // removeExtraSpaces(cusName);
  if (!isValidName(tmpStr))
  {
    check = 2;
  }
  else
  {
    // removeExtraSpaces(address);
    tmpStr = filterVietnamese(address);
    if (!isValidAddress(tmpStr))
    {
      check = 3;
    }
    else if (!isValidPhoneNum(phoneNum))
    {
      check = 4;
    }
    else
    {
      // removeExtraSpaces(coupon);
      if (coupon != "-1")
      { //-1 mean don't have coupon
        if (!isValidCoupon(coupon))
        {
          check = 5;
        }
        else if (!isAvailableCoupon(coupon, userID, &couponDiscount))
        {
          check = 5;
        }
      }
    }
  }

  if (check == 1)
  {
    time_t now;
    time(&now);

    if (userID == -1)
    {
      for (int i = 0; i < cartLength; i++)
      {
        char *tmp = filterVietnamese(cusName);
        addSalesHistory(*(purchaseGoods + i), tmp); //checked
      }
    }
    else
    {
      PurchaseHistory purchasedInfo;
      int64_t totalPrice = 0;
      User user = getUserByID(userID);

      for (int i = 0; i < cartLength; i++)
      {
        User seller = getUserByID((purchaseGoods + i)->ownerID);
        addSalesHistory(*(purchaseGoods + i), seller.userName);
        strcpy(purchasedInfo.listGoods[i], (purchaseGoods + i)->name);
        // printf("list good %d: %s\n", i, purchasedInfo.listGoods[i]);
        int64_t amount = (int64_t)((purchaseGoods + i)->price * (float)((purchaseGoods + i)->discount / 100.0));
        totalPrice += ((purchaseGoods + i)->price - amount);
        // deleteGoods((purchaseGoods + i)->id, &sizeGoods);
      }
      int64_t discountAmount;
      discountAmount = (int)(totalPrice * ((float)couponDiscount / 100.0));
      totalPrice -= (discountAmount);
      purchasedInfo.sizeListGoods = cartLength;
      // printf("sizelist: %d\n", purchasedInfo.sizeListGoods);
      purchasedInfo.totalPrice = totalPrice;
      // printf("total price: %d\n", totalPrice);
      purchasedInfo.time = now;
      // printf("time: %d\n", purchasedInfo.time);
      purchasedInfo.purchaseType = (char *)calloc(30, sizeof(char));
      if (method == 1)
      {
        strcpy(purchasedInfo.purchaseType, "COD");
      }
      else
      {

        strcpy(purchasedInfo.purchaseType, "Thanh toán bằng số dư");
      }
      // printf("method: %s\n", purchasedInfo.purchaseType);
      //phải cấp bộ nhớ rồi mới copy vô được????
      purchasedInfo.name = (char *)calloc(120, sizeof(char));
      strcpy(purchasedInfo.name, cusName);
      // printf("name: %s\n", purchasedInfo.name);
      purchasedInfo.address = (char *)calloc(120, sizeof(char));
      strcpy(purchasedInfo.address, address);
      // printf("address: %s\n", purchasedInfo.address);
      purchasedInfo.phone = (char *)calloc(120, sizeof(char));
      strcpy(purchasedInfo.phone, phoneNum);
      // printf("phone: %s\n", purchasedInfo.phone);
      //check payment method.
      if (method == 2)
      {

        if (user.balance - totalPrice < 0)
        {
          check = 6;
        }
        else
        {
          user.balance -= totalPrice;
          for (int i = 0; i < cartLength; i++)
          {
            User seller = getUserByID((purchaseGoods + i)->ownerID);
            int64_t amount = (int64_t)((purchaseGoods + i)->price * (100 - (purchaseGoods + i)->discount) / 100);
            seller.balance += amount;
            editUserToFile(seller);
          }
          editUserToFile(user);
        }
      }
      if (check == 1)
      {
        deleteCoupon(coupon, userID);
        addPurchaseHistory(user.userName, purchasedInfo);
      }
    }
  }
  return check;
}

SalesHistory *getSalesHistoryByTime(char *userName, int *sizeArr, time_t start, time_t end)
{
  SalesHistory *allPurchased;
  SalesHistory *foundPurchased;
  int foundLength = 0;
  int allLength = 0;

  allPurchased = getSalesHistory(userName, &allLength);
  if (allLength != 0)
  {
    foundPurchased = (SalesHistory *)calloc(allLength, sizeof(SalesHistory));
    for (int i = 0; i < allLength; i++)
    {
      if (((allPurchased + i)->time >= start) && ((allPurchased + i)->time <= end))
      {
        *(foundPurchased + foundLength++) = *(allPurchased + i);
      }
    }
  }
  *sizeArr = foundLength;
  return foundPurchased;
}

#endif