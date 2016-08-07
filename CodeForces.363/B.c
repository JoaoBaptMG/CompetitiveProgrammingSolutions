#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int rwalls[n], cwalls[m], nwalls = 0;
	char depot[n][m+1];

	for (int j = 0; j < n; j++)
		scanf("%s", depot[j]);

	for (int j = 0; j < n; j++)
		rwalls[j] = 0;

	for (int i = 0; i < m; i++)
		cwalls[i] = 0;

	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			if (depot[j][i] == '*')
				rwalls[j]++, cwalls[i]++, nwalls++;

	int r, c;
	for (r = 0; r < n; r++)
		for (c = 0; c < m; c++)
			if (rwalls[r] + cwalls[c] - (depot[r][c] == '*') == nwalls)
				goto shortcut;

shortcut:
	puts(r < n && c < m ? "YES" : "NO");
	if (r < n && c < m) printf("%d %d\n", r+1, c+1);
}
