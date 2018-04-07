#include <cstdio>
#include <vector>

using namespace std;

long discreteLog2(long x)
{
    long r = -1;
    while (x)
    {
        r++;
        x >>= 1;
    }
    
    return r;
}

int main()
{
    long x, d;
    scanf("%ld%ld", &x, &d);
    long n = 1+discreteLog2(x+1);
    
    long sum = 0;
    vector<long> vals;
    
    while (--n)
    {
        while (x >= (1LL << n) - 1)
        {
            vals.push_back(n);
            sum += n;
            x -= (1LL << n) - 1;
        }
    }
    
    if (vals.empty() || sum >= 10000) puts("-1");
    else
    {
        printf("%ld\n", sum);
        
        long long k = 1;
        bool nf = false;
        for (long v : vals)
        {
            while (v--)
            {
                if (nf) putchar(' ');
                nf = true;
                printf("%I64d", k);
            }
            
            k += d;
        }
    }
}
