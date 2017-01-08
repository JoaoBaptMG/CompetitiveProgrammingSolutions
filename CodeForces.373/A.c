#include <stdio.h>

int main()
{
	long n;
	scanf("%ld", &n);

	long a = -1, b = -1;

	while (n--)
	{
		a = b;
		scanf("%ld", &b);
	}

	if (a == -1) puts(b == 15 ? "DOWN" : b == 0 ? "UP" : "-1");
	else if (a == 14 && b == 15) puts("DOWN");
	else if (a == 1 && b == 0) puts ("UP");
	else puts (a > b ? "DOWN" : "UP");
}
