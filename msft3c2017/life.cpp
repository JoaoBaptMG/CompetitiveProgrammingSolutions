#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void update(char v, size_t& m, size_t& f)
{
    if (v == '#') m++;
    else if (v == '*') f++;
}

int main()
{
    size_t h, w, t;
    cin >> h >> w >> t;
    
    vector<char> matrix;
    matrix.resize(w*h);
    for (size_t j = 0; j < h; j++)
    {
        string buffer;
        cin >> buffer;
        copy_n(buffer.c_str(), w, &matrix[w*j]);
    }

    vector<char> destMatrix;
    destMatrix.resize(w*h);
    while (t--)
    {
        for (size_t j = 0; j < h; j++)
            for (size_t i = 0; i < w; i++)
            {
                size_t m = 0, f = 0;

                if (i > 0) update(matrix[w*j+(i-1)], m, f);
                if (i < w-1) update(matrix[w*j+(i+1)], m, f);

                if (j > 0) update(matrix[w*(j-1)+i], m, f);
                if (j < h-1) update(matrix[w*(j+1)+i], m, f);

                char v = matrix[w*j+i];
                if (v == '#' && (f < 2 || f > 3)) v = '.';
                else if (v == '*' && (m < 2 || m > 3)) v = '.';
                else if (m == 2 && f == 1) v = '*';
                else if (m == 1 && f == 2) v = '#';

                destMatrix[w*j+i] = v;
            }
        
        matrix = destMatrix;
    }

    for (size_t j = 0; j < h; j++)
    {
        for (size_t i = 0; i < w; i++)
            cout << matrix[w*j+i];
        cout << endl;
    }
}
