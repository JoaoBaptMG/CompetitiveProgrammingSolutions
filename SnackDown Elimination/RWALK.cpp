#include <iostream>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		long n;
		cin >> n;

		multiset<long> hor_vals;
		multiset<long> vert_vals;

		multiset<long> *pusher = &hor_vals;
		multiset<long> *other = &vert_vals;
		
		for (long i = 0; i <= n; i++)
		{
			long v;
			char d[3];
			if (i) cin >> d >> v;
			else cin >> v;

			pusher->insert(v);
			swap(pusher, other);
		}

		long r = 0;
		long v = 1;

		for (long p : hor_vals)
		{
			r += v*p;
			v = -v;
		}

		long s = 0;
		v = 1;

		for (long p : vert_vals)
		{
			s += v*p;
			v = -v;
		}

		cout << (abs(r) + abs(s)) << endl;
	}
}
