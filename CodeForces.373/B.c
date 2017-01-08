#include <stdio.h>

const char vals[] = "rb";

char c[100005];
int v[100005];
long dp[100002][2];

int main()
{
	long n;
	scanf("%ld%s", &n, c);

	for (long i = 0; i < n; i++)
		v[i] = c[i] == vals[i%2];

	long num[2] = { 0, 0 };
	long cons = 1;

	for (long i = 1; i < n; i++)
	{
		if (v[i] != v[i-1])
		{
			num[v[i-1]] += (cons+1)/2;
			cons = 1;
		}
		else cons++;
	}

	printf("%ld\n", num[0] < num[1] ? num[0] : num[1]);
}
