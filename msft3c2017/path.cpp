#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct pt
{
    size_t x, y;
    pt(size_t x, size_t y) : x(x), y(y) {}
    pt() : pt(0, 0) {}
};

size_t absdiff(size_t a, size_t b)
{
    return a > b ? a-b : b-a;
}

bool near(pt a, pt b)
{
    return absdiff(a.x, b.x) + absdiff(a.y, b.y) <= 1;
}

int main()
{
    int m;
    cin >> m;

    while (m--)
    {
        size_t n, x, y;
        cin >> n >> x >> y;

        vector<pt> positions;
        positions.resize(x*y);

        for (size_t j = 0; j < x; j++)
            for (size_t i = 0; i < y; i++)
            {
                size_t num;
                cin >> num;

                positions[num-1] = pt(i, j);
            }

        bool found = true;
        for (size_t i = 1; i < n; i++)
            if (!near(positions[i], positions[i-1]))
            {
                found = false;
                break;
            }

        cout << (found ? "true" : "false") << endl;
    }
}
