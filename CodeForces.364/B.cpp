#include <iostream>
#include <set>

using namespace std;
typedef unsigned long long ull;

int main()
{
	ull n, m;

	set<ull> rows, cols;
	cin >> n >> m;

	bool nf = false;
	while (m--)
	{
		ull r, c;
		cin >> r >> c;

		rows.insert(r);
		cols.insert(c);

		if (nf) cout << ' ';
		cout << ((n - rows.size())*(n - cols.size()));
		nf = true;
	}

	cout << endl;
}
