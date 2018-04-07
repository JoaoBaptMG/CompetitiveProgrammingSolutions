#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ull n, k, m;
    cin >> n >> k >> m;
    
    vector<string> wordName(n);
    vector<ull> wordCost(n);
    for (auto& str : wordName) cin >> str;
    for (auto& cost : wordCost) cin >> cost;
    
    map<string,ull> group;
    vector<ull> minCost(k, 1000000000000000ULL);
    
    for (ull i = 0; i < k; i++)
    {
        ull ki;
        cin >> ki;
        while (ki--)
        {
            ull j;
            cin >> j;
            group[wordName[j-1]] = i;
            if (minCost[i] > wordCost[j-1])
                minCost[i] = wordCost[j-1];
        }
    }
    
    ull totalCost = 0;
    while (m--)
    {
        string word;
        cin >> word;
        totalCost += minCost[group[word]];
    }
    
    cout << totalCost << endl;
}
