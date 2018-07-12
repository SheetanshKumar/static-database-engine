#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int printMain(char * att, int q, char * scheme)
{
	if (scheme[1] == '1')
	{
		if (att[0] == '*')
			printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
		else
		{
			if (compareString(att, "roll") == 1)
				printf("%d\n", scheme1[q].roll);
			else if (compareString(att, "name") == 1)
				printf("%s\n", scheme1[q].name);
			else if (compareString(att, "m1") == 1)
				printf("%d\n", scheme1[q].m1);
			else if (compareString(att, "m2") == 1)
				printf("%d\n", scheme1[q].m2);
			else if (compareString(att, "m3") == 1)
				printf("%d\n", scheme1[q].m3);
			else if (compareString(att, "m4") == 1)
				printf("%d\n", scheme1[q].m4);
			else
			{
				printf("\nAttribute not found in s1\nPlease try Again \n");
				return -1;
			}
		}
	}
	else if (scheme[1] == '2')
	{
		//printf("\nhello working s2 printing 1 \n");
		if (att[0] == '*')
			printf("%d,%s,%s,%s,%s\n", scheme2[q].roll, scheme2[q].phone, scheme2[q].address, scheme2[q].city,  scheme2[q].pin);
		else
		{
			//printf("\nhello working s2 printing 2 \n");
			if (compareString(att, "roll") == 1)
				printf("%d\n", scheme2[q].roll);
			else if (compareString(att, "phone") == 1)
				printf("%s\n", scheme2[q].phone);
			else if (compareString(att, "address") == 1)
				printf("%sd\n", scheme2[q].address);
			else if (compareString(att, "city") == 1)
				printf("%s\n", scheme2[q].city);
			else if (compareString(att, "pin") == 1)
				printf("%s\n", scheme2[q].pin);
			else
			{
				printf("\nAttribute not found in s1\nPlease try Again \n");
				return -1;
			}
		}
	}
}
int checkOperation(char *op)
{
	if (op[0] == 'g' && op[1] == 't')
		return 1;
	if (op[0] == 'l' && op[1] == 't')
		return 2;
	if (op[0] == 'e' && op[1] == 'q')
		return 3;
	if (op[0] == 'g' && op[1] == 'e')
		return 4;
	if (op[0] == 'l' && op[1] == 'e')
		return 5;
	else 
		return 0;
}

