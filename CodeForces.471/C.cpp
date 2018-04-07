#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

constexpr ull MAX = 1000000000000000000ULL;

ull upow(ull a, ull b)
{
	ull ar = a, r = 1;
	while (b)
	{
		if (b&1) r *= ar;
		ar *= ar;
		b >>= 1;
	}
	
	return r;
}

ull uroot(ull a, ull b)
{
	if (a <= 1 || b <= 1) return a;
	
	const ull maximums[] =
	{
		0, 0, 1000000000ULL, 1000000, 31622, 3981, 1000, 372, 177, 99, 63, 
		43, 31, 24, 19, 15, 13, 11, 10, 8, 7, 7, 6, 6, 5, 5, 4, 4, 4, 4, 
		3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
		2, 2, 2, 2, 2, 2, 2, 2
	};
	
	ull l = 1, r = maximums[b]+1;
    ull it, count = r-l, step;
 
    while (count > 0)
    {
        it = l;
        step = count / 2; 
        it += step;
        if (!(a < upow(it, b))) {
            l = ++it;
            count -= step + 1;
        }
        else count = step;
    }

    return l-1;
}

constexpr ull primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
constexpr ull primes2[] = { 6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 55, 57, 58 };
constexpr ull primes3[] = { 30, 42 };

int main()
{
	ull q;
	cin >> q;
	
	while (q--)
	{
		ull l, r;
		cin >> l >> r;
		
		ull sum = l == 1 ? 1 : 0;
		if (l > 1) l--;
		
		for (ull p : primes) sum += uroot(r, p) - uroot(l, p);
		for (ull p : primes2) sum -= uroot(r, p) - uroot(l, p);
		for (ull p : primes3) sum += uroot(r, p) - uroot(l, p);
		
		cout << sum << endl;
	}
}
