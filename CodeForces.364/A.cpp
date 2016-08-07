#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *vals = new int[n];
	int *nums = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> vals[i];
		nums[i] = i;
	}

	sort(nums, nums+n, [&vals] (int a, int b)
	{
		return vals[a] < vals[b];
	});

	for (int i = 0; i < n/2; i++)
		cout << (nums[i]+1) << ' ' << (nums[n-1-i]+1) << endl;

	delete[] vals;
	delete[] nums;
}
