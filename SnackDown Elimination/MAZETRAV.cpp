#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

struct node
{
	node *left, *up, *right, *down;
}

map<pair<node*,node*>,long> d_left, d_up, d_right, d_down;
pair<long,bool> find_left(node *begin, node *end);
pair<long,bool> find_up(node *begin, node *end);
pair<long,bool> find_right(node *begin, node *end);
pair<long,bool> find_down(node *begin, node *end);

pair<long,bool> find_left(node *begin, node* end)
{
	if (begin == end) return make_pair(0,true);

	bool found = false;

	auto it = d_left.find(make_pair(begin, end));
	if (it == d_left.end())
	{
		long dist = 0;
		if (begin->left->up)
		{
			auto p = find_up(begin->left, end);
			dist += p.first;
			if (p.second) goto ret;
		}
		
		if (begin->left->left)
		{
			auto p = find_left(begin->left, end);
			dist += p.first;
			if (p.second) goto ret;
		}
		
		if (begin->left->left)
		{
			auto p = find_left(begin->left, end);
			dist += p.first;
			if (p.second) goto ret;
		}
	}

ret:
	return make_pair(*it, found);
}

int main()
{
	long r, c, q;
	cin >> r >> c >> q;

	node *nodes = new node[r*c];
	string buffer;

	cin >> buffer;
	for (long i = 0; i < c; i++)
		nodes[i].up = nullptr;

	for (long j = 0; j < r; j++)
	{
		cin >> buffer;
		for (long i = 0; i < c; i++)
		{
			nodes[j*c+i].left = buffer[2*i] == '.' ? nodes+(j*c+(i-1)) : nullptr;
			nodes[j*c+i].right = buffer[2*(i+1)] == '.' ? nodes(j*c+(i+1)) : nullptr;
		}

		cin >> buffer;
		for (long i = 0; i < c; i++)
		{
			nodes[j*c+i].down = buffer[2*i+1] == '.' ? nodes+((j+1)*c+i) : nullptr;
			if (j < r-1)
				nodes[(j+1)*c+i].up = buffer[2*i+1] == '.' ? nodes+(j*c+i) : nullptr;
		}
	}

	

	delete[] nodes;
}
