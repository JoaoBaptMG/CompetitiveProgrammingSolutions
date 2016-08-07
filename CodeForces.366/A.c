#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf(i % 2 == 0 ? "I hate " : "I love ");
		printf(i == n-1 ? "it" : "that ");
	}

	return 0;
}
