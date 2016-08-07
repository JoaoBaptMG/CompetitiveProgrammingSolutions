#include <stdio.h>
#include <math.h>

double time(double n, double l, double v1, double v2, double k)
{
	double j = ceil(n/k);

	return (v1 + 2*v2*j - v2)/(v2 * (v1 + v2) * (v1 + v2 + 2 * (j-1)));
}

int main()
{
	double n, l, v1, v2, k;
	scanf("%lf%lf%lf%lf%lf", &n, &l, &v1, &v2, &k);
	printf("%lg", time(n, l, v1, v2, k));
}
