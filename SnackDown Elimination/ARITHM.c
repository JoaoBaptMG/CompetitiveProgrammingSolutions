#include <stdio.h>

#define LLD "%lld"

typedef long long ll;

int test(ll n, ll c)
{
	if (n % 2) return c % n == 0 && c > n * (n-1) / 2;
	else return c % (n/2) == 0 && (c+n-2)/(n-1) - c/n > 1;
}

int main()
{
	long t;
	scanf("%ld", &t);

	while (t--)
	{
		ll n, c;
		scanf(LLD LLD, &n, &c);

		puts(test(n, c) ? "Yes" : "No");
	}
}
