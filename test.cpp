#include <stdio.h>
#include <iostream>
using namespace std;
int stringLength(char * a)
{
    int i = 0;
    while (a[i++] != '\0');
    return --i;
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
int main()
{
    //printf("%d", stringLength("hello"));
    char  x[] = "Vizag";
    printf("\n%d\n", compareString(x,"Vizag"));
}
