#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef unsigned long long ull;

constexpr ull GRAND = 10000000000000000ULL;

struct node;

struct edge
{
	node *first, *second;
	ull weight;
};

struct node
{
	vector<edge*> edges;
	ull cur_computed;
	bool is_storage;
	bool visited;
};

typedef pair<node*, size_t> prio_entry;

struct comparer
{
	bool operator()(const prio_entry& n1, const prio_entry& n2) const
	{
		return n1.second > n2.second;
	}
};

typedef priority_queue<prio_entry, vector<prio_entry>, comparer> node_queue;

ull dijkstra(node *nodes, size_t n, node* begin, node* end)
{
	for (size_t i = 0; i < n; i++)
	{
		nodes[i].cur_computed = GRAND;
		nodes[i].visited = false;
	}

	begin->cur_computed = 0;

	node_queue queue;

	for (size_t i = 0; i < n; i++)
		queue.emplace(nodes+i, nodes[i].cur_computed);

	while (!queue.empty())
	{
		auto cur = queue.top().first;
		queue.pop();

		if (cur->visited) continue;
		cur->visited = true;

		for (auto ed : cur->edges)
		{
			auto other = ed->first == cur ? ed->second : ed->first;
			if (other->cur_computed > cur->cur_computed + ed->weight)
			{
				other->cur_computed = cur->cur_computed + ed->weight;
				queue.emplace(other, other->cur_computed);
			}
		}
	}

	return end->cur_computed;
}

int main()
{
	size_t n, m, k;
	cin >> n >> m >> k;

	node* nodes = new node[n+2];
	edge* edges = new edge[m+n];

	for (size_t i = 0; i < m; i++)
	{
		size_t a, b;
		cin >> a >> b >> edges[i].weight;

		a--, b--;

		edges[i].first = nodes+a;
		edges[i].second = nodes+b;

		nodes[a].edges.push_back(edges+i);
		nodes[b].edges.push_back(edges+i);
	}

	for (size_t i = 0; i < n; i++)
		nodes[i].is_storage = false;

	for (size_t i = 0; i < k; i++)
	{
		size_t a;
		cin >> a;

		nodes[a-1].is_storage = true;
	}

	for (size_t i = 0; i < n; i++)
	{
		edges[m+i].weight = 0ULL;
		edges[m+i].first = nodes+i;
		edges[m+i].second = nodes+(n+nodes[i].is_storage);

		nodes[i].edges.push_back(edges+(m+i));
		nodes[n+nodes[i].is_storage].edges.push_back(edges+(m+i));
	}

	auto res = dijkstra(nodes, n+2, nodes+n, nodes+(n+1));

	if (res == GRAND) cout << "-1" << endl;
	else cout << res << endl;

	delete[] nodes;
	delete[] edges;
}
