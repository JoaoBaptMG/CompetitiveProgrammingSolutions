#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LLD "%I64d"

typedef long long ll;
typedef long double ld;

int always_true(ll m, ll n) { return 1; }

int check_for_odd(ll m, ll n)
{
	return (m+n) % 2 == 0;
}

int llcomp(const void* p1, const void* p2)
{
	ll v1 = *(ll*)p1;
	ll v2 = *(ll*)p2;

	return v1 < v2 ? -1 : v1 > v2 ? 1 : 0;
}

ll squares[100000];

int factor_and_pick(ll c, ll *m, ll *n, int (*pred)(ll,ll))
{
	for (ll i = 1; i*i < c; i++)
	{
		if (c % i == 0)
		{
			ll mk = i, nk = c/i;
			if (pred(mk, nk))
			{
				*m = mk;
				*n = nk;
				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	ll c;
	int found = 0;

	scanf(LLD, &c);

	ll a, b;

	if (c % 2 == 0)
	{
		ll m, n;
		factor_and_pick(c/2, &n, &m, always_true);

		a = m*m - n*n;
		b = m*m + n*n;

		found = 1;
	}
	else
	{
		ll l, k;
		if (factor_and_pick(c, &k, &l, check_for_odd))
		{
			ll m = (l+k)/2;
			ll n = (l-k)/2;

			a = 2*m*n;
			b = m*m + n*n;

			found = 1;
		}
		else
		{
			ll i = 1;
			for (; i*i <= c; i++) squares[i] = i*i;

			for (ll j = 1; j*j <= c; j++)
			{
				ll t = c - j*j;
				ll* v = bsearch(&t, squares+1, i-1, sizeof(ll), llcomp);
				if (v != 0)
				{
					ll n = t, m = *v;
					if (n > m) { n ^= m; m ^= n; n ^= m; }

					a = m*m - n*n;
					b = 2*m*n;

					found = 1;
				}
			}
		}
	}

	if (found) printf(LLD " " LLD "\n", a, b);
	else puts("-1");
}
