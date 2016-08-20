#include <iostream>
#include <memory>

using namespace std;

struct trie
{
	long freq = 0;
	unique_ptr<trie> freqs[2];

	void insert(uint32_t n, uint32_t depth = 32)
	{
		if (depth == 0)
			freq++;
		else
		{
			uint32_t i = n >> 31;

			if (!freqs[i])
				freqs[i] = unique_ptr<trie>{new trie()};

			freqs[i]->insert(n << 1, depth - 1);
		}
	}

	void remove(uint32_t n, uint32_t depth = 32)
	{
		if (depth == 0)
			freq--;
		else
		{
			uint32_t i = n >> 31;

			if (freqs[i])
			{
				freqs[i]->remove(n << 1, depth-1);
				
				if (freqs[i]->empty())
					freqs[i] = nullptr;
			}
		}
	}

	uint32_t find_max(uint32_t x, uint32_t depth = 32, uint32_t compositing = 0) const
	{
		if (depth == 0)
			return compositing;
		
		uint32_t i = x >> 31;

		if (freqs[!i])
			return freqs[!i]->find_max(x << 1, depth - 1, (compositing << 1) | 1);
		else
			return freqs[i]->find_max(x << 1, depth - 1, compositing << 1);
	}

	bool empty() const
	{
		return !freqs[0] && !freqs[1] && freq == 0;
	}
};

int main()
{
	trie cur_trie;
	cur_trie.insert(0);

	uint32_t q;
	cin >> q;

	while (q--)
	{
		char c;
		uint32_t x;

		cin >> c >> x;

		if (c == '+')
			cur_trie.insert(x);
		else if (c == '-')
			cur_trie.remove(x);
		else cout << cur_trie.find_max(x) << endl;
	}
}
