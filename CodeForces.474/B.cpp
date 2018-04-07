#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int n, k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    
    vector<long> delta(n);
    for (long& v : delta) scanf("%ld", &v);
    for (long& v : delta)
    {
        long w;
        scanf("%ld", &w);
        v -= w;
        if (v < 0) v = -v;
    }
    
    priority_queue<long> values(delta.begin(), delta.end());
    
    int k = k1 + k2;
    while (k--)
    {
        long v = values.top();
        values.pop();
        values.push(v == 0 ? 1 : v-1);
    }
    
    long long quadsum = 0;
    while (!values.empty())
    {
        long long v = values.top();
        values.pop();
        quadsum += v*v;
    }
    
    printf("%I64d\n", quadsum);
}
