#include <stdio.h>

long long calcul_cmmdc(long long x1, long long x2)
{
	while (x2 != 0) {
		long long r = x1 % x2;
		x1 = x2;
		x2 = r;
	}
	return x1;
}

long long calcul_cmmmc(long long x1, long long x2, long long cmmdc)
{
	return (x1 / cmmdc) * x2;
}

int main(void)
{
	int window;
	long long t[401], x[401];
	int i = 0, j = 0;
	scanf("%d", &window);
	scanf("%lld%lld", &t[i], &x[i]);
	i++;
	while (scanf("%lld%lld", &t[i], &x[i]) && t[i] != 0) {
		if ((t[i] - t[j]) <= window && t[i] != 0 && x[i] != 0) {
			long long cmmdc = calcul_cmmdc(x[i], x[j]);
			long long cmmmc = calcul_cmmmc(x[i], x[j], cmmdc);
			printf("%lld %lld\n", cmmmc, cmmdc);
			i++;
	} else {
		for (int k = j; k < i; k++) {
			x[k] = x[k + 1];
			t[k] = t[k + 1];
		}
		i--;
		j = 0;
		int copie_i = j + 1;
		while (copie_i <= i &&
			   (t[copie_i] - t[j]) <= window && t[copie_i] != 0 && t[j] != 0) {
			long long cmmdc = calcul_cmmdc(x[copie_i], x[j]);
			long long cmmmc = calcul_cmmmc(x[copie_i], x[j], cmmdc);
			printf("%lld %lld\n", cmmmc, cmmdc);
			copie_i++;
		}
		i++;
	}
}

	while (j < i) {
		j++;
		int copie_i = j + 1;
		while (copie_i <= i &&
			   (t[copie_i] - t[j]) <= window && t[copie_i] != 0 && t[j] != 0) {
			long long cmmdc = calcul_cmmdc(x[copie_i], x[j]);
			long long cmmmc = calcul_cmmmc(x[copie_i], x[j], cmmdc);
			printf("%lld %lld\n", cmmmc, cmmdc);
			copie_i++;
		}
	}
	return 0;
}
