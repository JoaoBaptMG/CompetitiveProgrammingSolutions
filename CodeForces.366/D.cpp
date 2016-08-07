#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

long long x[5000], a[5000], b[5000], c[5000], d[5000];

long long dist(long i, long j)
{
	if (i == j) return 0;
	else if (j < i) return abs(x[i]-x[j]) + c[i] + b[j];
	else return abs(x[i]-x[j]) + d[i] + d[j];
}

int main()
{
	long n, s, e;
	cin >> n >> s >> e;

	for (long i = 0; i < n; i++) cin >> x[i];
	for (long i = 0; i < n; i++) cin >> a[i];
	for (long i = 0; i < n; i++) cin >> b[i];
	for (long i = 0; i < n; i++) cin >> c[i];
	for (long i = 0; i < n; i++) cin >> d[i];

	vector<long> seq;
	seq.reserve(n);
	seq.push_back(s);

	for (long i = 0; i < n; i++)
		if (i != s && i != e) seq.push_back(i);

	seq.push_back(e);

	bool run = true;

	while (run)
	{
		run = false;

		for (long i = 0; i < n-3; i++)
		{
			long long d1 = dist(seq[i], seq[i+1]) + dist(seq[i+1], seq[i+2]) + dist(seq[i+2], seq[i+3]);
			long long d2 = dist(seq[i], seq[i+2]) + dist(seq[i+2], seq[i+1]) + dist(seq[i+1], seq[i+3]);
			if (d1 < d2)
			{
				swap(seq[i+1], seq[i+2]);
				run = true;
			}
		}
	}

	long long d = 0;
	for (long i = 0; i < n-1; i++)
		d += dist(seq[i], seq[i+1]);

	cout << d << endl;
	return 0;
}
