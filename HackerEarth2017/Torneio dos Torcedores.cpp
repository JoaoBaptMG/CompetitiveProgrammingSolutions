#include <iostream>

using namespace std;

int choose(int* per, int i, int j)
{
    return per[i] >= per[j] ? i : j;
}

int main()
{
    int per[4];
    int ts[4];

    for (int i = 0; i < 4; i++)
    {
        int h, t;
        cin >> h >> t;
        per[i] = h + t;
        ts[i] = t;
    }

    int w1 = choose(per, 0, 1);
    int w2 = choose(per, 2, 3);

    per[w1] += ts[5-w2];
    per[w2] += ts[1-w1];
    
    int w = choose(per, w1, w2);

    cout << (w+1) << endl;
}
