#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

constexpr ll MOD = 1000000007LL;

ll pows(ll a, ll b)
{
	ll r = 1;

	while (b)
	{
		if (b % 2) r = r * a % MOD;
		
		a = a * a % MOD;
		b /= 2;
	}

	return r;
}

ll distances[52][52];

struct node
{
	vector<node*> siblings;
};

void find_distances(node *begin, node *base, node *cur, ll dist)
{
	if (cur == nullptr) cur = begin;

	distances[begin-base][cur-base] = distances[cur-base][begin-base] = dist;

	for (node *r : cur->siblings)
		if (distances[r-base][begin-base] == -1)
			find_distances(begin, base, r, dist+1);
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		ll n, k;
		cin >> n >> k;

		node *nodes = new node[n];

		for (ll i = 0; i < n-1; i++)
		{
			for (ll j = 0; j < n; j++)
				distances[i][j] = -1;
			
			ll a, b;
			cin >> a >> b;

			nodes[a-1].siblings.push_back(nodes+(b-1));
			nodes[b-1].siblings.push_back(nodes+(a-1));
		}

		for (ll i = 0; i < n; i++)
			find_distances(nodes+i, nodes, nodes+i, 1);

		for (ll j = 0; j < n; j++)
		{
			for (ll i = 0; i < n; i++)
				cout << distances[i][j] << ' ';
			cout << endl;
		}

		ll r = pows(k, n);

		for (ll j = 0; j < n-1; j++)
			for (ll i = j+1; i < n; i++)
			{
				if (distances[i][j] < 3) continue;

				ll d = distances[i][j];
				ll c = pows(k, n-d+1) * pows(k-1, d-2) % MOD;

				r = (r + MOD - c) % MOD;
			}

		cout << r << endl;

		delete[] nodes;
	}
}
