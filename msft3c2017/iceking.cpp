#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    size_t n = 25;

    while (n--)
    {
        string val;
        getline(cin, val);

        stringstream ss(val);
        vector<size_t > heights;

        size_t  v;
        while (ss >> v) heights.push_back(v);

        size_t  maxArea = 0, mi, mj;
        for (size_t j = 0; j < heights.size(); j++)
            for (size_t i = j+1; i < heights.size(); i++)
            {
                size_t area = min(heights[i], heights[j])*(i-j);
                if (maxArea < area) maxArea = area, mi = i, mj = j;
            }

        cout << maxArea << ' ' << mj << ' ' << mi << endl;
    }
}
