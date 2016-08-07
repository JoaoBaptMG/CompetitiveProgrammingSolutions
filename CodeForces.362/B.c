#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[200], *p;
	long b, i;

	scanf("%c.%s", str, str+1);

	b = atol(strchr(str, 'e')+1);

	if (str[0] == '0' && str[1] == '0')
	{
		puts("0");
		return 0;
	}
	
	for (i = b, p = str; *p != 'e'; i--, p++)
	{
		if (i == -1) putchar('.');
		putchar(*p);
	}

	while (i-- >= 0) putchar('0');

	putchar('\n');

	return 0;
}
