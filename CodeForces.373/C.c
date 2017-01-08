#include <stdio.h>
#include <string.h>

char v[200006];
long dp[200005];

int main()
{
	long n, t;
	scanf("%ld%ld%s", &n, &t, v);
	dp[n-2] = 0;

	long char_pos = strchr(v, '.') - v;

	long min_pos = n-1;

	for (long i = n-1; i >= char_pos; i--)
	{
		if (v[i] >= '5') dp[i-1] = 1;
		else if (v[i] < '4') dp[i-1] = t+5;
		else dp[i-1] = 1 + dp[i];

		if (dp[i-1] <= t) min_pos = i-1;
	}

	min_pos -= (min_pos == char_pos);
	if (min_pos != n-1)
	{
		while (min_pos >= 0 && v[min_pos] == '9')
		{
			if (min_pos == char_pos+1) min_pos--;
			else if (min_pos <= char_pos) v[min_pos] = '0';
			
			min_pos--;
		}

		if (min_pos == -1) printf("1");
		else v[min_pos]++;
	}

	v[min_pos+1 > char_pos ? min_pos+1 : char_pos] = 0;
	printf("%s\n", v);
}
