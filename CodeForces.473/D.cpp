#include <cstdio>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
#define LLU "%llu"

vector<long> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
	43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109,
	113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
	193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
	271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353,
	359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
	443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523,
	541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617,
	619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709,
	719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811,
	821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
	911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009 };

using memprimes = bitset<20000>;

void generatePrimesTo(ull v)
{
	while (primes.back() < v)
	{
		ull n = primes.back();
		vector<bool> isComposite(n*n/2);
		
		for (ull p : primes)
		{
			if (p == 2) continue;
			ull v = p*p;
			for (; v < n*n; v += 2*p) isComposite[(v-1)/2] = true;
		}
		
		for (ull i = (n+1)/2; i < isComposite.size(); i++)
			if (!isComposite[i]) primes.push_back(2*i+1);
	}
}

int main()
{
    ull n;
    scanf(LLU, &n);
    
    vector<ull> vs(n);
    for (ull& v : vs)
    {
        scanf(LLU, &v);
        generatePrimesTo(v);
    }
    
    memprimes curPrimes;
    ull firstn = 0;
    for (ull v : vs)
    {
        auto it = lower_bound(primes.begin(), primes.end(), v);
        if (it != primes.end() && *it == v)
        {
            if (curPrimes[it- primes.begin()]) goto genNewArray;
            else curPrimes[it - primes.begin()] = true;
        }
        else
        {
            memprimes vprimes;
            
            ull vc = v;
            for (ull i = 0; i < primes.size(); i++)
            {
                ull p = primes[i];
                if (p*p > v) break;
                if (vc % p == 0)
                {
                    if (curPrimes[i]) goto genNewArray;
                    else
                    {
                        vprimes[i] = true;
                        while (vc % p == 0) vc /= p;
                    }
                }
            }
            
            if (vc != 1)
            {
                auto it = lower_bound(primes.begin(), primes.end(), vc);
                if (curPrimes[it - primes.begin()]) goto genNewArray;
                else vprimes[it - primes.begin()] = true;
            }
            
            curPrimes |= vprimes;
        }
        firstn++;
    }
    
    printf(LLU, vs[0]);
    for (ull i = 1; i < n; i++) printf(" " LLU, vs[i]);
    return 0;
    
genNewArray:
    for (ull i = 0; i < firstn; i++) printf(LLU " ", vs[i]);
    {
        auto it = upper_bound(primes.begin(), primes.end(), vs[firstn]);
        ull j = it - primes.begin();
        while (curPrimes[j]) ++j, ++it;
        printf(LLU, *it);
        curPrimes[j] = 1;
    }
    
    ull i = firstn+1;
    for (ull j = 0; j < primes.size(); j++)
    {
        if (!curPrimes[j])
        {
            printf(" " LLU, primes[j]);
            if (++i == n) break;
        }
    }
    
    if (i < n)
    {
        ull v = primes.back();
        ull k = v/6;
        if (v % 6 == 5) k++;
        
        while (i < n)
        {
            for (ull v1 : { 6*k+1, 6*k+5 })
            {
                if (v1 == v) continue;
                
                bool isPrime = true;
                for (ull p : primes)
                {
                    if (p*p > v1) break;
                    else if (v1 % p == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }
                
                if (isPrime)
                {
                    printf(" " LLU, v1);
                    if (++i == n) break;
                }
            }
        }
    }
    putchar('\n');
}

