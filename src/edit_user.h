#ifndef EDIT_USER_H
#define EDIT_USER_H

// #include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "authenticator.h"

User getUser(char username[MAX]);
User *getAllUser();
int addMoney(char username[MAX], char amount[MAX]);
int isValidAmount(char str[MAX]);
int isValidID(char str[MAX]);
int isExistedId(int id, User *ptrUser, int *pos, int *length);
int changeInformation(int id, char name[MAX], char address[MAX], char phoneNum[MAX]);
int changePassword(int id, char newPassword[MAX]);

User getUser(char username[MAX])
{
	User *ptrUser;
	User matchedUser;

	int lineCount = countLineInFile(PATH_USER);

	ptrUser = (User *)malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	for (int i = 0; i < lineCount; i++)
	{
		if (strcmp((ptrUser + i)->userName, username) == 0)
		{
			matchedUser.id = (ptrUser + i)->id;
			strcpy(matchedUser.userName, (ptrUser + i)->userName);
			strcpy(matchedUser.password, (ptrUser + i)->password);
			strcpy(matchedUser.name, (ptrUser + i)->name);
			strcpy(matchedUser.address, (ptrUser + i)->address);
			strcpy(matchedUser.phoneNum, (ptrUser + i)->phoneNum);
			matchedUser.role = (ptrUser + i)->role;
			matchedUser.balance = (ptrUser + i)->balance;
			break;
		}
	}
	free(ptrUser);

	return matchedUser;
}

int isValidAmount(char str[20])
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
	return check;
}
int addMoney(char username[MAX], char amount[MAX])
{
	int check = 1;
	int pos;
	unsigned long money;
	User *ptrUser;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = (User *)malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	if (!isValidUsername(username))
	{
		check = 2;
	}
	else if (!isExistedUsername(username, ptrUser, &pos, &lineCount))
	{
		check = 4;
	}
	else if (!isValidAmount(amount))
	{
		check = 3;
	}
	else
	{
		money = atoi(amount);
		for (int i = 0; i < lineCount; i++)
		{
			if (strcmp((ptrUser + i)->userName, username) == 0)
			{
				(ptrUser + i)->balance = (ptrUser + i)->balance + money;
				break;
			}
		}
		writeDataToFile(ptrUser, lineCount);
	}
	free(ptrUser);

	return check;
}
int isValidID(char str[MAX])
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
	return check;
}
int isExistedId(int id, User *user, int *pos, int *length)
{
	int check = 0;
	int i;
	for (i = 0; i < *length; i++)
	{
		if (id == (user + i)->id)
		{ //==0 means both strings are identical
			check = 1;
			*pos = i;
			break;
		}
	}
	return check;
}

int changeInformation(int id, char name[MAX], char address[MAX], char phoneNum[MAX])
{
	User *ptrUser;
	int check = 1;
	int tmp, pos;
	char *lowerName, *lowerAddress;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = (User *)malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);
	lowerName = filterVietnamese(name);
	lowerAddress = filterVietnamese(address);
	// removeExtraSpace(name);
	// removeExtraSpace(address);

	if (!isExistedId(id, ptrUser, &pos, &lineCount))
	{
		check = 2;
	}
	else if (!isValidName(lowerName))
	{
		check = 3;
	}
	else if (!isValidAddress(lowerAddress))
	{
		check = 4;
	}
	else if (!isValidPhoneNum(phoneNum))
	{
		check = 5;
	}

	if (check == 1)
	{
		strcpy((ptrUser + pos)->name, name);
		strcpy((ptrUser + pos)->address, address);
		strcpy((ptrUser + pos)->phoneNum, phoneNum);
		writeDataToFile(ptrUser, lineCount);
	}
	free(ptrUser);
	return check;
}

int changePassword(int id, char newPassword[MAX])
{
	int check = 1;
	int tmp, pos;
	User *ptrUser;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = (User *)malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	if (!isExistedId(id, ptrUser, &pos, &lineCount))
	{
		check = 2;
	}
	else if (!isValidPassword(newPassword))
	{
		check = 3;
	}

	if (check == 1)
	{
		strcpy((ptrUser + pos)->password, newPassword);
		writeDataToFile(ptrUser, lineCount);
	}

	free(ptrUser);
	return check;
}

User *getAllUser()
{
	User *ptrUser;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = (User *)malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	return ptrUser;
	// free(ptrUser);
}

#endif