

#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "define.h"

void getDataFromFile(User *user);
void removeExtraSpace(char str[40]);
void cutString(char str[40], int start);
int countLineInFile(char filename[MAX]);
int isNum(char ch);
int isChar(char ch);
int isValidUsername(char str[MAX]);
int isValidName(char str[MAX]);
int isValidPassword(char str[MAX]);
int isBlankAddress(char str[MAX]);
int getLogin(char username[], char password[]);
int getRegister(char username[], char name[], char pass[], char repass[], char address[], int role);
int isExistedUsername(char str[MAX], User user[], int *pos, int *length);

int countLineInFile(char filename[MAX])
{
	char c;
	int lineCount = 0;
	char tmpStr[140];

	//count line to malloc for struct array
	FILE *fp;
	fp = fopen(PATH_USER, "r");
	while (fgets(tmpStr, 140, fp) != '\0') // Increment count if this character is newline
		lineCount++;
	fclose(fp);
	return lineCount++; //i can't understand why i have to increase lineCount by 1
}
void getDataFromFile(User *user)
{
	char delim[] = "-";
	char tmpStr[140];

	FILE *fiUser;
	fiUser = fopen(PATH_USER, "r");
	if (fiUser == NULL)
	{
		exit(1);
	}
	else
	{
		int i = 0;
		while (fgets(tmpStr, 140, fiUser) != NULL)
		{
			char *ptr = strtok(tmpStr, delim);
			(user + i)->id = atoi(ptr);
			ptr = strtok(NULL, delim);
			strcpy((user + i)->userName, ptr);
			ptr = strtok(NULL, delim);
			strcpy((user + i)->password, ptr);
			ptr = strtok(NULL, delim);
			strcpy((user + i)->name, ptr);
			ptr = strtok(NULL, delim);
			strcpy((user + i)->address, ptr);
			ptr = strtok(NULL, delim);
			strcpy((user + i)->phoneNum, ptr);
			ptr = strtok(NULL, delim);
			(user + i)->role = atoi(ptr);
			ptr = strtok(NULL, delim);
			(user + i)->balance = atoi(ptr);
			i++;
		}
	}
	fclose(fiUser);
}

int isExistedUsername(char str[], User *user, int *pos, int *length)
{
	int check = 0;
	int i;
	for (i = 0; i < *length; i++)
	{
		if (strcmp(str, (user + i)->userName) == 0)
		{ //==0 means both strings are identical
			check = 1;
			*pos = i;
			break;
		}
	}
	return check;
}

int getLogin(char username[], char password[])
{
	int check = 0;
	int pos, length;
	User *ptrUser;
	char c;
	int lineCount = 0;

	//open file to get number of line in file -> allocate memory
	FILE *fp;
	fp = fopen(PATH_USER, "r");
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') // Increment count if this character is newline
			lineCount = lineCount + 1;
	fclose(fp);
	lineCount++;
	//i can't understand why i have to increase lineCount by 1
	ptrUser = malloc((lineCount) * sizeof(User));

	getDataFromFile(ptrUser);

	if (isExistedUsername(username, ptrUser, &pos, &lineCount))
	{
		if (strcmp(password, (ptrUser + pos)->password) == 0)
		{
			check = (ptrUser + pos)->role;
		}
		else
			check = -1;
	}
	else
		check = -1;
	free(ptrUser);
	return check;
}

void cutString(char str[40], int start)
{
	for (int i = start; i < strlen(str); i++)
	{
		str[i] = str[i + 1];
	}
}

void removeExtraSpace(char str[40])
{
	int i = 0;
	//check beginning
	if (str[0] == ' ')
	{
		while (str[i] == ' ')
		{
			cutString(str, i);
		}
		i++;
	}

	//check middle
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			cutString(str, i);
		}
		i++;
	}

	//check end
	while (str[strlen(str) - 1] == ' ')
	{
		cutString(str, strlen(str));
	}
}

int isNum(char ch)
{
	if (ch >= 48 && ch <= 57)
		return 1;
	else
		return 0;
}

int isChar(char ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		return 1;
	else
		return 0;
}

int isValidUsername(char str[MAX])
{
	int i = 0;
	int check = 1;

	while (str[i] != '\0')
	{
		if (!isNum(str[i]) && !isChar(str[i]))
		{
			check = 0;
			break;
		}
		i++;
	}

	return check;
}

int isValidName(char str[40])
{
	int i = 0;
	int check = 1;

	while (str[i] != '\0')
	{
		if (!isNum(str[i]) && !isChar(str[i]) && str[i] != ' ')
		{
			check = 0;
			break;
		}
		i++;
	}

	return check;
}

int isValidPassword(char str[])
{
	int i = 0;
	int check = 1;

	while (str[i] != '\0')
	{
		if (!isNum(str[i]) && !isChar(str[i]) && str[i] == ' ')
		{
			check = 0;
			break;
		}
		i++;
	}

	return check;
}

int isBlankAddress(char str[])
{
	int i = 0;
	int check;
	int charCount = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			charCount++;
			break;
		}
		i++;
	}

	if (charCount > 0)
		return 0;
	else
		return 1;
}

int getRegister(char username[], char name[], char pass[], char repass[], char address[], int role)
{
	int check = 1;
	int pos;
	int length;
	char c;
	int lineCount = 0;
	User *user;

	//open file to get number of line in file -> allocate memory
	FILE *fp;
	fp = fopen(PATH_USER, "r");
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') // Increment count if this character is newline
			lineCount = lineCount + 1;
	fclose(fp);
	lineCount++;
	//i can't understand why i have to increase lineCount by 1
	user = malloc((lineCount) * sizeof(User));

	getDataFromFile(user);

	if (!isValidUsername(username))
	{
		check = 7;
	}
	else if (isExistedUsername(username, user, &pos, &lineCount))
	{
		check = 8;
	}
	else if (!isValidName(name))
	{
		check = 6;
	}
	else if (!isValidPassword(pass))
	{
		check = 5;
	}
	else if (strcmp(pass, repass) != 0)
	{
		check = 4;
	}
	else if (isBlankAddress(address))
	{
		check = 3;
	}
	else if (role != 1 && role != 2)
	{
		check = 2;
	}
	free(user);

	return check;
}

#endif
