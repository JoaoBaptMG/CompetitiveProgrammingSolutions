#include <stdio.h>

#define LLD "%I64d"

int main()
{
	long n, k;
	scanf("%ld%ld", &n, &k);

	int is_cap[n];
	long long beauty[n];
	long long all_sum = 0;
	long long result = 0;

	for (long i = 0; i < n; i++)
	{
		is_cap[i] = 0;
		scanf(LLD, beauty+i);
		all_sum += beauty[i];
	}

	long long temp_sum = all_sum;

	while (k--)
	{
		long id;
		scanf("%ld", &id);
		is_cap[id-1] = 1;
		temp_sum -= beauty[id-1];
		result += temp_sum * beauty[id-1];
	}

	for (long i = 0; i < n; i++)
	{
		long i1 = i;
		long i2 = (i+1)%n;

		if (is_cap[i1] || is_cap[i2]) continue;
		result += beauty[i1] * beauty[i2];
	}

	printf(LLD "\n", result);

	return 0;
}
