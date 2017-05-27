#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rings[3][16];
int ringPos[3];

int hexToNumber(char k)
{
    if (k >= 'A' && k <= 'F')
        return 10 + k - 'A';
    return k - '0';
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        string buffer;
        cin >> buffer;
        transform(&buffer[0], &buffer[16], &rings[i][0], hexToNumber);
        ringPos[i] = 0;
    }

    string asciiMsg;
    cin >> asciiMsg;

    vector<int> ascii(asciiMsg.size());
    transform(asciiMsg.begin(), asciiMsg.end(), ascii.begin(), hexToNumber);

    for (int& cur : ascii)
    {
        int maxId = 0;
        for (int i = 0; i < 3; i++)
        {
            cur -= rings[i][ringPos[i]];

            if (rings[maxId][ringPos[maxId]] < rings[i][ringPos[i]])
                maxId = i;
        }
        
        cur = (cur + 80) % 16;
        ringPos[maxId] = (ringPos[maxId] + 1) % 16;
    }

    for (size_t i = 0; i < ascii.size()/2; i++)
        cout << char(ascii[2*i] * 16 + ascii[2*i+1]);
    cout << endl;

    return 0;
}
