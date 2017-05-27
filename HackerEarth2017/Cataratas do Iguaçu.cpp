#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
 
using namespace std;
 
void erase_just_one(multiset<long>& w, long v)
{
    auto it = w.find(v);
    if (it != w.end()) w.erase(it);
}
 
int main()
{
    long n, k;
    cin >> n >> k;
 
    if (k == 1)
    {
        long max = 0;
        for (long i = 0; i < n; i++)
        {
            long v;
            cin >> v;
            if (max < v) max = v;
        }
        cout << max << endl;
    }
    else
    {
        multiset<long> w;
        queue<long> q;
 
        for (long i = 0; i < k; i++)
        {
            long v;
            cin >> v;
 
            w.insert(v);
            q.push(v);
        }
        
        auto median = w.begin();
        advance(median, k/2);
 
        long maxMedian = *median;
        for (long i = k; i < n; i++)
        {
            long v;
            cin >> v;
            q.push(v);
 
            long lv = q.front();
            q.pop();
 
            if (lv == *median)
            {
                if (v == *median) continue;
                median = w.erase(median);
                if (v < lv) median--;
                w.insert(v);
            }
            else
            {
                erase_just_one(w, lv);
                w.insert(v);
                if (lv < *median && v >= *median) median++;
                else if (lv >= *median && v < *median) median--;
            }
 
            if (maxMedian < *median)
                maxMedian = *median;
        }
 
        cout << maxMedian << endl;
    }
}
