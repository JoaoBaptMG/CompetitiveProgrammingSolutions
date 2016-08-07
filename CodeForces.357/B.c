#include <stdio.h>

int has_solution(long long k)
{
	if ((1197550LL * k) % 1234567LL == 0) return 1;
	if ((1197LL * k) % 1234LL == 0) return 1;
	return 1197550LL * k / 1234567LL != 1197LL * k / 1234LL;
}

#define LLD "%I64d"

int main()
{
	long long n;
	int is = 0;

	scanf(LLD, &n);

	while (n >= 0)
	{
		if (has_solution(n))
		{
			is = 1;
			break;
		}

		n -= 123456;
	}

	puts(is ? "YES" : "NO");
}
