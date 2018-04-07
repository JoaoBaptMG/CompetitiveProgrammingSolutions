#include <cstdio>
#include <map>

using namespace std;

#define LLD "%I64d"

long discreteLog2(long long x)
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
    long q;
    
    scanf("%ld", &q);
    
    map<long, long long> shiftValues, shiftNodes;
    
    while (q--)
    {
        long t;
        long long x;
        scanf("%ld" LLD, &t, &x);
        
        long lvl = discreteLog2(x);
        long long l2 = 1LL << lvl;
        
        if (t <= 2)
        {
            long long k;
            scanf(LLD, &k);
            
            auto& s = t == 1 ? shiftValues : shiftNodes;
            s[lvl] = (s[lvl] + k + l2) % l2;
        }
        else
        {
            x = l2 + (x - l2 + shiftValues[lvl]) % l2;
            printf(LLD, l2 + (x - shiftValues[lvl]) % l2);
            
            while (x > 1)
            {
                x = l2 + (x - l2 + shiftNodes[lvl]) % l2;
                x /= 2, lvl--, l2 /= 2;
                printf(" " LLD, l2 + (x - shiftValues[lvl]) % l2);
            }
            
            putchar('\n');
        }
    }
}
