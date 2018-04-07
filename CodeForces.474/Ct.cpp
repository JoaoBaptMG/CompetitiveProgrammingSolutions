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
    for (long xc = 1; xc < 100000; xc++)
    {
        long x = xc;
        printf("%ld = ", x);
        
        vector<long> vals;
        long n = 1+discreteLog2(x+1);
        
        while (--n)
        {
            while (x >= (1LL << n) - 1)
            {
                vals.push_back(n);
                x -= (1LL << n) - 1;
            }
        }
        
        for (long v : vals) printf("V(%ld) + ", v);
        printf("%ld\n", x);
    }
}
