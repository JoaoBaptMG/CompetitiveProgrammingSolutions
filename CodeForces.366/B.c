#include <stdio.h>

#define LLD "%I64d"

int main()
{
	long n;
	scanf("%ld", &n);

	long long sum = 0;

	for (long long i = 0; i < n; i++)
	{
		long long v;
		scanf(LLD, &v);
		sum += v;

		printf(LLD "\n", 1 + (sum - i) % 2);
	}

	return 0;
}
