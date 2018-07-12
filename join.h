#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

// command may be like = join s1 s2
// A new file will be created by joining schema s1 and s2 
/*int getlines(char * scheme)
{
	if (scheme[1] == '1')
		return s1importedlines - 1;
	else if (scheme[1] == '2')
		return s2importedlines - 1;
}*/
int join(char *cmd)
{
	int i = 0, j = 0;
	while (cmd[i++] != ' ');

	char * schm1 = (char *)malloc(sizeof(char) * 4);
	char * schm2 = (char *)malloc(sizeof(char) * 4);
	while (cmd[i] != ' ')
	schm1[j++] = cmd[i++];
	schm1[j] = '\0';

	i++;
	j = 0;
	while (cmd[i] != '\0'  && cmd[i] != ' ')
		schm2[j++] = cmd[i++];
	schm2[j] = '\0';

	int lines = getlines(schm1) > getlines(schm1) ? getlines(schm1) : getlines(schm2);

	printf("lines = %d, schm1 = %s, schm2 = %s \n", lines, schm1, schm2);

	int q = 0;
	FILE * fp;
	fp = fopen("joined.csv", "w");
	if (schm1[1] == '1' && schm2[1] == '2')
	{
		while (q < lines)
		{
			fprintf(fp, "%d,%s,%d,%d,%d,%d,%d,%s,%s,%s,%s\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4,
				scheme2[q].roll, scheme2[q].phone, scheme2[q].address, scheme2[q].city, scheme2[q].pin);
			q++;
		}
	}
	else if (schm1[1] == '2' && schm1[1] == '1')
	{
		while (q < lines)
		{
			fprintf(fp, "%d,%s,%s,%s,%s,%d,%s,%d,%d,%d,%d\n", scheme2[q].roll, scheme2[q].phone, scheme2[q].address, scheme2[q].city, scheme2[q].pin,
				scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
			q++;
		}
	}
	else if (schm1[1] == '1' && schm2[1] == '1')
	{
		while (q < lines)
		{
			fprintf(fp, "%d,%s,%d,%d,%d,%d,%d,%s,%d,%d,%d,%d\n", scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4,
				scheme1[q].roll, scheme1[q].name, scheme1[q].m1, scheme1[q].m2, scheme1[q].m3, scheme1[q].m4);
			q++;
		}
	}
	else if (schm1[1] == '2' && schm2[1] == '2')
	{
		while (q < lines)
		{
			fprintf(fp, "%d,%s,%s,%s,%s,%d,%s,%s,%s,%s\n", scheme2[q].roll, scheme2[q].phone, scheme2[q].address, scheme2[q].city, scheme2[q].pin,
				scheme2[q].roll, scheme2[q].phone, scheme2[q].address, scheme2[q].city, scheme2[q].pin);
			q++;
		}
	}

	fclose(fp);
	free(schm1);
	free(schm2);

	printf("\nJoined, check out in the file 'joined.csv'\n");
	return 0;
}