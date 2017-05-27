#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> parseLine(istream& in)
{
    string line;
    getline(in, line);

    vector<long> result;

    while (!line.empty())
    {
        size_t idx;
        result.push_back(stol(line, &idx));
        line.erase(0, idx+1);
    }

    return result;
}

int main()
{
        vector<long> line;

    while (!(line = parseLine(cin)).empty())
    {
        ssize_t temp = line[0];
        ssize_t target = line[1];
        ssize_t range = line[2];
        ssize_t time = line[3];

        ssize_t min = target-range;
        ssize_t max = target+range;

        if (temp > max || temp <= min)
            cout << "not possible" << endl;
        else
        {
            bool state = false;
            ssize_t res = 0;
            
            while (time--)
            {
                if (!state && temp == min+1)
                {
                    state = true;
                    temp -= 2;
                    res -= 5;
                }
                else if (state && temp == max)
                    state = false;
                else if (time < temp-min)
                {
                    //res += 5;
                    state = false;
                }

                if (state)
                {
                    temp += 1;
                    res += 10;
                }
                else temp -= 1;
            }
            if (temp == min) res -= 5;

            cout << res << endl;
        }
    }
}
