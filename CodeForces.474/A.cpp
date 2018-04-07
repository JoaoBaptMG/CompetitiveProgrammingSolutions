#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int nv[3] = { 0 };
    bool possible = true;
    int step = 0;
    
    for (char c : s)
    {
        if (c == 'b' + step) step++;
        if (c == 'a' + step) nv[step]++;
        else
        {
            possible = false;
            break;
        }
    }
    
    possible = possible && nv[0] > 0 && nv[1] > 0 && (nv[0] == nv[2] || nv[1] == nv[2]);
    cout << (possible ? "YES" : "NO") << endl;
}
