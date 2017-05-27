#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long ul;

struct test
{
    vector<test*> children;
    ul time;
} tests[50];

void runningTimes(test* cur, ul& outT1, ul& outT2)
{
    outT1 = outT2 = cur->time;

    for (auto t : cur->children)
    {
        ul t1, t2;
        runningTimes(t, t1, t2);
        outT1 += t1; outT2 += 2*t2;
    }
}

int main()
{
    ul n;
    cin >> n;

    for (ul i = 0; i < n; i++)
        cin >> tests[i].time;

    for (ul i = 0; i < n; i++)
    {
        ul k;
        cin >> k;
        tests[i].children.resize(k);

        for (ul j = 0; j < k; j++)
        {
            ul t;
            cin >> t;
            tests[i].children[j] = &tests[t-1];
        }
    }

    ul t1, t2;
    runningTimes(tests, t1, t2);

    cout << t1 << ' ' << t2 << endl;
}
