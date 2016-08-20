#include <stdio.h>
#include <math.h>

int main()
{
	double min_time = HUGE_VAL;
	double x, y;
	scanf("%lf%lf", &x, &y);

	int n;
	scanf("%d", &n);

	while (n--)
	{
		double xp, yp, vp;
		scanf("%lf%lf%lf", &xp, &yp, &vp);
		double time = hypot(xp-x, yp-y)/vp;
		if (min_time > time)
			min_time = time;
	}

	printf("%lg\n", min_time);
}
