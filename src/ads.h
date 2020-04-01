#ifndef ADS_H
#define ADS_H

#include "shopping_cart.h"

void sortAdsMoneyDecending(AdsItem *ptrAds, int length);
void deleteAdsItem(int onwerID, int goodsID);
void deleteAdsItemByGoodsID(int goodsID);
void getAdsFromFile(AdsItem *adsItem);
void writeAdsToFile(AdsItem *adsItem, int length);
void updateAdsItem(int ownerID, int goodsiD, long budget);
void deleteAdsItemBudget(long number);
int isYourGoods(int goodsID, int ownerID);
int addAds(int ownerID, int goodsID, long budget, long money);
long getAverageMoney();
AdsItem *getAllAdsItem(int *length);

void sortAdsMoneyDecending(AdsItem *ptrAds, int length)
{
  AdsItem tmpAds;

  for (int i = 0; i < length; i++)
  {
    for (int k = i + 1; k < length; k++)
    {
      if ((ptrAds + i)->money < (ptrAds + k)->money)
      {
        tmpAds = *(ptrAds + i);
        *(ptrAds + i) = *(ptrAds + k);
        *(ptrAds + k) = tmpAds;
      }
    }
  }
}

AdsItem *getAllAdsItem(int *length)
{
  AdsItem *ptrAds;
  *length = countLineInFile(PATH_ADS);

  ptrAds = (AdsItem *)calloc(*length, sizeof(AdsItem));
  getAdsFromFile(ptrAds);
  sortAdsMoneyDecending(ptrAds, *length);
  return ptrAds;
}

void deleteAdsItem(int ownerID, int goodsID)
{
  AdsItem *ptrAds;
  int length = countLineInFile(PATH_ADS);

  ptrAds = (AdsItem *)calloc(length, sizeof(AdsItem));
  getAdsFromFile(ptrAds);
  for (int i = 0; i < length; i++)
  {
    if (goodsID == (ptrAds + i)->goodID && ownerID == (ptrAds + i)->ownerID)
    {
      length -= 1;
      for (int k = i; k < length; k++)
      {
        *(ptrAds + k) = *(ptrAds + k + 1);
      }
      break;
    }
  }
  writeAdsToFile(ptrAds, length);
  free(ptrAds);
}
void deleteAdsItemByGoodsID(int goodsID)
{
  AdsItem *ptrAds;
  int length = countLineInFile(PATH_ADS);

  ptrAds = (AdsItem *)calloc(length, sizeof(AdsItem));
  getAdsFromFile(ptrAds);
  for (int i = 0; i < length; i++)
  {
    if (goodsID == (ptrAds + i)->goodID)
    {
      length -= 1;
      for (int k = i; k < length; k++)
      {
        *(ptrAds + k) = *(ptrAds + k + 1);
      }
      break;
    }
  }
  writeAdsToFile(ptrAds, length);
  free(ptrAds);
}
void getAdsFromFile(AdsItem *adsItem)
{
  char delim[] = ";";
  char tmpStr[100];

  FILE *fi;
  fi = fopen(PATH_ADS, "r");
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
      (adsItem + i)->goodID = atoi(ptr);
      ptr = strtok(NULL, delim);
      (adsItem + i)->ownerID = atoi(ptr);
      ptr = strtok(NULL, delim);
      (adsItem + i)->budget = atoi(ptr);
      ptr = strtok(NULL, delim);
      (adsItem + i)->money = atoi(ptr);
      i++;
    }
  }
  fclose(fi);
}

void writeAdsToFile(AdsItem *adsItem, int length)
{
  FILE *fo;
  fo = fopen(PATH_ADS, "w");

  for (int i = 0; i < length; i++)
  {
    fprintf(fo, "%d;%d;%ld;%ld\n", (adsItem + i)->goodID, (adsItem + i)->ownerID, (adsItem + i)->budget, (adsItem + i)->money);
  }
  fclose(fo);
}

void updateAdsItem(int ownerID, int goodsID, long budget)
{
  AdsItem *ptrAds;
  int length = countLineInFile(PATH_ADS);

  ptrAds = (AdsItem *)calloc(length, sizeof(AdsItem));
  getAdsFromFile(ptrAds);
  for (int i = 0; i < length; i++)
  {
    if (goodsID == (ptrAds + i)->goodID && ownerID == (ptrAds + i)->ownerID)
    {
      (ptrAds + i)->budget = budget;
      break;
    }
  }
  writeAdsToFile(ptrAds, length);
  free(ptrAds);
}
int isYourGoods2(int goodsID)
{
  int check = 0;
  Goods *ptrGoods;
  size_t length;

  ptrGoods = getAllGoods(&length);
  for (int i = 0; i < length; i++)
  {
    if (goodsID == (ptrGoods + i)->id)
    {
      check = 1;
      break;
    }
  }
  return check;
}
int isYourGoods(int goodsID, int ownerID)
{
  int check = 0;
  Goods *ptrGoods;
  size_t length;

  ptrGoods = getAllGoods(&length);
  for (int i = 0; i < length; i++)
  {
    if (goodsID == (ptrGoods + i)->id)
    {
      if (ownerID == (ptrGoods + i)->ownerID)
      {
        check = 1;
        break;
      }
      else
        break;
    }
  }
  return check;
}

void deleteAdsItemBudget(long number)
{
  AdsItem *ptrAds;
  int length = countLineInFile(PATH_ADS);

  ptrAds = (AdsItem *)calloc(length, sizeof(AdsItem));
  getAdsFromFile(ptrAds);
  for (int i = 0; i < length; i++)
  {
    if ((ptrAds + i)->budget < number)
    {
      length -= 1;
      for (int k = i; k < length; k++)
      {
        *(ptrAds + k) = *(ptrAds + k + 1);
      }
      i -= 1;
    }
  }
  writeAdsToFile(ptrAds, length);
  free(ptrAds);
}

long getAverageMoney()
{
  AdsItem *ptrAds;
  int length = countLineInFile(PATH_ADS);
  long result, sum = 0;
  if (length == 0)
    return 0;
  ptrAds = (AdsItem *)calloc(length, sizeof(AdsItem));
  getAdsFromFile(ptrAds);
  for (int i = 0; i < length; i++)
  {
    sum += (ptrAds + i)->money;
  }
  result = sum / length;
  free(ptrAds);
  return result;
}

int addAds(int ownerID, int goodsID, long budget, long money)
{
  int check = 1;

  if (!isYourGoods(goodsID, ownerID))
  {
    check = 2;
  }
  else if (money <= 0)
  {
    check = 3;
  }
  else if (budget < money)
  {
    check = 4;
  }

  if (check == 1)
  {
    AdsItem *ptrAds;
    int length = countLineInFile(PATH_ADS);

    ptrAds = (AdsItem *)calloc(length + 1, sizeof(AdsItem));
    getAdsFromFile(ptrAds);
    (ptrAds + length)->goodID = goodsID;
    (ptrAds + length)->ownerID = ownerID;
    (ptrAds + length)->budget = budget;
    (ptrAds + length)->money = money;
    writeAdsToFile(ptrAds, ++length);
    free(ptrAds);
  }

  return check;
}

#endif