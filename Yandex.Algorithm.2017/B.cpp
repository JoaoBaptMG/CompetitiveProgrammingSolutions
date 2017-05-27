#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long ul;

int main()
{
    ul c;
    cin >> c;

    unordered_map<string,unordered_map<string,uint32_t>> offices;
    unordered_map<string,uint32_t> totalAvailability;

    for (ul i = 0; i < c; i++)
    {
        string cname;
        ul k;
        cin >> cname >> k;

        for (ul j = 0; j < k; j++)
        {
            string av, name;
            cin >> av >> name;

            uint32_t availability = 0;
            for (char ch : av)
            {
                availability <<= 1;
                if (ch == '.') availability |= 1;
            }

            offices[cname].emplace(name, availability);
            totalAvailability[cname] |= availability;
        }
    }

    ul m;
    cin >> m;

    for (ul i = 0; i < m; i++)
    {
        ul l;
        cin >> l;

        vector<string> cities;
        uint32_t commonAvailability = 0xFFFFFFFF;
        for (ul j = 0; j < l; j++)
        {
            string name;
            cin >> name;
            cities.push_back(name);
            commonAvailability &= totalAvailability[name];
        }

        if (commonAvailability == 0)
            cout << "No" << endl;
        else
        {
            cout << "Yes";
            uint32_t firstBit = commonAvailability & -commonAvailability;
            
            for (ul j = 0; j < l; j++)
            {
                string roomName;
                for (const auto& p : offices[cities[j]])
                {
                    if (p.second & firstBit)
                    {
                        roomName = p.first;
                        break;
                    }
                }

                cout << ' ' << roomName;
            }

            cout << endl;
        }
    }

    return 0;
}
