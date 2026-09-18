#include <stdio.h>

void citire(int *n, int *m, int *k, int a[1001][1001])
{
	scanf("%d%d", n, m);
	for (int i = 1; i <= *n; i++) {
		for (int j = 1; j <= *m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d", k);
}

void maxim_si_minim(int c1, int r1, int c2, int r2,
					int *maximc, int *maximr, int *minimr, int *minimc)
{
	if (c1 > c2) {
		*maximc = c1;
		*minimc = c2;
		} else {
			*maximc = c2;
			*minimc = c1;
		}
		if (r1 > r2) {
			*maximr = r1;
			*minimr = r2;
		} else {
			*maximr = r2;
			*minimr = r1;
		}
}

int main(void)
{
	int n, m, a[1001][1001], k, elicoptere[801];
	int valid = 0, r1, c1, r2, c2, s, nr = 0;
	citire(&n, &m, &k, a);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d%d%d", &r1, &c1, &r2, &c2, &s);
		if (r1 == r2 || c1 == c2) {
			printf("Elicopterul %d este pozitionat necorespunzator!\n", i);
			continue;
		}
		int patratele = 0, afectate = 0, cnt = 0;
		int maximc, maximr, minimr, minimc;
		maxim_si_minim(c1, r1, c2, r2, &maximc, &maximr, &minimr, &minimc);
		if (((maximr == r1 && maximc == c1) ||
		     (maximr == r2 && maximc == c2)) && s == -1) {
			for (int ii = minimr; ii <= maximr; ii++) {
				for (int j = minimc; j <= cnt + minimc; j++) {
					patratele++;
					if (a[ii][j] == 0)
						afectate++;
				}
				cnt++;
			}
		}
		if (((maximr == r1 && maximc == c1) ||
		     (maximr == r2 && maximc == c2)) && s == 1) {
			for (int ii = maximr; ii >= minimr; ii--) {
				for (int j = maximc; j >= maximc - cnt; j--) {
					patratele++;
					if (a[ii][j] == 0)
						afectate++;
				}
				cnt++;
			}
		}
		if (((maximr == r1 && maximc == c2) ||
		     (maximr == r2 && maximc == c1)) && s == -1) {
			for (int ii = minimr; ii <= maximr; ii++) {
				for (int j = maximc; j >= maximc - cnt; j--) {
					patratele++;
					if (a[ii][j] == 0)
						afectate++;
				}
				cnt++;
			}
		}
		if (((maximr == r1 && maximc == c2) ||
		     (maximr == r2 && maximc == c1)) && s == 1) {
			for (int ii = maximr; ii >= minimr; ii--) {
				for (int j = minimc; j <= minimc + cnt; j++) {
					patratele++;
					if (a[ii][j] == 0)
						afectate++;
				}
				cnt++;
			}
		}
		if (afectate == 0)
			valid++;
			else if (afectate > patratele / 2) {
				nr++;
				elicoptere[nr] = i;
			}
		}
		printf("%d\n%d\n", valid, nr);
		for (int i = 1; i <= nr; i++) {
			printf("%d ", elicoptere[i]);
		}
		return 0;
}