int getlines(char * scheme)
{
	if (scheme[1] == '1')
		return s1importedlines - 1;
	else if (scheme[1] == '2')
		return s2importedlines - 1;
}
int printQuery(char *att1, char *att2, char *op,char * scheme, char * mainAtt)
{
	//printf("hello working\n");
	int q = 0;
	int lines = getlines(scheme);
	
	int operation = checkOperation(op);
	
	//printf("%s\n", mainAtt);
	//printf("%d , %d, %d, %s, %s %s", checkInt(att2),compareString(att1,"roll"), operation, att1, att2, scheme);
	if (scheme[1] == '1')
	{
		if (checkInt(att2) != 0)
		{
			//printf("\nHello checkint\n");
			if (compareString(att1, "roll") == 1)
			{
				//printf("\nHello compare\n");
				while (q < lines)
				{
					switch (operation)
					{
					case 1: if (scheme1[q].roll > checkInt(att2))
						printMain(mainAtt, q,scheme);
						//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
					case 2: if (scheme1[q].roll < checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 3: if (scheme1[q].roll == checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 4: if (scheme1[q].roll >= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 5: if (scheme1[q].roll <= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 0 : printf("\nOperation not available\n");
							return 0;
					}
					q++;
				}
			}
			else if (compareString(att1, "m1") == 1)
			{
				//printf("\nHello compare\n");
				while (q < lines)
				{
					switch (operation)
					{
					case 1: if (scheme1[q].m1 > checkInt(att2))
						printMain(mainAtt, q, scheme);
						//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
					case 2: if (scheme1[q].m1 < checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 3: if (scheme1[q].m1 == checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 4: if (scheme1[q].m1 >= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 5: if (scheme1[q].m1 <= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 0: printf("\nOperation not available\n");
						return 0;
					}
					q++;
				}
			}

			else if (compareString(att1, "m2") == 1)
			{
				//printf("\nHello compare\n");
				while (q < lines)
				{
					switch (operation)
					{
					case 1: if (scheme1[q].m2 > checkInt(att2))
						printMain(mainAtt, q, scheme);
						//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
					case 2: if (scheme1[q].m2 < checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 3: if (scheme1[q].m2 == checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 4: if (scheme1[q].m2 >= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 5: if (scheme1[q].m2 <= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 0: printf("\nOperation not available\n");
						return 0;
					}
					q++;
				}
			}

			else if (compareString(att1, "m3") == 1)
			{
				//printf("\nHello compare\n");
				while (q < lines)
				{
					switch (operation)
					{
					case 1: if (scheme1[q].m3 > checkInt(att2))
						printMain(mainAtt, q, scheme);
						//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
					case 2: if (scheme1[q].m3 < checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 3: if (scheme1[q].m3 == checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 4: if (scheme1[q].m3 >= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 5: if (scheme1[q].m3 <= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 0: printf("\nOperation not available\n");
						return 0;
					}
					q++;
				}
			}

			else if (compareString(att1, "m4") == 1)
			{
				//printf("\nHello compare\n");
				while (q < lines)
				{
					switch (operation)
					{
					case 1: if (scheme1[q].m4 > checkInt(att2))
						printMain(mainAtt, q, scheme);
						//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
					case 2: if (scheme1[q].m4 < checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 3: if (scheme1[q].m4 == checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 4: if (scheme1[q].m4 >= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 5: if (scheme1[q].m4 <= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 0: printf("\nOperation not available\n");
						return 0;
					}
					q++;
				}
			}
			else
				printf("\nAttribute not found s1, Please try again\n");

		}

		else{
			if (compareString(att1, "name") == 1)
			{
				printf("\nHello comparename in s1\n");
				while (q < lines)
				{
					switch (operation)
					{
					case 3: if (compareString(scheme1[q].name, att2) == 1)
						printMain(mainAtt, q, scheme);
						//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
					case 0: printf("\nOperation not available for strings \n");
						return 0;
					}
					q++;
				}
			}
			else
				printf("\nAttribute not found in s1, Please try again\n");
		}
	}
else if (scheme[1] == '2')
	{
		if (checkInt(att2) != 0)
		{
			if (compareString(att1, "roll") == 1)
			{
				//printf("\nHello compare in s2\n");
				while (q < lines)
				{
					switch (operation)
					{
					case 1: if (scheme2[q].roll > checkInt(att2))
						printMain(mainAtt, q, scheme);
						//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
					case 2: if (scheme2[q].roll < checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 3: if (scheme2[q].roll == checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 4: if (scheme2[q].roll >= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 5: if (scheme2[q].roll <= checkInt(att2))
						printMain(mainAtt, q, scheme);
						break;
					case 0: printf("\nOperation not available\n");
						return 0;
					}
					q++;
				}
			}
			else
				printf("\nAttribute not found in s2, Please try again\n");
		}
	
	else if (compareString(att1, "pin") == 1)
	{
		//printf("\nHello compare\n");
		while (q < lines)
		{
			switch (operation)
			{
				case 3: if (compareString(scheme2[q].pin, att2) == 1)
								printMain(mainAtt, q, scheme);
								//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
				case 0: printf("Operation not available for strings \n");
						return 0;
			}
			q++;
		}
	}
	else if (compareString(att1, "city") == 1)
	{
		//printf("\nHello compare city\n,lines = %d, operation = %d, q = %d mainatt = %s, scheme = %s", lines,operation,q,mainAtt,scheme);
		
		while (q < lines)
		{
			//printf("\ncompare  - %d , att2 = %s, scheme2[q].city = %s,Vizag.cityle = %d,Vizag len = %d\n ", compareString(scheme2[q].city, att2), att2, scheme2[q].city, stringLength(scheme2[q].city), stringLength("Vizag"));
			switch (operation)
			{
			case 3: if (compareString(scheme2[q].city, att2) == 1)
						printMain(mainAtt, q, scheme);
				//printf("%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
						break;
			case 0: printf("Operation not available for strings \n");
				return 0;
			}
			q++;
		}
	}
	else 
	printf("\nAttribute not found in s2, Please try again\n");

 }
	return 0;
}
int getAttribute(char * attr, int scheme)
{
	if (scheme == 1)
	{
		int i = 0;
		if (compareString(attr, "roll"))
			return 1;
		if (compareString(attr, "name"))
			return 2;
		if (compareString(attr, "m1"))
			return 3;
		if (compareString(attr, "m2"))
			return 4;
		if (compareString(attr, "m3"))
			return 5;
		if (compareString(attr, "m4"))
			return 6;
	}
	
}
int select(char * cmd)
{
	int i = 0, j = 0;
	char * att = (char *)malloc(sizeof(char) * 10);
	while (cmd[i++] != ' '); // for select
	int flag = 0, where = 0;

	while (cmd[i] != '\0' && cmd[i] != ' ')
	{
		att[j++] = cmd[i++]; // for attribute 
	}
	att[j] = '\0';
	
	j = 0; i++;
	while (cmd[i] != '\0' && cmd[i++] != ' ');// for from ...............................syntax : select * from filename where attribute1 gt attribute2
	
	j = 0;
	char * scheme = (char *)malloc(sizeof(char) * 2); // for getting scheme
	while (cmd[i] != ' ' && cmd[i] != '\0') //
		scheme[j++] = cmd[i++];
	scheme[j] = '\0';

	if (cmd[i] == ' ')
		i++;

	while (cmd[i] != '\0' && cmd[i++] != ' ')
	where = 1;

	char * att1 = (char *)malloc(sizeof(char) * 10);
	char * att2 = (char *)malloc(sizeof(char) * 10);
	char * op = (char *)malloc(sizeof(char) * 3);
	
	//printf("att  =%s, where = %d, where  =  \n", att, where);
									//When where clause is there
	if (where == 1)
	{
		j = 0;
		while (cmd[i] != '\0' && cmd[i] != ' ')
			att1[j++] = cmd[i++];
		att1[j] = '\0';
		j = 0; i++;
		while (cmd[i] != '\0' && cmd[i] != ' ')
			op[j++] = cmd[i++];
		i++;
		op[j] = '\0';
		j = 0;
		while (cmd[i] != '\0' && cmd[i] != ' ')
			att2[j++] = cmd[i++];
		att2[j] = '\0';
	}

	//printf("att1 = %s, att2 = %s , where = %d, flag = %d\, op = %s \n", att1, att2,where,flag, op );
	int q = 0,temp = 0;
	int lines = getlines(scheme);

	//printf("flag = %d, where = %d, filename == %s\n",flag,where,filename);
	if (where == 0)
	{
		while (q < lines - 1 && temp != -1)
		{
			temp = printMain(att, q, scheme);
			q++;
		}
	}
	else if (where == 1)
	{                                       //gt, lt,eq, ge, le - operation
		//printf("hello working\n");
		int res = printQuery(att1,att2, op, scheme,att);
	}
	
	return 1;
}