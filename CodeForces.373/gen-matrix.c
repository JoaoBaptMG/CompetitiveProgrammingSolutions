#include <stdio.h>

typedef struct { unsigned long long a, b, c, d; } matrix;

#define MOD 1000000007

void square(matrix *out)
{
	matrix m = { out->a, out->b, out->c, out->d };
	out->a = (m.a*m.a%MOD + m.b*m.c%MOD)%MOD;
	out->b = (m.a*m.b%MOD + m.b*m.d%MOD)%MOD;
	out->c = (m.c*m.a%MOD + m.d*m.c%MOD)%MOD;
	out->d = (m.c*m.b%MOD + m.d*m.d%MOD)%MOD;
}

int main()
{
	matrix mat = { 1, 1, 1, 0 };

	for (long i = 0; i < 32; i++)
	{
		printf("    { %lld, %lld, %lld, %lld },\n", mat.a, mat.b, mat.c, mat.d);
		square(&mat);
	}
}
