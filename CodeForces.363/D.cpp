#include <iostream>
#include <set>
#include <stack>

using namespace std;

int main()
{
	long n;
	cin >> n;

	long *parents = new long[n];
	bool *visited = new bool[n];
	long *comp_ids = new long[n];

	for (long i = 0; i < n; i++)
	{
		visited[i] = false;
		comp_ids[i] = -1;
	}

	for (long i = 0; i < n; i++)
	{
		cin >> parents[i];
		parents[i]--;
	}

	set<long> roots;
	long cur_cid = 0;

	for (long i = 0; i < n; i++)
	{
		if (visited[i]) continue;

		stack<long> dfs;
		dfs.push(i);

		while (!visited[dfs.top()])
		{
			visited[dfs.top()] = true;

			if (visited[parents[dfs.top()]] && comp_ids[parents[dfs.top()]] == -1)
			{
				roots.insert(dfs.top());
				comp_ids[dfs.top()] = cur_cid++;
			}
			else dfs.push(parents[dfs.top()]);
		}

		while (dfs.size() > 1)
		{
			dfs.pop();
			comp_ids[dfs.top()] = comp_ids[parents[dfs.top()]];
		}
	}

	auto changes = roots.size() - 1;
	long primary_root = -1;
	for (long root : roots)
	{
		if (parents[root] == root)
		{
			primary_root = root;
			break;
		}
	}

	if (primary_root == -1)
	{
		changes++;
		primary_root = *roots.begin();
		parents[primary_root] = primary_root;
	}

	for (long root : roots)
		parents[root] = primary_root;

	cout << changes << endl << (parents[0]+1);
	for (long i = 1; i < n; i++)
		cout << ' ' << (parents[i]+1);
	cout << endl;
	
	delete[] parents;
	delete[] visited;
	delete[] comp_ids;
}
