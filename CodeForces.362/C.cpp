#include <iostream>
#include <map>
#include <utility>

using namespace std;

typedef unsigned long long ull;
map<ull,ull> costs;

ull discreteLog2(ull x)
{
	ull r = 0;

	while (x)
	{
		r++;
		x >>= 1;
	}

	return r-1;
}

ull largestCommonAncestor(ull a, ull b)
{
	ull da = discreteLog2(a);
	ull db = discreteLog2(b);

	if (da > db) a >>= (da - db);
	else if (db > da) b >>= (db - da);

	while (a != b) a >>= 1, b >>= 1;

	return a;
}

void addCosts(ull a, ull b, ull x)
{
	ull l = largestCommonAncestor(a, b);

	while (a != l)
	{
		costs[a] += x;
		a >>= 1;
	}

	while (b != l)
	{
		costs[b] += x;
		b >>= 1;
	}
}

ull getCost(ull a, ull b)
{
	ull c = 0;
	
	ull l = largestCommonAncestor(a, b);

	while (a != l)
	{
		auto it = costs.find(a);
		if (it != costs.end()) c += it->second;
		a >>= 1;
	}

	while (b != l)
	{
		auto it = costs.find(b);
		if (it != costs.end()) c += it->second;
		b >>= 1;
	}

	return c;
}

int main()
{
	long q;
	cin >> q;

	while (q--)
	{
		ull k, a, b;
		cin >> k >> a >> b;

		if (k == 1)
		{
			ull x;
			cin >> x;

			addCosts(a, b, x);
		}
		else
		{
			cout << getCost(a, b) << endl;
		}
	}
}
