#include <stdio.h>

#define HUG 100000000L
#define MIN(x,y) ((x)<(y)?(x):(y))

long minDists[100][100];

int orders[5000][2];
long long dpArr[5000][2];

int main()
{
	int t;
	scanf("%d", &t);

	int tst = 0;

	while (t--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				minDists[i][j] = i == j ? 0 : HUG;

		// Read distances
		while (m--)
		{
			int a, b;
			long g;
			scanf("%d%d%ld", &a, &b, &g);
			a--, b--;

			minDists[a][b] = MIN(minDists[a][b], g);
			minDists[b][a] = MIN(minDists[b][a], g);
		}

		// Floyd-Warshall
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					minDists[i][j] = MIN(minDists[i][j], minDists[i][k] + minDists[k][j]);

		// Read orders
		for (int i = 0; i < k; i++)
		{
			scanf("%d%d", &orders[i][0], &orders[i][1]);
			orders[i][0]--;
			orders[i][1]--;
		}

		dpArr[0][0] = minDists[0][orders[0][0]] + minDists[orders[0][0]][orders[0][1]];
		dpArr[0][1] = minDists[0][orders[0][0]] + minDists[orders[0][0]][orders[1][0]];

		for (int i = 1; i < k-1; i++)
		{
			dpArr[i][0] = minDists[orders[i-1][1]][orders[i][0]] +
				MIN(dpArr[i-1][0] + minDists[orders[i][0]][orders[i][1]],
					dpArr[i-1][1] + minDists[orders[i-1][1]][orders[i][1]]);
			dpArr[i][1] = minDists[orders[i-1][1]][orders[i][0]] +
				MIN(dpArr[i-1][0] + minDists[orders[i][0]][orders[i+1][0]],
					dpArr[i-1][1] + minDists[orders[i-1][1]][orders[i+1][0]]);
		}

		long long answer = minDists[orders[k-2][1]][orders[k-1][0]] +
			MIN(dpArr[k-2][0] + minDists[orders[k-1][0]][orders[k-1][1]],
				dpArr[k-2][1] + minDists[orders[k-2][1]][orders[k-1][1]]);
		
		printf("Case #%d: %lld\n", ++tst, answer >= HUG ? -1 : answer);
	}
}
