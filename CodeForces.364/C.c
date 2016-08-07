#include <stdio.h>

typedef unsigned long long ull;

long char_to_index(char c)
{
	if (c >= 'A' && c <= 'Z') return c - 'A';
	else return c - 'a' + 26;
}

int all_set(long freqs[52], ull types_present)
{	
	for (long i = 0; i < 52; i++)
	{
		if ((types_present & (1ULL << i)) == 0) continue;
		if (freqs[i] == 0) return 0;
	}
	
	return 1;
}

int main()
{
	long n;
	scanf("%ld", &n);

	char types[n+1];

	scanf("%s", types);

	ull types_present = 0;
	for (long i = 0; i < n; i++)
		types_present |= (1ULL << char_to_index(types[i]));

	long freqs[52];
	for (long i = 0; i < 52; i++) freqs[i] = 0;
	
	long i = 0, j = 0;
	long min = n+50;

	while (i < n || j < n)
	{
		if (all_set(freqs, types_present))
		{
			if (min > j-i) min = j-i;
			freqs[char_to_index(types[i++])]--;
		}
		else if (j < n) freqs[char_to_index(types[j++])]++;
		else freqs[char_to_index(types[i++])]--;
	}

	printf("%ld\n", min);
}
