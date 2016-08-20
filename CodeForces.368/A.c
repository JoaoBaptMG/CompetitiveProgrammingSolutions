#include <stdio.h>

int main()
{
	int n, m;
	int is = 0;
	scanf("%d%d", &n, &m);

	n *= m;

	while (n--)
	{
		char val[2];
		scanf("%s", val);

		if (val[0] == 'C' || val[0] == 'M' || val[0] == 'Y')
		{ is = 1; break; }
	}

	puts(is ? "#Color" : "#Black&White");
}
