#include <cstdio>
#include <vector>

using namespace std;

struct node
{
	long tree_size = -1;
	double expected_value = -1;
	
	vector<node*> siblings;
	node* parent = nullptr;

	void calc_tree_size()
	{
		tree_size = 1;
		for (node *p : siblings)
		{
			p->calc_tree_size();
			tree_size += p->tree_size;
		}
	}

	void calc_expected_value()
	{
		if (parent && parent->expected_value == -1) parent->calc_expected_value();

		double sum = 0;

		for (node *p : siblings)
			sum += p->tree_size;

		for (node *p : siblings)
			p->expected_value = expected_value + 1 + (sum - p->tree_size)/2;
	}
};

int main()
{
	long n;
	scanf("%ld", &n);

	node *nodes = new node[n];

	for (long i = 1; i < n; i++)
	{
		long k;
		scanf("%ld", &k);
		k--;

		nodes[i].parent = nodes+k;
		nodes[k].siblings.push_back(nodes+i);
	}

	nodes[0].expected_value = 1;
	nodes[0].calc_tree_size();

	for (long i = 0; i < n; i++)
		nodes[i].calc_expected_value();

	printf("%g", nodes[0].expected_value);
	for (long i = 1; i < n; i++)
		printf(" %g", nodes[i].expected_value);
	putchar('\n');

	delete[] nodes;

	return 0;
}
