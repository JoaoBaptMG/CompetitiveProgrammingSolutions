#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

double probability(int h, int x, int y, int z)
{
	auto size = x*y - x + 1;
	
	vector<double> chancesPrev(size, 0);
	vector<double> chances(size, 0);

	chances[0] = 1;

	for (int i = 0; i < x; i++)
	{
		chancesPrev = move(chances);
		chances.assign(size, 0);
		
		for (int j = 0; j < y; j++)
			for (int k = 0; k <= size - y; k++)
				chances[k+j] += chancesPrev[k];
	}

	double cur = 0, total = 0;
	for (int i = 0; i < size; i++)
	{
		total += chances[i];
		if (i+x+z >= h) cur += chances[i];
	}

	return (double)cur / total;
}

int main()
{
	int t;
	scanf("%d", &t);

	int tst = 0;

	while (t--)
	{
		int h, s;
		char buffer[24];

		scanf("%d%d", &h, &s);
		double curmax = 0;

		while (s--)
		{
			scanf("%s", buffer);

			char* dSpec = strchr(buffer, 'd');
			char* pSpec = strpbrk(buffer, "+-");

			int x = atoi(buffer);
			int y = atoi(dSpec+1);
			int z = 0;
			if (pSpec) z = atoi(pSpec);

			double prob = probability(h, x, y, z);
			if (curmax < prob) curmax = prob;
		}

		printf("Case #%d: %.6f\n", ++tst, curmax);
	}
}
