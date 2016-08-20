#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))

constexpr size_t MAX = 1000000000000000000;

int main()
{
	size_t n;
	cin >> n;

	vector<size_t> cs;
	cs.resize(n);

	for (auto &c : cs)
		cin >> c;

	vector<string> strs;
	strs.resize(n);

	vector<string> revs;
	revs.reserve(n);

	for (auto &str : strs)
	{
		cin >> str;

		string rev{str.crbegin(), str.crend()};
		revs.push_back(rev);
	}

	vector<size_t> astr, arev;
	astr.resize(n);
	arev.resize(n);

	astr[0] = 0;
	arev[0] = cs[0];

	for (size_t i = 1; i < n; i++)
	{
		astr[i] = MAX;
		if (revs[i-1] <= strs[i]) astr[i] = MIN(astr[i], arev[i-1]);
		if (strs[i-1] <= strs[i]) astr[i] = MIN(astr[i], astr[i-1]);
		
		arev[i] = MAX;
		if (revs[i-1] <= revs[i]) arev[i] = MIN(arev[i], arev[i-1] + cs[i]);
		if (strs[i-1] <= revs[i]) arev[i] = MIN(arev[i], astr[i-1] + cs[i]);
	}

	auto res = MIN(astr[n-1], arev[n-1]);
	if (res == MAX) cout << "-1" << endl;
	else cout << res << endl;
}
