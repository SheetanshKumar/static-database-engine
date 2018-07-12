#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;



int flush(char * cmd)
{
	int i = 0;
	while (cmd[i++] != ' ');
	char * filename = (char *)malloc(sizeof(char) * 50);//flush filename

	int j = 0, q = 0;
	while (cmd[i] != ' ')
	{
		filename[j++] = cmd[i++];
	}
	filename[j] = '\0';
	//printf("%s", filename);
	i++;
	char scheme[10];
	j = 0;
	while (cmd[i] != '\0') //flush filename scheme
		scheme[j++] = cmd[i++];
	scheme[j] = '\0';
	FILE *fptr = fopen(filename, "w");
	if (scheme[1] == '1')
		while (q < 200)
		{
			fprintf(fptr, "%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
			q++;
		}
	else if (scheme[1] == '2'){
		while (q < 200)
		{
			fprintf(fptr, "%d,%s,%s,%s,%s\n", scheme2[q].roll, scheme2[q].phone, scheme2[q].address, scheme2[q].city, scheme2[q].pin);
			q++;
		}
	}
	if (scheme[1] == '1')
		free(scheme1);
	else
		free(scheme2);
	fclose(fptr);
	printf("Flushed at %s\n", filename);
	return 0;
}