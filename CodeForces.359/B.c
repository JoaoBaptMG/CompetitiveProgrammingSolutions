#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	long h[n];
	for (int i = 0; i < n; i++)
		scanf("%ld", h+i);

	int run = 1;
	while (run)
	{
		run = 0;

		for (int i = 0; i < n-1; i++)
		{
			if (h[i] > h[i+1])
			{
				printf("%d %d\n", i+1, i+2);

				h[i] ^= h[i+1];
				h[i+1] ^= h[i];
				h[i] ^= h[i+1];

				run = 1;
			}
		}
	}
}
