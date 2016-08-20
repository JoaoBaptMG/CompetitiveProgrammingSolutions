#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <map>

using namespace std;

struct op { int type; size_t i, j; };

int main()
{
	int n, m, q;

	cin >> n >> m >> q;

	op *ops = new op[q];

	set<int> t4q;
	for (int i = 0; i < q; i++)
	{
		cin >> ops[i].type >> ops[i].i;

		if (ops[i].type < 3) cin >> ops[i].j;
		else if (ops[i].type == 4)
			t4q.insert(ops[i].i);
	}
	
	set<pair<int,int>> pairs;
	map<int,decltype(pairs)> history;

	history.emplace(0, pairs);

	auto t4q_it = t4q.begin();

	for (int i = 0; i < q; i++)
	{
		switch (ops[i].type)
		{
		case 1: pairs.emplace(ops[i].i, ops[i].j); break;
		case 2: pairs.erase(make_pair(ops[i].i, ops[i].j)); break;
		case 3:
			{
				decltype(pairs) temp;

				auto it = pairs.lower_bound(make_pair(ops[i].i, 1));
				for (int j = 1; j <= m; j++)
					if (it != pairs.end() && it->first == ops[i].i && it->second == j)
						it = pairs.erase(it);
					else temp.emplace(ops[i].i, j);

				pairs.insert(temp.begin(), temp.end());
			} break;
		case 4: pairs = history.at(ops[i].i);
		}

		if (*t4q_it == i+1)
		{
			history.emplace(i+1, pairs);
			t4q_it++;
		}

		cout << pairs.size() << endl;
	}

	delete[] ops;
}
