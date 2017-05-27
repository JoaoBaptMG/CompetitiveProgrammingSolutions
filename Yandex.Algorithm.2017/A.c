#include <stdio.h>

long ids[200002];

int main()
{
    long n;
    scanf("%ld", &n);

    for (long i = 0; i < n; i++)
    {
        long v;
        scanf("%ld", &v);
        ids[v-1] = i;
    }

    long ans = 1;
    for (long i = 1; i < n; i++)
    {
        if (ids[i-1] > ids[i]) ans++;
    }

    printf("%ld\n", ans);
    return 0;
}
