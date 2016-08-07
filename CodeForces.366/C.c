#include <stdio.h>

struct { long app, time; } first_nots[300002];
long app_nots[300002];
long app_read[300002];

int main()
{
	long n, q;
	long unread = 0;
	long f_posted = 0;
	long f_read = 0;

	scanf("%ld%ld", &n, &q);

	for (long i = 1; i <= n; i++)
		app_nots[i] = app_read[i] = 0;

	for (long i = 0; i < q; i++)
	{
		int cmd;
		long v;

		scanf("%d%ld", &cmd, &v);

		if (cmd == 1)
		{
			first_nots[f_posted].app = v;
			first_nots[f_posted].time = app_nots[v]++;
			f_posted++, unread++;
		}
		else if (cmd == 2)
		{
			long dif = app_nots[v] - app_read[v];
			app_read[v] += dif;
			unread -= dif;
		}
		else if (cmd == 3)
		{
			for (; f_read < v; f_read++)
				if (app_read[first_nots[f_read].app] <= first_nots[f_read].time)
					app_read[first_nots[f_read].app]++, unread--;
		}

		printf("%ld\n", unread);
	}

	return 0;
}
