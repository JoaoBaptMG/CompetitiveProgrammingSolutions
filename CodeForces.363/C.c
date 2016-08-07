#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int ors = 1, oct = 0, osp = 0;
	int nrs, nct, nsp;

	while (n--)
	{
		int k;
		scanf("%d", &k);
		
		int min = ors;
		if ((k & 1) && min > oct) min = oct;
		if ((k & 2) && min > osp) min = osp;
		nrs = min+1;

		min = ors;
		if ((k & 2) && min > osp) min = osp;
		nct = min;

		min = ors;
		if ((k & 1) && min > oct) min = oct;
		nsp = min;

		ors ^= nrs; nrs ^= ors; ors ^= nrs;
		oct ^= nct; nct ^= oct; oct ^= nct;
		osp ^= nsp; nsp ^= osp; osp ^= nsp;
	}

	int min = ors;
	if (min > oct) min = oct;
	if (min > osp) min = osp;
	printf("%d\n", min);
}
