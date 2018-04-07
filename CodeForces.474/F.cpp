#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct edge
{
    long a, b, weight;
    
    bool isConnected(const edge& o) const
    {
        return a == o.a || a == o.b || b == o.a || b == o.b;
    }
};

int main()
{
    long n, m;
    scanf("%ld %ld", &n, &m);
    
    vector<edge> edges(m);
    for (edge& e : edges)
        scanf("%ld%ld%ld", &e.a, &e.b, &e.weight);
        
    vector<long> ends;
    vector<long> prevs(m);
    ends.reserve(m);
    
    for (long i = 0; i < edges.size(); i++)
    {
        const edge& e = edges[i];
        auto it = upper_bound(ends.begin(), ends.end(), e.weight);
        if (it == ends.end())
        {
            prevs[i] = ends.size() - 1;
            
            if (edges[prevs[i]].isConnected(e))
                ends.push_back(e.weight);
        }
        else
        {
            prevs[i] = it - ends.begin() - 1;
            
            if (edges[prevs[i]].isConnected(e))
                *it = e.weight;
        }
    }
    
    printf("%ld", (long)ends.size());
}
