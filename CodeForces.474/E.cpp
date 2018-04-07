#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

#define LLD "%lld"

int main()
{
    ll n;
    scanf(LLD, &n);
    
    vector<ll> ws(n);
    for (ll& w : ws) scanf(LLD, &w);
    
    vector<vector<ll>> siblings(n);
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        scanf(LLD LLD, &a, &b);
        a--, b--;
        
        siblings[a].push_back(b);
        siblings[b].push_back(a);
    }
    
    vector<bool> visited(n, false), group(n);
    visited[0] = true;
    group[0] = false;
    
    vector<ll> stack, groups[2];
    stack.push_back(0);
    
    while (!stack.empty())
    {
        ll v = stack.back();
        stack.pop_back();
        
        for (ll k : siblings[v])
        {
            if (!visited[k])
            {
                visited[k] = true;
                group[k] = !group[v];
                stack.push_back(k);
            }
        }
    }
    
    for (ll i = 0; i < n; i++)
        groups[group[i]].push_back(i);
        
    
}
