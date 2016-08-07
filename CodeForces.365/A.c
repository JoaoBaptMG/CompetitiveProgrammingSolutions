#include <stdio.h>

int main()
{
	int n, a = 0, b = 0;
	scanf("%d", &n);

	while (n--)
	{
		int ad, bd;
		scanf("%d%d", &ad, &bd);

		if (ad > bd) a++;
		else if (ad < bd) b++;
	}

	if (a > b) puts("Mishka");
	else if (a < b) puts("Chris");
	else puts("Friendship is magic!^^");

	return 0;
}
