#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
using namespace std;

typedef unsigned long ul;

void push_insert(vector<string> &cmds, ul n)
{
	ostringstream str;
	str << "insert " << n;
	cmds.push_back(str.str());
}

void push_get_min(vector<string> &cmds, ul n)
{
	ostringstream str;
	str << "getMin " << n;
	cmds.push_back(str.str());
}

void push_remove(vector<string> &cmds)
{
	cmds.emplace_back("removeMin");
}

int main()
{
	long n;
	cin >> n;

	vector<string> cmds;
	priority_queue<ul, vector<ul>, greater<ul>> heap;

	while (n--)
	{
		string cmd;
		ul v;

		cin >> cmd;
		if (cmd[0] == 'i')
		{
			cin >> v;
			push_insert(cmds, v);
			heap.push(v);
		}
		else if (cmd[0] == 'r')
		{
			if (heap.empty())
			{
				push_insert(cmds, 0);
				heap.push(0);
			}
			push_remove(cmds);
			heap.pop();
		}
		else
		{
			cin >> v;
			while (!heap.empty() && heap.top() < v)
			{
				push_remove(cmds);
				heap.pop();
			}

			if (heap.empty() || heap.top() > v)
			{
				push_insert(cmds, v);
				heap.push(v);
			}

			push_get_min(cmds, v);
		}
	}

	cout << cmds.size() << endl;
	for (const string &str : cmds)
		cout << str << endl;
}
