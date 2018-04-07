#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	long n;
	scanf("%ld", &n);
	
	vector<vector<long>> conns(n), children(n);
	for (long i = 0; i < n-1; i++)
	{
		long x, y;
		scanf("%ld%ld", &x, &y);
		x--, y--;
		
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	
	vector<bool> visited(n);
	visited[0] = true;
	
	stack<long> visitors(n);
	visitors.push(0);
	
	while (!visitors.empty())
	{
		long vis = visitors.top();
		visitors.pop();
		
		for (long next : conns[vis])
			if (!visited[next])
			{
				visited[next] = true;
				children[vis].push_back(next);
			}
	}
}
