#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	int tst = 0;

	while (t--)
	{
		int n;
		scanf("%d", &n);

		vector<int> numbers;
		numbers.resize(n);
		for (auto& v : numbers) scanf("%d", &v);
		sort(numbers.begin(), numbers.end());

		deque<int> values{numbers.begin(), numbers.end()};

		int numTrips = 0;
		while (!values.empty())
		{
			int w = values.back();
			values.pop_back();

			int ns = (49+w)/w; // ceil of 50/w
			
			if (values.size() < ns-1) values.clear();
			else
			{
				while (--ns) if (!values.empty()) values.pop_front();
				numTrips++;
			}
		}

		printf("Case #%d: %d\n", ++tst, numTrips);
	}
}
