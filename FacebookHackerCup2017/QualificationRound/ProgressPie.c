#include <stdio.h>
#include <math.h>

int main()
{
	int T;
	scanf("%d", &T);

	int tst = 0;

	while (T--)
	{
		int p, x, y;
		scanf("%d%d%d", &p, &x, &y);

		x -= 50; y -= 50;
		int black = 0;
		if (x == 0 && y > 0) black = p > 0;
		else if (x*x + y*y <= 2500) black = atan2(-x, -y) <= (p - 50) * 0.06283185307;
		printf("Case #%d: %s\n", ++tst, black ? "black" : "white");
	}
}
