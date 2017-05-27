#include <iostream>
#include <string>
#include <vector>

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
        ssize_t x = line[0];
        ssize_t a = line[1];
        ssize_t b = line[2];
        ssize_t na = line[3];
        ssize_t nb = line[4];

        vector<ssize_t> at, bt;
        at.resize(na);
        bt.resize(nb);

        ssize_t total = 0;

        for (ssize_t j = 0; j < na; j++)
            for (ssize_t i = 0; i < nb; i++)
            {
                ssize_t estimate = x;
                estimate = min(estimate, a-at[j]);
                estimate = min(estimate, b-bt[i]);

                at[j] += estimate;
                bt[i] += estimate;
                total += estimate;
            }

        cout << total << endl;
    }
}
