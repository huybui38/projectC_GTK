#ifndef EDIT_USER_H
#define EDIT_USER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "authenticator.h"
#include "define.h"

User getUser(char username[MAX]);
User *getAllUser();
void addMoney(char username[MAX], unsigned long amount);
void writeDataToFile(User *ptrUser, int linCount);
void changeInfomation(int id, char name[MAX], char address[MAX]);
void changePassword(int id, char newPassword[MAX]);

User getUser(char username[MAX])
{
	User *ptrUser;
	User matchedUser;

	int lineCount = countLineInFile(PATH_USER);

	ptrUser = malloc(lineCount * sizeof(User));
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

void writeDataToFile(User *ptrUser, int lineCount)
{
	FILE *fo;
	fo = fopen(PATH_USER, "w");

	for (int i = 0; i < lineCount; i++)
	{
		fprintf(fo, "%d-", (ptrUser + i)->id);
		fputs((ptrUser + i)->userName, fo);
		fprintf(fo, "-");
		fputs((ptrUser + i)->password, fo);
		fprintf(fo, "-");
		fputs((ptrUser + i)->name, fo);
		fprintf(fo, "-");
		fputs((ptrUser + i)->address, fo);
		fprintf(fo, "-");
		fputs((ptrUser + i)->phoneNum, fo);
		fprintf(fo, "-");
		fprintf(fo, "%d-%lu\n", (ptrUser + i)->role, (ptrUser + i)->balance);
	}
	fclose(fo);
}

void addMoney(char username[MAX], unsigned long amount)
{
	User *ptrUser;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	for (int i = 0; i < lineCount; i++)
	{
		if (strcmp((ptrUser + i)->userName, username) == 0)
		{
			(ptrUser + i)->balance = (ptrUser + i)->balance + amount;
			break;
		}
	}
	writeDataToFile(ptrUser, lineCount);

	free(ptrUser);
}

void changeInformation(int id, char name[MAX], char address[MAX])
{
	User *ptrUser;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	for (int i = 0; i < lineCount; i++)
	{
		if ((ptrUser + i)->id == id)
		{
			strcpy((ptrUser + i)->name, name);
			strcpy((ptrUser + i)->address, address);
			break;
		}
	}
	writeDataToFile(ptrUser, lineCount);

	free(ptrUser);
}

void changePassword(int id, char newPassword[MAX])
{
	User *ptrUser;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	for (int i = 0; i < lineCount; i++)
	{
		if ((ptrUser + i)->id == id)
		{
			strcpy((ptrUser + i)->password, newPassword);
			break;
		}
	}
	writeDataToFile(ptrUser, lineCount);

	free(ptrUser);
}

User *getAllUser()
{
	User *ptrUser;

	int lineCount = countLineInFile(PATH_USER);
	ptrUser = malloc(lineCount * sizeof(User));
	getDataFromFile(ptrUser);

	return ptrUser;
	// free(ptrUser);
}

#endif