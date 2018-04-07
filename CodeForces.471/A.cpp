#include <cstdio>

int main()
{
	int hh, mm;
	int h, d, c, n;
	scanf("%d%d%d%d%d%d", &hh, &mm, &h, &d, &c, &n);
	
	int time = hh*60+mm;
	
	int bunsCostNow = c * ((h+n-1)/n);
	if (time >= 1200) printf("%lg\n", (double)bunsCostNow * 0.8);
	else
	{
		int diff = 1200 - time;
		int bunsCostThen_54 = c * ((h+diff*d + n-1)/n);
		
		if (4 * bunsCostThen_54 < 5 * bunsCostNow)
			printf("%lg\n", (double)bunsCostThen_54 * 0.8);
		else printf("%d\n", bunsCostNow);
	}
}
