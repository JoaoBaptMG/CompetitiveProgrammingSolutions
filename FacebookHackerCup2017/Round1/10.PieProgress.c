#include <stdio.h>
#include <stdlib.h>

int longcmp(const void *p1, const void *p2)
{
	long l1 = *(const long*)p1;
	long l2 = *(const long*)p2;

	return l1 < l2 ? -1 : l1 > l2 ? 1 : 0;
}

#define LONG_LONG_MAX 0x7FFFFFFFFFFFFFFFLL
#define MIN(x,y) ((x)<(y)?(x):(y))

long costs[300][301];
long long dArray[300][301];

int main()
{
	int t;
	scanf("%d", &t);

	int tst = 0;

	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		for (int i = 0; i < n; i++)
		{
			costs[i][0] = 0;

			for (int j = 1; j <= m; j++)
				scanf("%ld", &costs[i][j]);

			qsort(&costs[i][1], m, sizeof(long), longcmp);

			for (int j = 1; j <= m; j++)
				costs[i][j] += costs[i][j-1];
			for (int j = 1; j <= m; j++)
				costs[i][j] += j*j;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j <= n; j++)
				dArray[i][j] = 1000000000000000LL;

		for (int j = 0; j <= m && j <= n; j++)
			dArray[0][j] = costs[0][j];

		for (int i = 1; i < n; i++)
			for (int j = 0; j <= n; j++)
				for (int k = 0; k <= j && k <= m; k++)
					dArray[i][j] = MIN(dArray[i][j], dArray[i-1][j-k] + costs[i][k]);
		
		printf("Case #%d: %lld\n", ++tst, dArray[n-1][n]);
	}
}
