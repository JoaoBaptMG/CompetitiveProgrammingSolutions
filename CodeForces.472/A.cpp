#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	string v(n+5, 0);
	scanf("%s", &v[0]);
	
	bool possible = false;
	if (v.front() == '?' || v.back() == '?') possible = true;
	else
	{
		for (int i = 1; i < n-1; i++)
		{
			if (v[i] == '?' && v[i+1] == '?')
			{
				possible = true;
				break;
			}
			else if (v[i] == '?' && v[i-1] == v[i+1])
			{
				possible = true;
				break;
			}
		}
	}
	
	for (int i = 1; i < n; i++)
	{
		if (v[i] != '?' && v[i] == v[i-1])
		{
			possible = false;
			break;
		}
	}
	
	puts(possible ? "Yes" : "No");
}
