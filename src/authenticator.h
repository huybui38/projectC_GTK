#ifndef GET_DATA_H
#define GET_DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "define.h"
#define MAX 40
// #define PATH_USER "shopee\\data\\user.txt"

void getDataFromFile(User *user);
// void removeExtraSpace(char *str);
// void cutString(char str[200], int start);
void writeDataToFile(User *ptrUser, int lineCount);
void lowerString(char str[130]);
char *replaceWord(const char *s, const char *oldW,
				  const char *newW);
char *filterVietnamese(char *word);
int countLineInFile(char filename[MAX]);
int isNum(char ch);
int isChar(char ch);
int isValidUsername(char str[MAX]);
int isValidName(char str[MAX]);
int isValidPassword(char str[MAX]);
int isValidAddress(char str[MAX]);
int isValidPhoneNum(char str[MAX]);
int isValidRole(char str[MAX]);
int getLogin(char username[], char password[]);
int getRegister(char username[], char name[], char pass[], char repass[],
				char address[], char phone[], int role);
int isExistedUsername(char str[MAX], User user[], int *pos, int *length);

int isValidRole(char str[MAX])
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
		if (tmp != 1 && tmp != 2)
		{
			check = 0;
		}
	}
	return check;
}

char *replaceWord(const char *s, const char *oldW,
				  const char *newW)
{
	char *result;
	int i, cnt = 0;
	int newWlen = strlen(newW);
	int oldWlen = strlen(oldW);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (strstr(&s[i], oldW) == &s[i])
		{
			cnt++;
			i += oldWlen - 1;
		}
	}
	result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);
	i = 0;
	while (*s)
	{
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

char *filterVietnamese(char *word)
{
	char temp[999][999];
	//A: 17 (0)
	strcpy(temp[0], replaceWord(word, "À", "A"));
	strcpy(temp[1], replaceWord(temp[0], "Á", "A"));
	strcpy(temp[2], replaceWord(temp[1], "Ạ", "A"));
	strcpy(temp[3], replaceWord(temp[2], "Ả", "A"));
	strcpy(temp[4], replaceWord(temp[3], "Ã", "A"));
	strcpy(temp[5], replaceWord(temp[4], "Â", "A"));
	strcpy(temp[6], replaceWord(temp[5], "Ầ", "A"));
	strcpy(temp[7], replaceWord(temp[6], "Ấ", "A"));
	strcpy(temp[8], replaceWord(temp[7], "Ậ", "A"));
	strcpy(temp[9], replaceWord(temp[8], "Ẩ", "A"));
	strcpy(temp[10], replaceWord(temp[9], "Ẫ", "A"));
	strcpy(temp[11], replaceWord(temp[10], "Ă", "A"));
	strcpy(temp[12], replaceWord(temp[11], "Ằ", "A"));
	strcpy(temp[13], replaceWord(temp[12], "Ắ", "A"));
	strcpy(temp[14], replaceWord(temp[13], "Ẳ", "A"));
	strcpy(temp[15], replaceWord(temp[14], "Ẵ", "A"));
	strcpy(temp[16], replaceWord(temp[15], "Ặ", "A"));
	//a: 17 (17)
	strcpy(temp[17], replaceWord(temp[16], "à", "a"));
	strcpy(temp[18], replaceWord(temp[17], "á", "a"));
	strcpy(temp[19], replaceWord(temp[18], "ả", "a"));
	strcpy(temp[20], replaceWord(temp[19], "ã", "a"));
	strcpy(temp[21], replaceWord(temp[20], "ạ", "a"));
	strcpy(temp[22], replaceWord(temp[21], "ă", "a"));
	strcpy(temp[23], replaceWord(temp[22], "ằ", "a"));
	strcpy(temp[24], replaceWord(temp[23], "ắ", "a"));
	strcpy(temp[25], replaceWord(temp[24], "ẳ", "a"));
	strcpy(temp[26], replaceWord(temp[25], "ẵ", "a"));
	strcpy(temp[27], replaceWord(temp[26], "ặ", "a"));
	strcpy(temp[28], replaceWord(temp[27], "â", "a"));
	strcpy(temp[29], replaceWord(temp[28], "ầ", "a"));
	strcpy(temp[30], replaceWord(temp[29], "ấ", "a"));
	strcpy(temp[31], replaceWord(temp[30], "ẩ", "a"));
	strcpy(temp[32], replaceWord(temp[31], "ẫ", "a"));
	strcpy(temp[33], replaceWord(temp[32], "ậ", "a"));
	//E: 11 (34)
	strcpy(temp[34], replaceWord(temp[33], "È", "E"));
	strcpy(temp[35], replaceWord(temp[34], "É", "E"));
	strcpy(temp[36], replaceWord(temp[35], "Ẻ", "E"));
	strcpy(temp[37], replaceWord(temp[36], "Ẽ", "E"));
	strcpy(temp[38], replaceWord(temp[37], "Ẹ", "E"));
	strcpy(temp[39], replaceWord(temp[38], "Ê", "E"));
	strcpy(temp[40], replaceWord(temp[39], "Ề", "E"));
	strcpy(temp[41], replaceWord(temp[40], "Ế", "E"));
	strcpy(temp[42], replaceWord(temp[41], "Ể", "E"));
	strcpy(temp[43], replaceWord(temp[42], "Ễ", "E"));
	strcpy(temp[44], replaceWord(temp[43], "Ệ", "E"));
	//e: 11 (45)
	strcpy(temp[45], replaceWord(temp[44], "è", "e"));
	strcpy(temp[46], replaceWord(temp[45], "é", "e"));
	strcpy(temp[47], replaceWord(temp[46], "ẻ", "e"));
	strcpy(temp[48], replaceWord(temp[47], "ẽ", "e"));
	strcpy(temp[49], replaceWord(temp[48], "ẹ", "e"));
	strcpy(temp[50], replaceWord(temp[49], "ê", "e"));
	strcpy(temp[51], replaceWord(temp[50], "ề", "e"));
	strcpy(temp[52], replaceWord(temp[51], "ế", "e"));
	strcpy(temp[53], replaceWord(temp[52], "ể", "e"));
	strcpy(temp[54], replaceWord(temp[53], "ễ", "e"));
	strcpy(temp[55], replaceWord(temp[54], "ệ", "e"));
	//I: 5 (56)
	strcpy(temp[56], replaceWord(temp[55], "Ì", "I"));
	strcpy(temp[57], replaceWord(temp[56], "Í", "I"));
	strcpy(temp[58], replaceWord(temp[57], "Ỉ", "I"));
	strcpy(temp[59], replaceWord(temp[58], "Ĩ", "I"));
	strcpy(temp[60], replaceWord(temp[59], "Ị", "I"));
	//i: 5 (61)
	strcpy(temp[61], replaceWord(temp[60], "ì", "i"));
	strcpy(temp[62], replaceWord(temp[61], "í", "i"));
	strcpy(temp[63], replaceWord(temp[62], "ỉ", "i"));
	strcpy(temp[64], replaceWord(temp[63], "ĩ", "i"));
	strcpy(temp[65], replaceWord(temp[64], "ị", "i"));
	//O: 17 (66)
	strcpy(temp[66], replaceWord(temp[65], "Ò", "O"));
	strcpy(temp[67], replaceWord(temp[66], "Ó", "O"));
	strcpy(temp[68], replaceWord(temp[67], "Ỏ", "O"));
	strcpy(temp[69], replaceWord(temp[68], "Õ", "O"));
	strcpy(temp[70], replaceWord(temp[69], "Ọ", "O"));
	strcpy(temp[71], replaceWord(temp[70], "Ô", "O"));
	strcpy(temp[72], replaceWord(temp[71], "Ồ", "O"));
	strcpy(temp[73], replaceWord(temp[72], "Ố", "O"));
	strcpy(temp[74], replaceWord(temp[73], "Ổ", "O"));
	strcpy(temp[75], replaceWord(temp[74], "Ỗ", "O"));
	strcpy(temp[76], replaceWord(temp[75], "Ộ", "O"));
	strcpy(temp[77], replaceWord(temp[76], "Ơ", "O"));
	strcpy(temp[78], replaceWord(temp[77], "Ờ", "O"));
	strcpy(temp[79], replaceWord(temp[78], "Ớ", "O"));
	strcpy(temp[80], replaceWord(temp[79], "Ở", "O"));
	strcpy(temp[81], replaceWord(temp[80], "Ỡ", "O"));
	strcpy(temp[82], replaceWord(temp[81], "Ợ", "O"));
	//o: 17 (83)
	strcpy(temp[83], replaceWord(temp[82], "ò", "o"));
	strcpy(temp[84], replaceWord(temp[83], "ó", "o"));
	strcpy(temp[85], replaceWord(temp[84], "ỏ", "o"));
	strcpy(temp[86], replaceWord(temp[85], "õ", "o"));
	strcpy(temp[87], replaceWord(temp[86], "ọ", "o"));
	strcpy(temp[88], replaceWord(temp[87], "ô", "o"));
	strcpy(temp[89], replaceWord(temp[88], "ồ", "o"));
	strcpy(temp[90], replaceWord(temp[89], "ố", "o"));
	strcpy(temp[91], replaceWord(temp[90], "ổ", "o"));
	strcpy(temp[92], replaceWord(temp[91], "ỗ", "o"));
	strcpy(temp[93], replaceWord(temp[92], "ộ", "o"));
	strcpy(temp[94], replaceWord(temp[93], "ơ", "o"));
	strcpy(temp[95], replaceWord(temp[94], "ờ", "o"));
	strcpy(temp[96], replaceWord(temp[95], "ớ", "o"));
	strcpy(temp[97], replaceWord(temp[96], "ở", "o"));
	strcpy(temp[98], replaceWord(temp[97], "ỡ", "o"));
	strcpy(temp[99], replaceWord(temp[98], "ợ", "o"));
	//U: 11 (100)
	strcpy(temp[100], replaceWord(temp[99], "Ù", "U"));
	strcpy(temp[101], replaceWord(temp[100], "Ú", "U"));
	strcpy(temp[102], replaceWord(temp[101], "Ủ", "U"));
	strcpy(temp[103], replaceWord(temp[102], "Ũ", "U"));
	strcpy(temp[104], replaceWord(temp[103], "Ụ", "U"));
	strcpy(temp[105], replaceWord(temp[104], "Ư", "U"));
	strcpy(temp[106], replaceWord(temp[105], "Ừ", "U"));
	strcpy(temp[107], replaceWord(temp[106], "Ứ", "U"));
	strcpy(temp[108], replaceWord(temp[107], "Ử", "U"));
	strcpy(temp[109], replaceWord(temp[108], "Ữ", "U"));
	strcpy(temp[110], replaceWord(temp[109], "Ự", "U"));
	//u: 11 (111)
	strcpy(temp[111], replaceWord(temp[110], "ù", "u"));
	strcpy(temp[112], replaceWord(temp[111], "ú", "u"));
	strcpy(temp[113], replaceWord(temp[112], "ủ", "u"));
	strcpy(temp[114], replaceWord(temp[113], "ũ", "u"));
	strcpy(temp[115], replaceWord(temp[114], "ụ", "u"));
	strcpy(temp[116], replaceWord(temp[115], "ư", "u"));
	strcpy(temp[117], replaceWord(temp[116], "ừ", "u"));
	strcpy(temp[118], replaceWord(temp[117], "ứ", "u"));
	strcpy(temp[119], replaceWord(temp[118], "ử", "u"));
	strcpy(temp[120], replaceWord(temp[119], "ữ", "u"));
	strcpy(temp[121], replaceWord(temp[120], "ự", "u"));
	//Y: 5 (122)
	strcpy(temp[122], replaceWord(temp[121], "Ỳ", "Y"));
	strcpy(temp[123], replaceWord(temp[122], "Ý", "Y"));
	strcpy(temp[124], replaceWord(temp[123], "Ỷ", "Y"));
	strcpy(temp[125], replaceWord(temp[124], "Ỹ", "Y"));
	strcpy(temp[126], replaceWord(temp[125], "Ỵ", "Y"));
	//y: 5 (127)
	strcpy(temp[127], replaceWord(temp[126], "ỳ", "y"));
	strcpy(temp[128], replaceWord(temp[127], "ý", "y"));
	strcpy(temp[129], replaceWord(temp[128], "ỷ", "y"));
	strcpy(temp[130], replaceWord(temp[129], "ỹ", "y"));
	strcpy(temp[131], replaceWord(temp[130], "ỵ", "y"));
	//Đ: 1 (132)
	strcpy(temp[132], replaceWord(temp[131], "Đ", "D"));
	//d: 1 (133)
	strcpy(temp[133], replaceWord(temp[132], "đ", "d"));
	char *result = temp[133];
	return result;
}

void lowerString(char str[130])
{
	int i = 0;
	while (str[i] != '\0')
	{
		str[i] = tolower(str[i]);
		i++;
	}
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

void getDataFromFile(User *user)
{
	char delim[] = "-";
	char tmpStr[100];

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

int getLogin(char username[], char password[])
{
	int check = 0;
	int pos, length;
	User *ptrUser;
	char c;
	int lineCount = 0;

	lineCount = countLineInFile(PATH_USER);
	ptrUser = (User *)malloc((lineCount) * sizeof(User));

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

// void cutString(char str[200], int start) {
//   int length = strlen(str);
// 	int i;
// 	printf("ok\n");
// 	for (i = start; i < length; i++) {
// 		printf("cut: %d\n", i);
//     // *(str + i) = *(str + i + 1);
// 		str[i] = str[i + 1];
// 	}
// }

// void removeExtraSpace(char *str) {
// 	int i = 0;
// 	//check beginning
// 	if (str[0] == ' ') {
// 		while (str[i] == ' ') {
// 			cutString(str, i);
// 		}
// 	}
// 	//check middle
// 	while (str[i] != '\0') {
// 		while (str[i] == ' ' && str[i + 1] == ' ') {
// 			cutString(str, i);
// 		}
// 		i++;
// 	}
// 	//check end
// 	while (str[strlen(str) - 1] == ' ') {
// 	  cutString(str, strlen(str) - 1);
// 	}
// }

int isValidAddress(char str[MAX])
{
	// g_print("=>>>%s\n", str[MAX]);
	int check = 1;
	int i = 0;
	while (str[i] != '\0')
	{
		if (!isNum(str[i]) && !isChar(str[i]) && str[i] != '/' && str[i] != ',' && str[i] != ' ')
		{
			check = 0;
			break;
		}
		i++;
	}
	return check;
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
	int length = strlen(str);

	if (length < 3 || length > 15)
	{
		check = 0;
	}
	else
	{
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

int isValidName(char str[MAX])
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

int isValidPassword(char str[MAX])
{
	int i = 0;
	int check = 1;
	int length = strlen(str);

	if (length < 3 || length > 15)
	{
		check = 0;
	}
	else
	{
		while (str[i] != '\0')
		{
			if (!isNum(str[i]) && !isChar(str[i]) && str[i] == ' ')
			{
				check = 0;
				break;
			}
			i++;
		}
	}

	return check;
}

int isValidPhoneNum(char str[MAX])
{
	int check = 1;
	int i = 0;
	int minLength = 8, maxLength = 11;
	if (str[0] == '+')
	{
		i++;			//+ is valid in phoneNum so skip first char
		maxLength = 13; //+84 is identical with 0 => increase maxlength by 2;
	}

	while (str[i] != '\0')
	{
		if (!isNum(str[i]))
		{
			check = 0;
			break;
		}
		i++;
	}
	int length = strlen(str);
	if (length < minLength || length > maxLength)
	{
		check = 0;
	}
	return check;
}

int getRegister(char username[], char name[], char pass[], char repass[],
				char address[], char phoneNum[], int role)
{
	int check = 1;
	int pos;
	int length;
	char c;
	int lineCount = 0;
	char *lowerName, *lowerAddress;
	User *user;
	lineCount = countLineInFile(PATH_USER);
	user = (User *)malloc((lineCount + 1) * sizeof(User));
	//lineCount + 1 de ty nua ghi them

	getDataFromFile(user);
	// g_print("Before:%s\n", name);
	lowerName = filterVietnamese(name);
	lowerAddress = filterVietnamese(address);

	// g_print("After:%s\n", lowerAddress);
	// removeExtraSpace(name);
	// removeExtraSpace(lowerName);
	// removeExtraSpace(address);
	// removeExtraSpace(lowerAddress);

	if (!isValidUsername(username))
	{
		check = 7;
	}
	else if (isExistedUsername(username, user, &pos, &lineCount))
	{
		check = 8;
	}
	else if (!isValidName(lowerName))
	{
		// g_print("%s", lowerName);
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
	else if (!isValidAddress(lowerAddress))
	{
		check = 3;
	}
	else if (role != 1 && role != 2)
	{
		check = 2;
	}
	else if (!isValidPhoneNum(phoneNum))
	{
		check = 9;
	}
	//write data to file
	if (check == 1)
	{
		strcpy((user + lineCount)->userName, username);
		strcpy((user + lineCount)->name, name);
		strcpy((user + lineCount)->password, pass);
		strcpy((user + lineCount)->address, address);
		strcpy((user + lineCount)->phoneNum, phoneNum);
		(user + lineCount)->id = lineCount + 1;
		(user + lineCount)->role = role;
		(user + lineCount)->balance = 0;
		writeDataToFile(user, ++lineCount);
	}
	free(user);

	return check;
}

#endif
