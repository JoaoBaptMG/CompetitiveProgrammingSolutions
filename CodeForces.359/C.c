#include <stdio.h>

long digitsIn7(long a)
{
	long r = 0;

	do
	{
		r++;
		a /= 7;
	} while (a);

	return r;
}

int hasDistinct(long v, long r)
{		
	int mask = 0;

	while (r--)
	{
		long d = v % 7;
		if (mask & (1<<d)) return 0;
		mask |= 1 << d;
		v /= 7;
	}

	return 1;
}

int main()
{
	long a, b;
	scanf("%ld%ld", &a, &b);

	long da = digitsIn7(a-1);
	long db = digitsIn7(b-1);

	if (da + db > 7)
		puts("0");
	else
	{
		long pow = 1;
		long sum = 0;
		for (long i = 0; i < da; i++)
			pow *= 7;
		
		long i, j;

		for (i = 0; i < a; i++)
			for (j = 0; j < b; j++)
				if (hasDistinct(i + j*pow, da+db)) sum++;

		printf("%ld\n", sum);
	}
}
