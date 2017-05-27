#include <iostream>
#include <memory>

using namespace std;

int main()
{
    long n;
    cin >> n;

    long long sum1 = 0, sum2 = 0;
    unique_ptr<long long[]> values(new long long[n]);

    for (long i = 0; i < n; i++)
    {
        cin >> values[i];
        sum2 += values[i];
    }

    long long max = 0;
    for (long i = 0; i < n-1; i++)
    {
        sum1 += values[i];
        sum2 -= values[i];

        if (max < sum1*sum2)
            max = sum1*sum2;
    }

    cout << max << endl;
}
