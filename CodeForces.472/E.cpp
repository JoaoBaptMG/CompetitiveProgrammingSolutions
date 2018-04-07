#include <iostream>
#include <map>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ull gcd(ull a, ull b)
{
	return b == 0 ? a : gcd(b, a%b);
}

struct fraction { ull n, d; };
bool operator<(const fraction& f1, const fraction& f2)
{
	return f1.n * f2.d < f2.n * f1.d;
}

constexpr ull mid = 0x8000000000000000ULL;

int main()
{
	ull n, w;
	cin >> n >> w;

	multimap<pair<fraction,ull>,ull> values;
	for (ull i = 0; i < n; i++)
	{
		ll x, v;
		cin >> x >> v;
		
		ull x0 = x >= 0 ? x : -x;
		ull v0 = v >= 0 ? v : -v;
		
		ull g = gcd(x0, v0+w);
		values.emplace(make_pair(fraction{ x0/g, (v0+w)/g }, 2 + (x > 0)), i);
		g = gcd(x0, v0-w);
		values.emplace(make_pair(fraction{ x0/g, (v0-w)/g }, (x > 0)), i);
	}
	
	ull all = 0;
	ull cur[2] = { 0, 0 };
	bool prevIncr[2] = { false, false };
	for (const auto& p : values)
	{	
		if (p.first.second & 2)
		{
			int i = p.first.second&1;
			
			cur[i]++;
			prevIncr[i] = true;
		}
		else
		{
			int i = p.first.second&1;
			
			if (prevIncr[i]) all += cur[0] * cur[1];
			cur[i]--;
			prevIncr[i] = false;
		}
		
		cout << endl;
	}
	
	cout << all << endl;
}
