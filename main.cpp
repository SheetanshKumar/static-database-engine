/*
This is a static Database engine which works on 2 schema i.e s1 and s2.\n
For schema information do check the files included - 'studentmarkslist.csv' works in schema1 and 'studentinfolist.csv' works in schema2\n

Commands that work with this engine :

-import statement
$import filename schemaname   // for importing the files into memory

-join statement
$join s1 and s2 // for joining 2 schema after importing

- select statement
$select * from s1 // printing all from 
$select * from s1 where roll gt 100 // where clause is included and operations (gt,lt,ge,le,eq) can be performed.
$select name from s1  // will print all the names from the s1
$select name roll s1 where roll gt 100 // will print all the roll greater than 100;

- flush statement
$flush filename schemaname // will save schema in the given filename and flush the memory. 
*/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define use_CRT_SECURE_NO_WARNINGS

//Files to be included :
#include "import.h"
#include "Flush.h"
#include "select.h"
#include "join.h"

typedef struct file1
{
	int roll;
	char name[20];
	int m1, m2, m3, m4;
};
typedef struct file2
{
	int  roll;
	char phone[10];
	char address[30];
	char city[20];
	char pin[6];
};


void find_avg(char * name)
{
	//printf("%s", name);
	FILE *fp;
	FILE *fptr = fopen("avg.txt", "w");
	fp = fopen(name, "r");
	const size_t line_size = 300;
	char* k = (char *)malloc(line_size);
	file1 * file_1 = (file1 *)malloc(sizeof(file1) * 1000);
	
	char names[20];
	fgets(k, line_size, fp);
	while (!feof(fp))
	{
		fgets(k, line_size, fp);
		// fscanf(fp,"%[^\n]", k);
		// printf("%s\n",k);
		int len = stringLength(k);
		int  i = 0, j = 0, countComma = 0, q = 0;
		char * str = (char *)malloc(sizeof(char) * 300);
		while (k[i] != '\n')
		{
			if (k[i] != ',')
				str[j++] = k[i];
			if (k[i] == ',')
			{
				countComma++;
				str[j] = '\0';
				j = 0;
				if (countComma == 1)
					file_1[q].roll = checkInt(str);
				if (countComma == 2)
					strcpy(file_1[q].name, str);
				if (countComma == 3)
					file_1[q].m1 = checkInt(str);
				if (countComma == 4)
					file_1[q].m2 = checkInt(str);
				if (countComma == 5)
					file_1[q].m3 = checkInt(str);
				else
					file_1[q].m4 = checkInt(str);

			}

			i++;
		}

		int avg = (file_1[q].m1 + file_1[q].m2 + file_1[q].m3 + file_1[q].m4) / 4;
		float grade;
		if (avg >= 90 && avg <= 100)
			grade = 4.0;
		else if (avg >= 85 && avg <= 89)
			grade = 3.76;
		else if (avg >= 80 && avg <= 84)
			grade = 3.5;
		else if (avg >= 75 && avg <= 79)
			grade = 3.33;
		else if (avg >= 70 && avg <= 74)
			grade = 3.0;
		else if (avg >= 65 && avg <= 69)
			grade = 2.76;
		else if (avg >= 60 && avg <= 64)
			grade = 2.5;
		else if (avg < 60)
			grade = 2.0;
		//printf("%s,avg=%d,grade=%.2f\n", file_1[q].name,avg,grade);


		printf("%d,%s,%d,%d,%d,%d,%d,%.2f\n", file_1[q].roll, file_1[q].name, file_1[q].m1, file_1[q].m2, file_1[q].m3,
			file_1[q].m4, avg, grade);

		fprintf(fptr, "%d,%s,%d,%d,%d,%d,%d,%.2f\n", file_1[q].roll, file_1[q].name, file_1[q].m1, file_1[q].m2, file_1[q].m3,
			file_1[q].m4, avg, grade);

		q++;
	}
	fclose(fp);
	fclose(fptr);
}
/*
void join_files(char * filename1, char * filename2)
{

	FILE * fp1;
	FILE * fp2;
	FILE * fp3;
	fp1 = fopen(filename1, "r");
	fp2 = fopen(filename2, "r");
	fp3 = fopen("JOIN.txt", "w");

	file1 * file_1 = (file1 *)malloc(sizeof(file1) * 201);
	file2 * file_2 = (file2 *)malloc(sizeof(file2) * 201);

	/*while(!feof(fp1) && !feof(fp2))
	{
	printf("working");
	char c1,c2;
	while(c1 != '\n')
	{
	c1 = fgetc(fp1);
	fputc(c1,fp3);
	}
	fputc(',',fp3);
	while(c2 != ',' && c2 != '\n')
	{
	c2= fgetc(fp2);
	}
	while(c2 != '\n')
	{
	fputc(c2,fp3);
	c2 = fgetc(fp2);
	}
	fputc('\n',fp3);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}*/


int main()
{
    int importlines = 0,importCount = 0;
	printf("*******************************************************************************\n");
	printf("This is a static Database engine which works on 2 schema i.e s1 and s2.\nFor schema information do check the files included -\n 'studentmarkslist.csv' works in schema1 and 'studentinfolist.csv' works in schema2\nDo check the comments or README FILE for commands.\n");
	printf("\n*******************************************************************************\n\n");
	while (1)
	{
		printf("Enter your query : \n$");
		char * command = (char *)malloc(sizeof(char) * 100);
		scanf("%[^\n]", command);
        //scanf("%s", command);
        fflush(stdin);
        if(stringLength(command) < 4)
        {
            printf("\nCommand not found\n");
            continue;
        }
		char str[20];
		int i = 0;
		while (command[i] != '\0' && command[i] != '\n' && command[i] != ' ')
		{
			str[i] = command[i++];
		}
		str[i] = '\0';
		i = 0;

		if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't')
		{
		    printf("exiting...");
			break;
		}
		else if (str[0] == 'j' && str[1] == 'o' && str[2] == 'i' && str[3] == 'n')
		{
			if (stringLength(command) < 5)
			{
				printf("Please enter valid join command\n");
				continue;
			}
			join(command);
		}
		else if (str[0] == 'i' && str[1] == 'm' && str[2] == 'p' && str[3] == 'o' && str[4] == 'r' && str[5] == 't')
		{
			if (stringLength(command) < 7)
			{
				printf("Please enter valid import command\n");
				continue;
			}
			importlines += import(command);
			if(importlines)
                printf("\nLoaded and ready to be fired.\n");
            else
                printf("\nProblem in loading.\n");
			importCount++;
			printf("total lines imported : %d\n", importlines);
		}
		else if (str[0] == 'f' && str[1] == 'l' && str[2] == 'u' && str[3] == 's' && str[4] == 'h')
		{
		    if(importCount == 0)
            {
                printf("\nNothing to Flush\n");
                continue;
            }
			flush(command);
			importlines = 0;
			printf("Done\n");
		}
		else if(str[0] == 's' && str[1] == 'e' && str[2] == 'l' && str[3] == 'e' &&  str[4] == 'c' && str[5] == 't')
        {
			if (stringLength(command) < 15)
			{
				printf("Please enter valid select command \n");
					continue;
			}
            int res = select(command);
        }
		else
		{
			printf("\nCommand not found\n");
		}
		//find_avg("studentmarkslist.csv");

		//join_files("studentmarkslist.csv","studentinfolist.csv");*/
		free(command);
	}
	cin.get();
	return 0;
}
