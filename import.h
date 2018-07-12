#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct s1
{
	int roll;
	char name[20];
	int m1, m2, m3, m4;

}s1;
typedef struct s2
{
	int  roll;
	char phone[10];
	char address[30];
	char city[20];
	char pin[6];
}s2;

s1 *scheme1;
s2 *scheme2;
int s1importedlines;
int s2importedlines;
int stringLength(char * a)
{
	int i = 0;
	while (a[i++] != '\0');
	return (--i);
}

int compareString(char * a, char * b)
{
	int i = 0, flag = 0;
	if (stringLength(a) != stringLength(b))
		return 0;
	while (1)
	{
		if (a[i] == b[i])
		{
			if (a[i] == '\0' || b[i] == '\0')
				break;
			i++;
		}
		else
			break;
	}
	if (i != stringLength(a) && i != stringLength(b))
		return 0;
	else
		return 1;
}
int checkInt(char * str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		i++;
	}
	i = 0;
	int num = 0;
	while (str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return num;
}



int import(char * cmd)
{
	//printf("working");
	int i = 0;
	while (cmd[i++] != ' ');
	char * filename = (char *)malloc(sizeof(char) * 100);

	int j = 0;
	while (cmd[i] != ' ')
	{
		filename[j++] = cmd[i++];
	}
	filename[j] = '\0';
	i++;
	//printf("filename = %s\n", filename);
	char scheme[10];
	j = 0;
	while (cmd[i] != '\0')
		scheme[j++] = cmd[i++];
	scheme[j] = '\0';

	const size_t line_size = 201;
	char* k = (char *)malloc(line_size);

	FILE * fp;
	fp = fopen(filename, "r");
	if (!fp)
	{
		printf("filename not found, please try again\n");
		cin.get();
		return 0;
	}
	int lines = 0;
	while (!feof(fp))
	{
		fgets(k, line_size, fp);
		lines++;
	}
	fclose(fp);
	if (scheme[1] == '1')
	{
		scheme1 = (s1 *)malloc(sizeof(s1) * lines);
		s1importedlines = (int)malloc(sizeof(int));
		s1importedlines = lines;
	}
	else if (scheme[1] == '2')
	{
		scheme2 = (s2 *)malloc(sizeof(s2) * lines);
		s2importedlines = (int)malloc(sizeof(int));
		s2importedlines = lines;
	}
	else
	{
		printf("Wrong scheme\n");
		cin.get();
		return 0;
	}
	//glist1 = (s1 *)malloc(sizeof(s1)*);
	//glist2 = (s2 *)malloc(sizeof(s2)*200);

	fp = fopen(filename, "r");

	int q = 0;
	fgets(k, line_size, fp);
	i = 0;
	while (!feof(fp))
	{
		fgets(k, line_size, fp);
		int  i = 0, j = 0, countComma = 0;
		char * str = (char *)malloc(sizeof(char) * 300);
		while (k[i] != '\n')
		{
			if (k[i] != ',' && k[i] != '\n')
				str[j++] = k[i];
			str[j] = '\0';
			if (scheme[1] == '1')
				if (scheme1[q].m3)
					scheme1[q].m4 = checkInt(str);
			if (scheme[1] == '2')
				if (scheme2[q].city)
					strcpy(scheme2[q].pin, str);
			if (k[i] == ',')
			{
				countComma++;
				/*if(countComma == 2)
				printf("string = %s",str);*/
				j = 0;
				if (scheme[1] == '1')
				{
					if (countComma == 1)
						scheme1[q].roll = checkInt(str);
					if (countComma == 2)
						strcpy(scheme1[q].name, str);
					if (countComma == 3)
						scheme1[q].m1 = checkInt(str);
					if (countComma == 4)
						scheme1[q].m2 = checkInt(str);
					if (countComma == 5)
						scheme1[q].m3 = checkInt(str);
					else
						scheme1[q].m4 = checkInt(str);
				}
				else if (scheme[1] == '2')
				{
					//printf("%s, countimport studentinfolist.csv s2COmma = %d\n",str,countComma);
					if (countComma == 1)
						scheme2[q].roll = checkInt(str);
					if (countComma == 2)
						strcpy(scheme2[q].phone, str);
					if (countComma == 3)
						strcpy(scheme2[q].address, str);
					if (countComma == 4)
						strcpy(scheme2[q].city, str);
				}
			}

			i++;
		}
		//free(str);

		/*if(scheme[1] == '1')//.................printing...................
		printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3,
		scheme1[q].m4);
		else if(scheme[1]== '2')
		printf("%d,%s,%s,%s,%s\n", scheme2[q].roll, scheme2[q].phone ,scheme2[q].address, scheme2[q].city,scheme2[q].pin);*/
		q++;
	}
	fclose(fp);
	return q;
}