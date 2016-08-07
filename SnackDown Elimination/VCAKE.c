#include <stdio.h>

typedef long long ll;

int divs(ll a, ll b)
{
	return b % a == 0;
}

int test(ll r, ll c, ll m, ll k, ll j)
{
	if (m + k + j != r*c) return 0;

	if (divs(r, m) && divs(r, k) && divs(r, j)) return 1;
	if (divs(c, m) && divs(c, k) && divs(c, j)) return 1;

	if (divs(r, m) && divs(c - m/r, k) && divs(c - m/r, j)) return 1;
	if (divs(r, k) && divs(c - k/r, m) && divs(c - k/r, j)) return 1;
	if (divs(r, j) && divs(c - j/r, m) && divs(c - j/r, k)) return 1;

	if (divs(c, m) && divs(r - m/c, k) && divs(r - m/c, j)) return 1;
	if (divs(c, k) && divs(r - k/c, m) && divs(r - k/c, j)) return 1;
	if (divs(c, j) && divs(r - j/c, m) && divs(r - j/c, k)) return 1;

	return 0;
}

int main()
{
	long t;

	scanf("%ld", &t);

	while (t--)
	{
		ll r, c, m, k, j;

		scanf("%lld%lld%lld%lld%lld", &r, &c, &m, &k, &j);
		puts(test(r, c, m, k, j) ? "Yes" : "No");
	}
}
