#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int in_search(const void *pkey, const void *pelem)
{
	double k = *(double*)pkey;
	double i1 = ((double*)pelem)[0];
	double i2 = ((double*)pelem)[1];

	if (k < i1) return -1;
	if (k >= i2) return 1;
	return 0;
}

int de_search(const void *pkey, const void *pelem)
{
	double k = *(double*)pkey;
	double i1 = ((double*)pelem)[1];
	double i2 = ((double*)pelem)[0];

	if (k < i1) return 1;
	if (k >= i2) return -1;
	return 0;
}

int main()
{
	long n;
	double w, v, u;
	double cur_time;

	scanf("%ld%lf%lf%lf", &n, &w, &v, &u);

	struct { double x, y; } points[n];
	double in_y[n], de_y[n];
	long in_size = 0, de_size = 0;
	long in_point = 0, de_point = 0;

	for (long i = 0; i < n; i++)
		scanf("%lf%lf", &points[i].x, &points[i].y);

	for (long i = 0; i < n; i++)
	{
		long in = (i+n-1)%n;
		long ip = (i+1)%n;

		if (points[ip].y > points[i].y && points[in].y >= points[i].y) in_point = i;
		if (points[ip].y < points[i].y && points[in].y <= points[i].y) de_point = i;
	}

	long i;
	for (i = in_point; i != de_point; i = (i+1)%n)
		in_y[in_size++] = points[i].y;
	if (points[i].y != points[(i+n-1)%n].y) in_y[in_size++] = points[i].y;

	for (i = de_point; i != in_point; i = (i+1)%n)
		de_y[de_size++] = points[i].y;
	if (points[i].y != points[(i+n-1)%n].y) de_y[de_size++] = points[i].y;

	for (long i = 1; i < in_size-1; i++)
	{
		double px2 = points[(in_point+i)%n].x;
		long jd = (double*)bsearch(in_y+i, de_y, de_size-1, sizeof(double), de_search) - de_y;
		long j = (jd+de_point)%n;

		double px1 = points[j].x;
		if (points[(j+1)%n].y != points[j].y)
			px1 += (points[(j+1)%n].x-points[j].x)*(in_y[i]-points[j].y)/(points[(j+1)%n].y-points[j].y);

		if (px1/v < in_y[i]/u && in_y[i]/u < px2/v) goto second_strategy;
	}

	for (long i = 1; i < de_size-1; i++)
	{
		double px1 = points[(de_point+i)%n].x;
		long jd = (double*)bsearch(de_y+i, in_y, in_size-1, sizeof(double), in_search) - in_y;
		long j = (jd+in_point)%n;

		double px2 = points[j].x;
		if (points[(j+1)%n].y != points[j].y)
			px2 += (points[(j+1)%n].x-points[j].x)*(de_y[i]-points[j].y)/(points[(j+1)%n].y-points[j].y);

		if (px1/v < de_y[i]/u && de_y[i]/u < px2/v) goto second_strategy;
	}

	printf("%.9lf\n", w/u);
	return 0;

second_strategy:

	cur_time = MAX(points[in_point].x/v, in_y[0]/u);

	for (i = in_point; i != de_point; i = (i+1)%n)
	{
		double dx = points[(i+1)%n].x - points[i].x;
		double dy = points[(i+1)%n].y - points[i].y;

		if (dx <= 0) break;
		cur_time += MAX(dx/v, dy/u);
	}

	cur_time += (w - points[i].y)/u;

	printf("%.9lf\n", cur_time);
	return 0;
}
