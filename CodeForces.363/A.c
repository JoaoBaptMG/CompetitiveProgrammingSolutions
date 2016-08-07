#include <stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))

int main()
{
	long n;
	scanf("%ld", &n);

	char vals[n+1];
	long pos[n];

	scanf("%s", vals);

	for (long i = 0; i < n; i++)
		scanf("%ld", pos+i);

	unsigned long min = (unsigned long)-1;

	for (long i = 0; i < n-1; i++)
	{
		if (vals[i] == 'R' && vals[i+1] == 'L')
			min = MIN(min, pos[i+1]/2 - pos[i]/2);
	}

	printf("%ld", min);
}
