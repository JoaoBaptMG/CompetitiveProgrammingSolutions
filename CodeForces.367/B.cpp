#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long n;
	cin >> n;

	long* shops = new long[n];

	for (long i = 0; i < n; i++)
		cin >> shops[i];

	sort(shops, shops+n);

	long q;
	cin >> q;

	while (q--)
	{
		long m;
		cin >> m;

		auto id = upper_bound(shops, shops+n, m);
		cout << (id - shops) << endl;
	}

	delete[] shops;
}
