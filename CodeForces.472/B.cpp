#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long long ull;

int main()
{
	int n, m;
	cin >> n >> m;
	
	string grid;
	grid.reserve(n*m);
	
	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		grid += line;
	}
	
	vector<ull> lines(n, 0), cols(m, 0);
	
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
		{
			if (grid[j*m+i] == '#')
			{
				lines[j] |= (1ULL << i);
				cols[i] |= (1ULL << j);
			}
		}
		
	bool possible = true;
		
	if (!possible) goto shortcircuit;
	
	for (int i2 = 0; i2 < m; i2++)
		for (int i1 = i2+1; i1 < m; i1++)
			if (cols[i1] & cols[i2])
				if (cols[i1] != cols[i2])
				{
					possible = false;
					goto shortcircuit;
				}

	for (int j2 = 0; j2 < n; j2++)
		for (int j1 = j2+1; j1 < n; j1++)
			if (lines[j1] & lines[j2])
				if (lines[j1] != lines[j2])
				{
					possible = false;
					goto shortcircuit;
				}
		
shortcircuit:
	puts(possible ? "Yes" : "No");
}
