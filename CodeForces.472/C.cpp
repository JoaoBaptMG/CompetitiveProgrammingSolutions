#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
typedef unsigned long long ull;

int main()
{
	ull n, u;
	cin >> n >> u;
	
	vector<ull> e(n);
	for (ull& v : e) cin >> v;
	
	long double mu = -1;
	
	for (auto it = e.begin(); it != e.end(); ++it)
	{
		auto itk = upper_bound(it, e.end(), *it + u)-1;
		if (itk <= it+1) continue;
		long double curmu = (long double)(*itk - *(it+1))/(*itk - *it);
		if (mu < curmu) mu = curmu;
	}
	
	cout << setprecision(21) << mu << endl;
}
