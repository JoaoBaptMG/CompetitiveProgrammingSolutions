#include <iostream>
#include <vector>

using namespace std;

struct node
{
	long tree_size = -1, max_children_size = -1;
	bool found_centroids = false;

	vector<node*> children;
	node* parent;
	node* centroid = nullptr;
};

void calc_tree_size(node* cur)
{
	if (cur->tree_size != -1) return;
	cur->tree_size = 1;
	cur->max_children_size = 0;

	for (node *p : cur->children)
	{
		calc_tree_size(p);
		cur->tree_size += p->tree_size;

		if (cur->max_children_size < p->tree_size)
			cur->max_children_size = p->tree_size;
	}
}

bool is_centroid(node* cur, node* test)
{
	if (cur->tree_size - test->tree_size > cur->tree_size/2) return false;
	if (test->max_children_size > cur->tree_size/2) return false;

	return true;
}

void find_centroid(node* cur)
{
	if (cur->found_centroids) return;
	cur->found_centroids = true;

	cur->centroid = cur;

	for (node* p : cur->children)
	{
		if (p->tree_size > cur->tree_size/2)
		{
			find_centroid(p);

			for (node *t = p->centroid; t != cur; t = t->parent)
				if (is_centroid(cur, t))
				{
					cur->centroid = t;
					break;
				}
			
			break;
		}
	}
}

int main()
{
	long n, q;

	cin >> n >> q;

	node *nodes = new node[n];

	for (long i = 1; i < n; i++)
	{
		long v;
		cin >> v;
		nodes[v-1].children.push_back(nodes+i);
		nodes[i].parent = nodes+(v-1);
	}

	calc_tree_size(nodes);

	while (q--)
	{
		long v;
		cin >> v;

		node* target = nodes+(v-1);
		find_centroid(target);
		cout << (target->centroid + 1 - nodes) << endl;
	}

	delete[] nodes;
}
