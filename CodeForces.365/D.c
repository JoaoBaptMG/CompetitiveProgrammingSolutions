#include <stdio.h>
typedef unsigned long ul;

int main()
{
	long n;
	scanf("%ld", &n);

	ul all_ors[n+1];
	ul all_xors[n+1];

	all_ors[0] = all_xors[0] = 0;
	for (long i = 1; i <= n; i++)
	{
		ul v;
		scanf("%lu", &v);
		all_ors[i] = all_ors[i-1] | v;
		all_xors[i] = all_xors[i-1] ^ v;
	}

	long q;
	scanf("%ld", &q);

	while (q--)
	{
		long a, b;
		scanf("%ld%ld", &a, &b);

		printf("%lu\n", all_ors[b] ^ all_ors[a-1] ^ all_xors[b] ^ all_xors[a-1]);
	}
}
