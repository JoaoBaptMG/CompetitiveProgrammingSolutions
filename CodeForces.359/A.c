#include <stdio.h>

int main()
{
	long long sum;
	long dist = 0, n;

	scanf("%ld%I64d", &n, &sum);

	while (n--)
	{
		char val[3];
		long long cur;

		scanf("%s %I64d", val, &cur);

		if (val[0] == '+')
			sum += cur;
		else
			if (sum >= cur) sum -= cur;
			else dist++;
	}

	printf("%I64d %ld\n", sum, dist);
}
