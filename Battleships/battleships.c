#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//Tiepac Anduena-Maria 311CB
int ampl_nava_V1(int **mat1, int x, int y, int m,
				 int *gasit1, int *pers, int nr, int *e_nava)
{
	for (int j = x; j > x - nr; j--) {
		if (!mat1[j])
			mat1[j] = calloc(m + 1, sizeof(int));
		if (!mat1[j]) {
			printf("Eroare la alocarea mat2[j]");
			return 1;
		}
		if (mat1[j][y] != 0)
			*e_nava = 1;
	}
	for (int j = x; j > x - nr && *e_nava == 0; j--) {
		if (!mat1[j])
			mat1[j] = calloc(m + 1, sizeof(int));
		if (!mat1[j]) {
			printf("Eroare la alocarea mat2[j]");
		return 1;
		}
		mat1[j][y] = nr;
		(*gasit1)++;
	}
	if (*e_nava == 0) {
		mat1[x][y] += 20;
		*pers = 2;
	}
	return 0;
}

int ampl_nava_H1(int **mat1, int m, int x, int y,
				 int *e_nava, int *gasit1, int *pers, int nr)
{
	if (!mat1[x])
		mat1[x] = calloc(m + 1, sizeof(int));
	for (int j = y; j < y + nr; j++) {
		if (mat1[x][j] != 0)
			*e_nava = 1;
	}
	for (int j = y; j < y + nr && *e_nava == 0; j++) {
		(*gasit1)++;
		mat1[x][j] = nr;
	}
	if (*e_nava == 0) {
		mat1[x][y] += 10;
		*pers = 2;
	}
	return 0;
}

void barca_orizontala(int **mat2, int y, int x, int *gasit2, int nr)
{
	nr = nr % 10;
	for (int j = y; j < nr + y; j++) {
		if (mat2[x][j] > 0)
			(*gasit2)--;
		if (mat2[x][j] != -2)
			mat2[x][j] = -1;
	}
	if (nr == 1) {
		printf("Jucatorul 1 a distrus o nava Albacore ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 2) {
		printf("Jucatorul 1 a distrus o nava Laffey plasata ");
		printf("intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 3) {
		printf("Jucatorul 1 a distrus o nava Belfast plasata ");
		printf("intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 4) {
		printf("Jucatorul 1 a distrus o nava Yamato plasata ");
		printf("intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 5) {
		printf("Jucatorul 1 a distrus o nava Shinano plasata ");
		printf("intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
}

int ampl_nava_H2(int **mat2, int m, int x, int y, int nr,
				 int *e_nava, int *pers, int *gasit2)
{
	if (!mat2[x])
		mat2[x] = calloc(m + 1, sizeof(int));
	if (!mat2[x]) {
		printf("Eroare la alocarea mat2[x]");
		return 1;
	}
	for (int j = y; j < y + nr; j++)
		if (mat2[x][j] != 0)
			*e_nava = 1;
	for (int j = y; j < y + nr && *e_nava == 0; j++) {
		(*gasit2)++;
		mat2[x][j] = nr;
	}
	if (*e_nava == 0) {
		*pers = 1;
		mat2[x][y] += 10;
	}
	return 0;
}

int ampl_nava_V2(int **mat2, int x, int m, int y, int *pers,
				 int *e_nava, int *gasit2, int nr)
{
	for (int j = x; j > x - nr; j--) {
		if (!mat2[j])
			mat2[j] = calloc(m + 1, sizeof(int));
		if (!mat2[j]) {
			printf("Eroare la alocarea mat2[j]");
			return 1;
		}
		if (mat2[j][y] != 0)
			*e_nava = 1;
	}
		for (int j = x; j > x - nr && *e_nava == 0; j--) {
			if (!mat2[j])
				mat2[j] = calloc(m + 1, sizeof(int));
			if (!mat2[j]) {
				printf("Eroare la alocarea mat2[j]");
				return 1;
			}
			mat2[j][y] = nr;
		(*gasit2)++;
		}
	if (*e_nava == 0) {
		mat2[x][y] += 20;
		*pers = 1;
	}
	return 0;
}

void barca_verticala(int **mat2, int nr, int y, int x, int *gasit2)
{
	nr = nr % 10;
	for (int j = x; j > x - nr; j--) {
		if (mat2[j][y] > 0)
			(*gasit2)--;
		if (mat2[j][y] != -2)
			mat2[j][y] = -1;
	}
	if (nr == 1) {
		printf("Jucatorul 1 a distrus o nava Albacore ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 2) {
		printf("Jucatorul 1 a distrus o nava Laffey ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 3) {
		printf("Jucatorul 1 a distrus o nava Belfast ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 4) {
		printf("Jucatorul 1 a distrus o nava Yamato ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 5) {
		printf("Jucatorul 1 a distrus o nava Shinano ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
}

void barca_orizontala2(int **mat1, int nr, int x, int y, int *gasit1)
{
	nr = nr % 10;
	for (int j = y; j < nr + y; j++) {
		if (mat1[x][j] > 0)
			(*gasit1)--;
		if (mat1[x][j] != -2)
			mat1[x][j] = -1;
	}
	if (nr == 1) {
		printf("Jucatorul 2 a distrus o nava Albacore ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 2) {
		printf("Jucatorul 2 a distrus o nava Laffey ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 3) {
		printf("Jucatorul 2 a distrus o nava Belfast ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 4) {
		printf("Jucatorul 2 a distrus o nava Yamato ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
	if (nr == 5) {
		printf("Jucatorul 2 a distrus o nava Shinano ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x, y + nr - 1);
	}
}

void barca_verticala2(int **mat1, int nr, int x, int y, int *gasit1)
{
	nr = nr % 10;
	for (int j = x; j > x - nr; j--) {
		if (mat1[j][y] > 0)
			(*gasit1)--;
		if (mat1[j][y] != -2)
			mat1[j][y] = -1;
	}
	if (nr == 1) {
		printf("Jucatorul 2 a distrus o nava Albacore ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 2) {
		printf("Jucatorul 2 a distrus o nava Laffey ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 3) {
		printf("Jucatorul 2 a distrus o nava Belfast ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 4) {
		printf("Jucatorul 2 a distrus o nava Yamato ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
	if (nr == 5) {
		printf("Jucatorul 2 a distrus o nava Shinano ");
		printf("plasata intre coordonatele ");
		printf("(%d, %d) si (%d, %d).\n", x, y, x - nr + 1, y);
	}
}

int calcul_k(int k, int m, int n)
{
	k = 0;
	k += (n * m) / 20;
	k += (n * m) / 30;
	k += (n * m) / 40;
	k += (n * m) / 55;
	k += (n * m) / 70;
	k = k * 2;
	return k;
}

int determinare_barca(int nr, char nava)
{
	if (nava == 'A') {
		nr = 1;
	}
	if (nava == 'L') {
		nr = 2;
	}
	if (nava == 'B') {
		nr = 3;
	}
	if (nava == 'Y') {
		nr = 4;
	}
	if (nava == 'S') {
		nr = 5;
	}
	return nr;
}

void afisare_mesaj1(int x, int y, char nava)
{
	if (nava == 'A') {
		printf("Nava Albacore nu poate fi amplasata orizontal");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'L') {
		printf("Nava Laffey nu poate fi amplasata orizontal");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'B') {
		printf("Nava Belfast nu poate fi amplasata orizontal");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'Y') {
		printf("Nava Yamato nu poate fi amplasata orizontal");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'S') {
		printf("Nava Shinano nu poate fi amplasata orizontal");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
}

void afisare_mesaj2(int x, int y, char nava)
{
	if (nava == 'A') {
		printf("Nava Albacore nu poate fi amplasata vertical");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'L') {
		printf("Nava Laffey nu poate fi amplasata vertical");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'B') {
		printf("Nava Belfast nu poate fi amplasata vertical");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'Y') {
		printf("Nava Yamato nu poate fi amplasata vertical");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
	if (nava == 'S') {
		printf("Nava Shinano nu poate fi amplasata vertical");
		printf(" la coordonatele (%d, %d).\n", x, y);
	}
}

void afisare_matrice(int **mat1, int **mat2, int m, int n)
{
	for (int i = 1; i <= n; i++) {
		if (mat1[i]) {
			for (int j = 1; j <= m; j++) {
				if (mat1[i][j] < 9)
					printf("%d ", mat1[i][j]);
				else
					printf("%d ", mat1[i][j] % 10);
			}
		} else {
			for (int j = 1; j <= m; j++)
				printf("0 ");
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		if (mat2[i]) {
			for (int j = 1; j <= m; j++)
				if (mat2[i][j] < 9)
					printf("%d ", mat2[i][j]);
				else
					printf("%d ", mat2[i][j] % 10);
		} else {
			for (int j = 1; j <= m; j++)
				printf("0 ");
		}
		printf("\n");
	}
}

void ratare_lovitura1(int **mat2, int x, int y, int m)
{
	if (!mat2[x]) {
		mat2[x] = calloc(m + 1, sizeof(int));
	}
	mat2[x][y] = -2;
	printf("Jucatorul 1 a ratat o ");
	printf("lovitura la coordonatele (%d, %d).\n", x, y);
}

void lovitura_nava1(int **mat2, int x, int y, int *gasit2)
{
	if (mat2[x][y] == 1) {
		printf("Jucatorul 1 a lovit o nava Albacore ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat2[x][y] == 2) {
		printf("Jucatorul 1 a lovit o nava Laffey ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat2[x][y] == 3) {
		printf("Jucatorul 1 a lovit o nava Belfast ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat2[x][y] == 4) {
		printf("Jucatorul 1 a lovit o nava Yamato ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat2[x][y] == 5) {
		printf("Jucatorul 1 a lovit o nava Shinano ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	mat2[x][y] = -2;
	(*gasit2)--;
}

void lovitura_nava2(int **mat1, int x, int y, int *gasit1)
{
	if (mat1[x][y] == 1) {
		printf("Jucatorul 2 a lovit o nava Albacore ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat1[x][y] == 2) {
		printf("Jucatorul 2 a lovit o nava Laffey ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat1[x][y] == 3) {
		printf("Jucatorul 2 a lovit o nava Belfast ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat1[x][y] == 4) {
		printf("Jucatorul 2 a lovit o nava Yamato ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	if (mat1[x][y] == 5) {
		printf("Jucatorul 2 a lovit o nava Shinano ");
		printf("la coordonatele (%d, %d).\n", x, y);
	}
	mat1[x][y] = -2;
	(*gasit1)--;
}

void ratare_lovitura2(int **mat1, int m, int x, int y)
{
	if (!mat1[x]) {
		mat1[x] = calloc(m + 1, sizeof(int));
	}
	mat1[x][y] = -2;
	printf("Jucatorul 2 a ratat o lovitura la ");
	printf("coordonatele (%d, %d).\n", x, y);
}

void decidere_castigator(int gasit1, int gasit2, int *castig)
{
	if (gasit1 <= 0) {
		printf("Jucatorul 2 a castigat.\n");
		*castig = 1;
	}
	if (gasit2 <= 0) {
		printf("Jucatorul 1 a castigat.\n");
		*castig = 1;
	}
}

void eliberare_memorie(int **mat1, int **mat2, int n)
{
	for (int i = 1; i <= n; i++) {
		if (mat1[i])
			free(mat1[i]);
	}
	free(mat1);
	for (int i = 1; i <= n; i++) {
		if (mat2[i])
			free(mat2[i]);
	}
	free(mat2);
}

void amplasare_H(int **mat1, int **mat2, int m, int x, int y,
				 int nr, int *pers, int *e_nava, int *gasit1, int *gasit2)
{
	if (*pers == 1) {
		ampl_nava_H1(mat1, m, x, y, e_nava, gasit1, pers, nr);
	} else {
		ampl_nava_H2(mat2, m, x, y, nr, e_nava, pers, gasit2);
	}
}

void amplasare_V(int **mat1, int **mat2, int m, int x, int y,
				 int nr, int *pers, int *e_nava, int *gasit1, int *gasit2)
{
	if (*pers == 1) {
		ampl_nava_V1(mat1, x, y, m, gasit1, pers, nr, e_nava);
	} else {
		ampl_nava_V2(mat2, x, m, y, pers, e_nava, gasit2, nr);
	}
}

void alegere_castigator(int castig, int **mat2, int **mat1, int x,
						int y, int pers, int m, int *gasit1, int *gasit2,
						double *nr_lovituri_nimerite1,
						double *nr_lovituri_nimerite2,
						double *nr_lovituri_totale1,
						double *nr_lovituri_totale2, int meci)
{
	while (castig == 0) {
		scanf("%d%d", &x, &y);
		if (pers == 1) {
			pers = 2;
			if (!mat2[x] || mat2[x][y] == 0 || mat2[x][y] == -1) {
				nr_lovituri_totale1[meci]++;
				ratare_lovitura1(mat2, x, y, m);
			} else if (mat2[x][y] == -2) {
				nr_lovituri_totale1[meci]++;
				printf("Coordonatele (%d, %d) au fost ", x, y);
				printf("deja atacate de jucatorul 1.\n");
			} else {
				nr_lovituri_nimerite1[meci]++;
				nr_lovituri_totale1[meci]++;
				int nr = mat2[x][y];
				if (nr < 9) {
					lovitura_nava1(mat2, x, y, gasit2);
					continue;
				}
				if (nr > 10 && nr < 20) {
					barca_orizontala(mat2, y, x, gasit2, nr);
				}
				if (nr > 20) {
					barca_verticala(mat2, nr, y, x, gasit2);
				}
			}
				if (mat2[x])
					mat2[x][y] = -2;
		} else {
			pers = 1;
			if (!mat1[x] || mat1[x][y] == 0 || mat1[x][y] == -1) {
				nr_lovituri_totale2[meci]++;
				ratare_lovitura2(mat1, m, x, y);
			} else if (mat1[x][y] == -2) {
				nr_lovituri_totale2[meci]++;
				printf("Coordonatele (%d, %d) au fost deja ", x, y);
				printf("atacate de jucatorul 2.\n");
			} else {
				nr_lovituri_nimerite2[meci]++;
				nr_lovituri_totale2[meci]++;
				int nr = mat1[x][y];
				if (nr < 9) {
					lovitura_nava2(mat1, x, y, gasit1);
					continue;
				}
				if (nr > 10 && nr < 20) {
					barca_orizontala2(mat1, nr, x, y, gasit1);
				}
				if (nr > 20) {
					barca_verticala2(mat1, nr, x, y, gasit1);
				}
			}
			if (mat1[x])
				mat1[x][y] = -2;
		}
		decidere_castigator(*gasit1, *gasit2, &castig);

	}
}

double *copie_acc_meci, *copie_nr_nave;

int compara1(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;
	if (copie_nr_nave[x] * 100 - copie_acc_meci[x] <
		copie_nr_nave[y] * 100 - copie_acc_meci[y])
		return 1;
	if (copie_nr_nave[x] * 100 - copie_acc_meci[x] >
		copie_nr_nave[y] * 100 - copie_acc_meci[y])
		return -1;
	return 0;
}

int compara2(const void *a, const void *b)
{
	int x = *(const int *)a;
	int y = *(const int *)b;
	if (copie_acc_meci[x] > copie_acc_meci[y])
		return 1;
	if (copie_acc_meci[x] < copie_acc_meci[y])
		return -1;
	return 0;
}

void calcul_MAX_U(double procent, double acuratete, int nr_meci,
				  double *nr_lovituri_totale1,
				  double *nr_lovituri_nimerite1, char *rasp,
				  int poz, char *cheie)
{
	if (procent >= acuratete) {
		if (cheie[0] == '-')
			printf("0");
		rasp[poz] = '.';
		rasp[poz + 1] = '0';
		rasp[poz + 2] = '\0';
	} else {
		for (double i = nr_lovituri_totale1[nr_meci]
			 - nr_lovituri_nimerite1[nr_meci];
			 i <= nr_lovituri_totale1[nr_meci]; i++) {
			double x = (int)(((nr_lovituri_totale1[nr_meci]
			- i) * 10000) / nr_lovituri_totale1[nr_meci])
			/ 100.0;
			if (x < procent) {
				if (cheie[0] == '-')
					printf("%.0f", i -
						   (nr_lovituri_totale1[nr_meci]
						   - nr_lovituri_nimerite1[nr_meci])
						   - 1);
				int numar = i -
					   (nr_lovituri_totale1[nr_meci]
					   - nr_lovituri_nimerite1[nr_meci])
					   - 1;
				int copie_nr = numar, cif = 0;
				while (copie_nr > 0) {
					cif++;
					copie_nr /= 10;
				}
				rasp[poz] = '.';
				for (int h = 1; h <= cif; h++) {
					rasp[poz + cif - h + 1] = numar % 10 + '0';
					numar /= 10;
				}
				rasp[poz + cif + 1] = '\0';
				break;
			}
		}
	}
}

void cerere_MIN_T(int jocuri, double procent, double total,
				  double copie_total, double total_nave,
				  double *acc_meci, int *index, double *nr_nave,
				  char *rasp, int poz, char *cheie)
{
	qsort(index + 1, jocuri, sizeof(int), compara1);
	if (total >= procent) {
		if (cheie[0] == '-')
			printf("0");
		rasp[poz] = '.';
		rasp[poz + 1] = '0';
		rasp[poz + 2] = '\0';
	} else {
		for (int i = 1; i <= jocuri; i++) {
			copie_total = copie_total - acc_meci[index[i]];
			copie_total += 100.00 * nr_nave[index[i]];
			if (copie_total / total_nave >= procent) {
				if (cheie[0] == '-')
					printf("%d", i);
				int numar = i;
				int copie_nr = numar, cif = 0;
				while (copie_nr > 0) {
					cif++;
					copie_nr /= 10;
				}
				rasp[poz] = '.';
				for (int h = 1; h <= cif; h++) {
					rasp[poz + cif - h + 1] = numar % 10 + '0';
					numar /= 10;
				}
				rasp[poz + cif + 1] = '\0';
				break;
			}
		}
	}
}

void calcul_MAX_T(double procent, double acuratete,
				  double *nr_lovituri_totale2,
				  double *nr_lovituri_nimerite2, int nr_meci,
				char *rasp, int poz, char *cheie)
{
	if (procent >= acuratete) {
		if (cheie[0] == '-')
			printf("0");
		rasp[poz] = '.';
		rasp[poz + 1] = '0';
		rasp[poz + 2] = '\0';
	} else {
		for (double i = nr_lovituri_totale2[nr_meci]
			 - nr_lovituri_nimerite2[nr_meci];
			 i <= nr_lovituri_totale2[nr_meci]; i++) {
			double x = (int)(((nr_lovituri_totale2[nr_meci]
			- i) * 10000) / nr_lovituri_totale2[nr_meci])
			/ 100.0;
			if (x < procent) {
				if (cheie[0] == '-')
					printf("%.0f", i -
					(nr_lovituri_totale2[nr_meci]
					- nr_lovituri_nimerite2[nr_meci])
					- 1);
				int numar = i -
							(nr_lovituri_totale2[nr_meci]
							- nr_lovituri_nimerite2[nr_meci])
							- 1;
				int copie_nr = numar, cif = 0;
				while (copie_nr > 0) {
					cif++;
					copie_nr /= 10;
				}
				rasp[poz] = '.';
				for (int h = 1; h <= cif; h++) {
					rasp[poz + cif - h + 1] = numar % 10 + '0';
					numar /= 10;
				}
				rasp[poz + cif + 1] = '\0';
				break;
			}
		}
	}
}

void calcul_min_T(int *index, int jocuri, double total,
				  double procent, double copie_total, double *nr_nave,
				  double total_nave, double *acc_meci, char *rasp,
				  int poz, char *cheie)
{
	qsort(index + 1, jocuri, sizeof(int), compara1);
	if (total >= procent) {
		if (cheie[0] == '-')
			printf("0");
		rasp[poz] = '.';
		rasp[poz + 1] = '0';
		rasp[poz + 2] = '\0';
	} else {
		for (int i = 1; i <= jocuri; i++) {
			copie_total = copie_total - acc_meci[index[i]];
			copie_total += 100.00 * nr_nave[index[i]];
			if (copie_total / total_nave >= procent) {
				if (cheie[0] == '-')
					printf("%d", i);
				int numar = i;
				int copie_nr = numar, cif = 0;
				if (copie_nr == 0) {
					rasp[poz] = '.';
					rasp[poz + 1] = '0';
					rasp[poz + 2] = '\0';
				}
				while (copie_nr > 0) {
					cif++;
					copie_nr /= 10;
				}
				if (cif > 0)
					rasp[poz] = '.';
				for (int h = 1; h <= cif; h++) {
					rasp[poz + cif - h + 1] = numar % 10 + '0';
					numar /= 10;
				}
				if (cif > 0)
					rasp[poz + cif + 1] = '\0';
				break;
			}
		}
	}
}

double calcul_procent(double procent, int p, char *cerere)
{
	for (int i = 10; i >= 5; i--) {
		if (cerere[i] != '.') {
			procent += p * (cerere[i] - '0');
			p *= 10;
		}
	}
	procent /= 100;
	return procent;
}

int calcul_nr_meci(int nr_meci, int p, char *cerere)
{
	for (int i = 4; i >= 2; i--) {
		nr_meci += p * (cerere[i] - '0');
		p *= 10;
	}
	return nr_meci;
}

void creare_rasp(char *rasp, int numar, int *poz)
{
	int copie_nr = numar, cif = 0;
	if (copie_nr == 0) {
		rasp[*poz] = '.';
		rasp[*poz + 1] = '0';
		rasp[*poz + 2] = '\0';
	}
	while (copie_nr > 0) {
		cif++;
		copie_nr /= 10;
	}
	if (cif > 0)
		rasp[*poz] = '.';
	for (int h = 1; h <= cif; h++) {
		rasp[*poz + cif - h + 1] = numar % 10 + '0';
		numar /= 10;
	}
	if (cif > 0)
		rasp[*poz + cif + 1] = '\0';
}

void calcul_MIN_U(double *nr_lovituri_nimerite1, double *nr_lovituri_totale1,
				  double procent, char *cheie, int *poz,
				  char *rasp, int nr_meci)
{
	for (double i = nr_lovituri_nimerite1[nr_meci];
		 i <= nr_lovituri_totale1[nr_meci]; i++) {
		double x = (int)((i * 10000) /
		nr_lovituri_totale1[nr_meci]) / 100.0;
		if (x >= procent) {
			if (cheie[0] == '-')
				printf("%.0f", i -
					   nr_lovituri_nimerite1[nr_meci]);
			int numar = i - nr_lovituri_nimerite1[nr_meci];
			creare_rasp(rasp, numar, poz);
			break;
		}
	}
}

void calcul_U(int nr_meci, char *cerere, double procent,
			  double *nr_lovituri_nimerite1,
			  double *nr_lovituri_totale1, char *rasp, int *poz, char *cheie)
{
	double acuratete = (int)((nr_lovituri_nimerite1[nr_meci]
	* 10000) / nr_lovituri_totale1[nr_meci]) / 100.0;
	if (acuratete < 10) {
		if (cheie[0] == '-')
			printf("00%.2f.", acuratete);
		int copie_acuratete = acuratete * 1000;
		if (copie_acuratete % 10 >= 5) {
			copie_acuratete /= 10;
			copie_acuratete++;
		} else
			copie_acuratete /= 10;
		rasp[*poz + 5] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 4] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 3] = '.';
		rasp[*poz + 2] = copie_acuratete % 10 + '0';
		rasp[*poz + 1] = '0';
		rasp[*poz] = '0';
		*poz += 6;
	} else if (acuratete < 100) {
		if (cheie[0] == '-')
			printf("0%.2f.", acuratete);
		int copie_acuratete = acuratete * 1000;
		if (copie_acuratete % 10 >= 5) {
			copie_acuratete /= 10;
			copie_acuratete++;
		} else
			copie_acuratete /= 10;
		rasp[*poz + 5] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 4] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 3] = '.';
		rasp[*poz + 2] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 1] = copie_acuratete % 10 + '0';
		rasp[*poz] = '0';
		*poz += 6;
	} else {
		if (cheie[0] == '-')
			printf("%.2f.", acuratete);
		int copie_acuratete = acuratete * 1000;
		if (copie_acuratete % 10 >= 5) {
			copie_acuratete /= 10;
			copie_acuratete++;
		} else
			copie_acuratete /= 10;
		rasp[*poz + 5] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 4] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 3] = '.';
		rasp[*poz + 2] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz + 1] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[*poz] = copie_acuratete % 10 + '0';
		*poz += 6;
	}
	if (cerere[12] == 'I') {
		calcul_MIN_U(nr_lovituri_nimerite1,
					 nr_lovituri_totale1, procent,
					 cheie, poz, rasp, nr_meci);
	} else {
		calcul_MAX_U(procent, acuratete, nr_meci,
					 nr_lovituri_totale1, nr_lovituri_nimerite1,
					 rasp, *poz, cheie);
	}
}

void afisare_si_creare_rasp(double total, char *cheie, char *rasp, int *poz)
{
	if (total < 10) {
		if (cheie[0] == '-')
			printf("00%.2f.", total);
		int copie_total = total * 1000;
		if (copie_total % 10 >= 5) {
			copie_total /= 10;
			copie_total++;
		} else
			copie_total /= 10;
		rasp[*poz + 5] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 4] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 3] = '.';
		rasp[*poz + 2] = copie_total % 10 + '0';
		rasp[*poz + 1] = '0';
		rasp[*poz] = '0';
		*poz += 6;
	} else if (total < 100) {
		if (cheie[0] == '-')
			printf("0%.2f.", total);
		int copie_total = total * 1000;
		if (copie_total % 10 >= 5) {
			copie_total /= 10;
			copie_total++;
		} else
			copie_total /= 10;
		rasp[*poz + 5] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 4] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 3] = '.';
		rasp[*poz + 2] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 1] = copie_total % 10 + '0';
		rasp[*poz] = '0';
		*poz += 6;
	} else {
		if (cheie[0] == '-')
			printf("%.2f.", total);
		int copie_total = total * 1000;
		if (copie_total % 10 >= 5) {
			copie_total /= 10;
			copie_total++;
		} else
			copie_total /= 10;
		rasp[*poz + 5] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 4] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 3] = '.';
		rasp[*poz + 2] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz + 1] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[*poz] = copie_total % 10 + '0';
		*poz += 6;
	}
}

void calcul_T(int jocuri, double procent, double *nr_nave, int *index,
			  double *acc_meci, char *cerere, double *nr_lovituri_totale1,
			  double *nr_lovituri_nimerite1, char *rasp, int *poz, char *cheie)
{
	double total = 0, total_nave = 0, copie_total = 0;
	for (int i = 1; i <= jocuri; i++) {
		double acuratete = (int)((nr_lovituri_nimerite1[i]
		* 10000) / nr_lovituri_totale1[i]) / 100.0;
		total += nr_nave[i] * acuratete;
		copie_total += nr_nave[i] * (nr_lovituri_nimerite1[i]
		* 100.00 / nr_lovituri_totale1[i]);
		total_nave += nr_nave[i];
		acc_meci[i] = nr_nave[i] * (nr_lovituri_nimerite1[i]
		* 100.00 / nr_lovituri_totale1[i]);
	}
	total /= total_nave;
	afisare_si_creare_rasp(total, cheie, rasp, poz);
	if (cerere[12] == 'I') {
		cerere_MIN_T(jocuri, procent, total, copie_total,
					 total_nave, acc_meci, index, nr_nave, rasp, *poz, cheie);
	} else {
		qsort(index + 1, jocuri, sizeof(int), compara2);
		for (int i = 1; i <= jocuri; i++) {
			copie_total -= acc_meci[index[i]];
			if (copie_total / total_nave < procent) {
				if (cheie[0] == '-')
					printf("%d", i - 1);
				int numar = i - 1;
				int copie_nr = numar, cif = 0;
				if (copie_nr == 0) {
					rasp[*poz] = '.';
					rasp[*poz + 1] = '0';
					rasp[*poz + 2] = '\0';
				}
				while (copie_nr > 0) {
					cif++;
					copie_nr /= 10;
				}
				if (cif > 0)
					rasp[*poz] = '.';
				for (int h = 1; h <= cif; h++) {
					rasp[*poz + cif - h + 1] = numar % 10 + '0';
					numar /= 10;
				}
				if (cif > 0)
					rasp[*poz + cif + 1] = '\0';
				break;
			}
		}
	}
}

void calcul_min_U(int *index, int jocuri, double copie_total,
				  double *acc_meci, double procent, double total_nave,
				  char *cheie, char *rasp, int poz)
{
	qsort(index + 1, jocuri, sizeof(int), compara2);
	for (int i = 1; i <= jocuri; i++) {
		copie_total -= acc_meci[index[i]];
		if (copie_total / total_nave < procent) {
			if (cheie[0] == '-')
				printf("%d", i - 1);
			int numar = i - 1;
			int copie_nr = numar, cif = 0;
			if (copie_nr == 0) {
				rasp[poz] = '.';
				rasp[poz + 1] = '0';
				rasp[poz + 2] = '\0';
			}
			while (copie_nr > 0) {
				cif++;
				copie_nr /= 10;
			}
			if (cif > 0)
				rasp[poz] = '.';
			for (int h = 1; h <= cif; h++) {
				rasp[poz + cif - h + 1] = numar % 10 + '0';
				numar /= 10;
			}
			if (cif > 0)
				rasp[poz + cif + 1] = '\0';
			break;
		}
	}
}

void calcul_min(double *nr_lovituri_nimerite2,
				double *nr_lovituri_totale2, int nr_meci,
				double procent, char *cheie, char *rasp, int poz)
{
	for (double i = nr_lovituri_nimerite2[nr_meci];
		 i <= nr_lovituri_totale2[nr_meci]; i++) {
		double x = (int)((i * 10000) /
		nr_lovituri_totale2[nr_meci]) / 100.0;
		if (x >= procent) {
			if (cheie[0] == '-')
				printf("%.0f", i -
					   nr_lovituri_nimerite2[nr_meci]);
			int numar = i - nr_lovituri_nimerite2[nr_meci];
			int copie_nr = numar, cif = 0;
			if (copie_nr == 0) {
				rasp[poz] = '.';
				rasp[poz + 1] = '0';
				rasp[poz + 2] = '\0';
			}
			while (copie_nr > 0) {
				cif++;
				copie_nr /= 10;
			}
			if (cif > 0)
				rasp[poz] = '.';
			for (int h = 1; h <= cif; h++) {
				rasp[poz + cif - h + 1] = numar % 10 + '0';
				numar /= 10;
			}
			if (cif > 0)
				rasp[poz + cif + 1] = '\0';
			break;
		}
	}
}

void calcul_U_O(double *nr_lovituri_nimerite2,
				double *nr_lovituri_totale2, char *cheie,
				char *rasp, int poz, char *cerere, double procent,
				int nr_meci)
{
	double acuratete = (int)((nr_lovituri_nimerite2[nr_meci]
	* 10000) / nr_lovituri_totale2[nr_meci]) / 100.0;
	if (acuratete < 10) {
		if (cheie[0] == '-')
			printf("00%.2f.", acuratete);
		int copie_acuratete = acuratete * 1000;
		if (copie_acuratete % 10 >= 5) {
			copie_acuratete /= 10;
			copie_acuratete++;
		} else
			copie_acuratete /= 10;
		rasp[poz + 5] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 4] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 3] = '.';
		rasp[poz + 2] = copie_acuratete % 10 + '0';
		rasp[poz + 1] = '0';
		rasp[poz] = '0';
		poz += 6;
	} else if (acuratete < 100) {
		if (cheie[0] == '-')
			printf("0%.2f.", acuratete);
		int copie_acuratete = acuratete * 1000;
		if (copie_acuratete % 10 >= 5) {
			copie_acuratete /= 10;
			copie_acuratete++;
		} else
			copie_acuratete /= 10;
		rasp[poz + 5] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 4] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 3] = '.';
		rasp[poz + 2] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 1] = copie_acuratete + '0';
		rasp[poz] = '0';
		poz += 6;
	} else {
		if (cheie[0] == '-')
			printf("%.2f.", acuratete);
		int copie_acuratete = acuratete * 1000;
		if (copie_acuratete % 10 >= 5) {
			copie_acuratete /= 10;
			copie_acuratete++;
		} else
			copie_acuratete /= 10;
		rasp[poz + 5] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 4] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 3] = '.';
		rasp[poz + 2] = copie_acuratete % 10 + '0';
		copie_acuratete /= 10;
		rasp[poz + 1] = copie_acuratete % 10  + '0';
		copie_acuratete /= 10;
		rasp[poz] = copie_acuratete + '0';
		poz += 6;
	}
	if (cerere[12] == 'I') {
		calcul_min(nr_lovituri_nimerite2, nr_lovituri_totale2,
				   nr_meci, procent, cheie, rasp, poz);
	} else {
		calcul_MAX_T(procent, acuratete,
					 nr_lovituri_totale2, nr_lovituri_nimerite2,
					 nr_meci, rasp, poz, cheie);
	}
}

int calcul_rsp(int poz, int copie_total, char *rasp)
{
	rasp[poz + 5] = copie_total % 10 + '0';
	copie_total /= 10;
	rasp[poz + 4] = copie_total % 10 + '0';
	copie_total /= 10;
	rasp[poz + 3] = '.';
	rasp[poz + 2] = copie_total % 10 + '0';
	copie_total /= 10;
	rasp[poz + 1] = copie_total + '0';
	rasp[poz] = '0';
	poz += 6;
	return poz;
}

void calcul_T_O(int jocuri, double *nr_lovituri_nimerite2,
				double *nr_lovituri_totale2, double *nr_nave,
				double *acc_meci, char *cheie, char *rasp, int poz,
				char *cerere, int *index, double procent)
{
	double total = 0, total_nave = 0, copie_total = 0;
	for (int i = 1; i <= jocuri; i++) {
		double acuratete = (int)((nr_lovituri_nimerite2[i]
		* 10000) / nr_lovituri_totale2[i]) / 100.0;
		total += nr_nave[i] * acuratete;
		copie_total += nr_nave[i] * (nr_lovituri_nimerite2[i]
		* 100.00 / nr_lovituri_totale2[i]);
		total_nave += nr_nave[i];
		acc_meci[i] = nr_nave[i] * (nr_lovituri_nimerite2[i]
		* 100.00 / nr_lovituri_totale2[i]);
	}
	total /= total_nave;
	if (total < 10) {
		if (cheie[0] == '-')
			printf("00%.2f.", total);
		int copie_total = total * 1000;
		if (copie_total % 10 >= 5) {
			copie_total /= 10;
			copie_total++;
		} else
			copie_total /= 10;
		rasp[poz + 5] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[poz + 4] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[poz + 3] = '.';
		rasp[poz + 2] = copie_total % 10 + '0';
		rasp[poz + 1] = '0';
		rasp[poz] = '0';
		poz += 6;
	} else if (total < 100) {
		if (cheie[0] == '-')
			printf("0%.2f.", total);
		int copie_total = total * 1000;
		if (copie_total % 10 >= 5) {
			copie_total /= 10;
			copie_total++;
		} else
			copie_total /= 10;
		poz = calcul_rsp(poz, copie_total, rasp);
	} else {
		if (cheie[0] == '-')
			printf("%.2f.", total);
		int copie_total = total * 1000;
		if (copie_total % 10 >= 5) {
			copie_total /= 10;
			copie_total++;
		} else
			copie_total /= 10;
		rasp[poz + 5] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[poz + 4] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[poz + 3] = '.';
		rasp[poz + 2] = copie_total % 10 + '0';
		copie_total /= 10;
		rasp[poz + 1] = copie_total % 10  + '0';
		copie_total /= 10;
		rasp[poz] = copie_total;
		poz += 6;
	}
		if (cerere[12] == 'I') {
			calcul_min_T(index, jocuri, total, procent,
						 copie_total, nr_nave, total_nave,
						 acc_meci, rasp, poz, cheie);
		} else {
			calcul_min_U(index, jocuri, copie_total,
						 acc_meci, procent, total_nave, cheie, rasp, poz);
		}
}

void statistics(int *index, int jocuri, char cerere[15],
				double *nr_lovituri_nimerite1, double *nr_lovituri_totale1,
				double *nr_nave, double *acc_meci, double *nr_lovituri_totale2,
				double *nr_lovituri_nimerite2, char *rasp, char *cheie)
{
	int poz = 0;
	double procent = calcul_procent(0, 1, cerere);
	int nr_meci = calcul_nr_meci(0, 1, cerere);
	if (cerere[0] == 'O') {
		if (cerere[1] == 'U') {
			calcul_U(nr_meci, cerere, procent,
					 nr_lovituri_nimerite1, nr_lovituri_totale1,
					 rasp, &poz, cheie);
		} else {
			calcul_T(jocuri, procent, nr_nave, index, acc_meci,
					 cerere, nr_lovituri_totale1,
					 nr_lovituri_nimerite1, rasp, &poz, cheie);
		}
	} else {
		if (cerere[1] == 'U') {
			calcul_U_O(nr_lovituri_nimerite2, nr_lovituri_totale2, cheie,
					   rasp, poz, cerere, procent, nr_meci);
		} else {
			calcul_T_O(jocuri, nr_lovituri_nimerite2, nr_lovituri_totale2,
					   nr_nave, acc_meci, cheie, rasp,
					   poz, cerere, index, procent);
		}
	}
}

void creare_matrice_cheie(int cnt,
						  char *cheie, int **mat_cheie)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cheie[cnt] >= 'A' && cheie[cnt] <= 'Z') {
				mat_cheie[i][j] = 10 + (cheie[cnt] - 'A');
			} else if (cheie[cnt] == '.')
				mat_cheie[i][j] = 36;
			else
				mat_cheie[i][j] = cheie[cnt] - '0';
			cnt++;
		}
	}
}

void codificare(int len_msj, char *msj, int **mat_msj,
				int **mat_cheie, char *cheie, int ok)
{
	for (int z = 0; z < len_msj; z += 3) {
		if (len_msj - z >= 3) {
			for (int i = z; i < 3 + z; i++) {
				if (msj[i] >= 'A' && msj[i] <= 'Z') {
					mat_msj[i - z][0] = 10 + (msj[i] - 'A');
				} else if (msj[i] == '.')
					mat_msj[i - z][0] = 36;
				else
					mat_msj[i - z][0] = msj[i] - '0';
			}
			for (int i = 0; i < 3; i++) {
				int sum = 0;
				for (int j = 0; j < 3; j++) {
					sum += mat_cheie[i][j] * mat_msj[j][0];
				}
				sum = sum % 37;
				if (sum <= 35 && sum >= 10)
					printf("%c", sum - 10 + 'A');
				else if (sum <= 9)
					printf("%c", sum + '0');
				else
					printf(".");
			}
		} else if (len_msj - z == 2) {
			int cnt = 0;
			for (int i = 0; i < len_msj - z && ok == 1; i++) {
				for (int j = 0; j < len_msj - z; j++) {
					if (cheie[cnt] >= 'A' && cheie[cnt] <= 'Z') {
						mat_cheie[i][j] = 10 + (cheie[cnt] - 'A');
					} else if (cheie[cnt] == '.')
						mat_cheie[i][j] = 36;
					else
						mat_cheie[i][j] = cheie[cnt] - '0';
					cnt++;
				}
			}
			for (int i = z; i < len_msj; i++) {
				if (msj[i] >= 'A' && msj[i] <= 'Z') {
					mat_msj[i - z][0] = 10 + (msj[i] - 'A');
				} else if (msj[i] == '.')
					mat_msj[i - z][0] = 36;
				else
					mat_msj[i - z][0] = msj[i] - '0';
			}
			for (int i = 0; i < len_msj - z; i++) {
				int sum = 0;
				for (int j = 0; j < len_msj - z; j++) {
					sum += mat_cheie[i][j] * mat_msj[j][0];
				}
				sum = sum % 37;
				if (sum <= 35 && sum >= 10)
					printf("%c", sum - 10 + 'A');
				else if (sum <= 9)
					printf("%c", sum + '0');
				else
					printf(".");
			}
			ok = 0;
		} else {
			int sum;
			if (msj[len_msj - 1] >= 'A' && msj[len_msj - 1] <= 'Z') {
				sum = (mat_cheie[0][0] * (10 + (msj[len_msj - 1]
					- 'A'))) % 37;
			} else if (msj[len_msj - 1] == '.')
				sum = (mat_cheie[0][0] * 36) % 37;
			else
				sum = (mat_cheie[0][0] * (msj[len_msj - 1] - '0')) % 37;
			if (sum <= 35 && sum >= 10)
				printf("%c", sum - 10 + 'A');
			else if (sum <= 9)
				printf("%c", sum + '0');
			else
				printf(".");
		}
	}
}

void invers_multiplicativ(int det, int alfabet, int *x, int *y)
{
	if (alfabet == 0) {
		*x = 1;
		*y = 0;
		return;
	}
	int x1, y1;
	invers_multiplicativ(alfabet, det % alfabet, &x1, &y1);
	*x = y1;
	*y = x1 - det / alfabet * y1;
}

void calcul_adjuncta3(int **mat_cheie)
{
	int nr1 = mat_cheie[1][1] * mat_cheie[2][2]
			- mat_cheie[1][2] * mat_cheie[2][1];
	int nr2 = mat_cheie[1][2] * mat_cheie[2][0]
			- mat_cheie[1][0] * mat_cheie[2][2];
	int nr3 = mat_cheie[1][0] * mat_cheie[2][1]
			- mat_cheie[1][1] * mat_cheie[2][0];
	int nr4 = mat_cheie[0][2] * mat_cheie[2][1]
			- mat_cheie[0][1] * mat_cheie[2][2];
	int nr5 = mat_cheie[0][0] * mat_cheie[2][2]
			- mat_cheie[0][2] * mat_cheie[2][0];
	int nr6 = mat_cheie[0][1] * mat_cheie[2][0]
			- mat_cheie[0][0] * mat_cheie[2][1];
	int nr7 = mat_cheie[0][1] * mat_cheie[1][2]
			- mat_cheie[0][2] * mat_cheie[1][1];
	int nr8 = mat_cheie[0][2] * mat_cheie[1][0]
			- mat_cheie[0][0] * mat_cheie[1][2];
	int nr9 = mat_cheie[0][0] * mat_cheie[1][1]
			- mat_cheie[0][1] * mat_cheie[1][0];
	if (nr1 >= 0)
		mat_cheie[0][0] = nr1 % 37;
	else
		mat_cheie[0][0] = ((nr1 % 37) + 37) % 37;
	if (nr2 >= 0)
		mat_cheie[1][0] = nr2 % 37;
	else
		mat_cheie[1][0] = ((nr2 % 37) + 37) % 37;
	if (nr3 >= 0)
		mat_cheie[2][0] = nr3 % 37;
	else
		mat_cheie[2][0] = ((nr3 % 37) + 37) % 37;
	if (nr4 >= 0)
		mat_cheie[0][1] = nr4 % 37;
	else
		mat_cheie[0][1] = ((nr4 % 37) + 37) % 37;
	if (nr5 >= 0)
		mat_cheie[1][1] = nr5 % 37;
	else
		mat_cheie[1][1] = ((nr5 % 37) + 37) % 37;
	if (nr6 >= 0)
		mat_cheie[2][1] = nr6 % 37;
	else
		mat_cheie[2][1] = ((nr6 % 37) + 37) % 37;
	if (nr7 >= 0)
		mat_cheie[0][2] = nr7 % 37;
	else
		mat_cheie[0][2] = ((nr7 % 37) + 37) % 37;
	if (nr8 >= 0)
		mat_cheie[1][2] = nr8 % 37;
	else
		mat_cheie[1][2] = ((nr8 % 37) + 37) % 37;
	if (nr9 >= 0)
		mat_cheie[2][2] = nr9 % 37;
	else
		mat_cheie[2][2] = ((nr9 % 37) + 37) % 37;
}

void calcul_adjuncta2(int **mat_cheie)
{
	int nr1 = mat_cheie[1][1];
	int nr2 = -mat_cheie[0][1];
	int nr3 = -mat_cheie[1][0];
	int nr4 = mat_cheie[0][0];
	if (nr4 >= 0)
		mat_cheie[1][1] = nr4 % 37;
	else
		mat_cheie[1][1] = ((nr4 % 37) + 37) % 37;
	if (nr3 >= 0)
		mat_cheie[1][0] = nr3 % 37;
	else
		mat_cheie[1][0] = ((nr3 % 37) + 37) % 37;
	if (nr2 >= 0)
		mat_cheie[0][1] = nr2 % 37;
	else
		mat_cheie[0][1] = ((nr2 % 37) + 37) % 37;
	if (nr1 >= 0)
		mat_cheie[0][0] = nr1 % 37;
	else
		mat_cheie[0][0] = ((nr1 % 37) + 37) % 37;
}

int calcul_det3(int **mat_cheie)
{
	int det = mat_cheie[0][0] * mat_cheie[1][1] * mat_cheie[2][2] +
	mat_cheie[1][0] * mat_cheie[2][1] * mat_cheie[0][2] +
	mat_cheie[0][1] * mat_cheie[1][2] * mat_cheie[2][0] -
	mat_cheie[0][2] * mat_cheie[1][1] * mat_cheie[2][0] -
	mat_cheie[1][0] * mat_cheie[0][1] * mat_cheie[2][2] -
	mat_cheie[0][0] * mat_cheie[1][2] * mat_cheie[2][1];
	det = ((det % 37) + 37) % 37;
	return det;
}

void codificare_cu_msj_complet(int z, char *msj, int **mat_msj,
							   int **mat_cheie, char *rez)
{
	for (int i = z; i < 3 + z; i++) {
		if (msj[i] >= 'A' && msj[i] <= 'Z') {
			mat_msj[i - z][0] = 10 + (msj[i] - 'A');
		} else if (msj[i] == '.')
			mat_msj[i - z][0] = 36;
		else
			mat_msj[i - z][0] = msj[i] - '0';
	}
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += mat_cheie[i][j] * mat_msj[j][0];
		}
		sum = sum % 37;
		if (sum <= 35 && sum >= 10)
			rez[i + z] = sum - 10 + 'A';
		else if (sum <= 9)
			rez[i + z] = sum + '0';
		else
			rez[i + z] = '.';
	}
}

void decodificare(int **mat_cheie,
				  int len_msj, int **mat_msj, char *msj,
				  char *rez, int ok, char *cheie)
{
	int det = calcul_det3(mat_cheie);
	int x, y;
	invers_multiplicativ(det, 37, &x, &y);
	while (x < 0)
		x += 37;
	calcul_adjuncta3(mat_cheie);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat_cheie[i][j] = (x * mat_cheie[i][j]) % 37;
		}
	}
	for (int z = 0; z < len_msj; z += 3) {
		if (len_msj - z >= 3) {
			codificare_cu_msj_complet(z, msj, mat_msj, mat_cheie, rez);
		} else {
			int cnt = 0;
			for (int i = 0; i < len_msj - z && ok == 1; i++) {
				for (int j = 0; j < len_msj - z; j++) {
					if (cheie[cnt] >= 'A' && cheie[cnt] <= 'Z') {
						mat_cheie[i][j] = 10 + (cheie[cnt] - 'A');
					} else if (cheie[cnt] == '.')
						mat_cheie[i][j] = 36;
					else
						mat_cheie[i][j] = cheie[cnt] - '0';
					cnt++;
				}
			}
			int det = mat_cheie[0][0] * mat_cheie[1][1] -
					  mat_cheie[0][1] * mat_cheie[1][0];
			det = ((det % 37) + 37) % 37;
			int x, y;
			invers_multiplicativ(det, 37, &x, &y);
			while (x < 0)
				x += 37;
			calcul_adjuncta2(mat_cheie);
			for (int i = 0; i < len_msj - z; i++) {
				for (int j = 0; j < len_msj - z; j++) {
					mat_cheie[i][j] = (x * mat_cheie[i][j]) % 37;
				}
			}
			for (int i = z; i < len_msj; i++) {
				if (msj[i] >= 'A' && msj[i] <= 'Z') {
					mat_msj[i - z][0] = 10 + (msj[i] - 'A');
				} else if (msj[i] == '.')
					mat_msj[i - z][0] = 36;
				else
					mat_msj[i - z][0] = msj[i] - '0';
			}
			for (int i = 0; i < len_msj - z; i++) {
				int sum = 0;
				for (int j = 0; j < len_msj - z; j++) {
					sum += mat_cheie[i][j] * mat_msj[j][0];
				}
				sum = sum % 37;
				if (sum <= 35 && sum >= 10)
					rez[i + z] = sum - 10 + 'A';
				else if (sum <= 9)
					rez[i + z] = sum + '0';
				else
					rez[i + z] = '.';
			}
			ok = 0;
		}
	}
}

void algoritmul_hill_cipher(char *msj, char *cheie, char *rez, int **mat_cheie,
							int *index, char *rasp,
							double *acc_meci, double *nr_lovituri_nimerite1,
							double *nr_nave, int **mat_msj, int jocuri,
							double *nr_lovituri_totale1,
							double *nr_lovituri_nimerite2,
							double *nr_lovituri_totale2)
{
	int len_msj = strlen(msj);
	creare_matrice_cheie(0, cheie, mat_cheie);
	decodificare(mat_cheie, len_msj, mat_msj, msj, rez, 1, cheie);
	statistics(index, jocuri, rez, nr_lovituri_nimerite1,
			   nr_lovituri_totale1, nr_nave, acc_meci,
			   nr_lovituri_totale2, nr_lovituri_nimerite2, rasp, cheie);
	creare_matrice_cheie(0, cheie, mat_cheie);
	int len_rasp = strlen(rasp);
	codificare(len_rasp, rasp, mat_msj, mat_cheie, cheie, 1);
}

void battleships(int jocuri, double *nr_nave, double *nr_lovituri_nimerite1,
				 double *nr_lovituri_nimerite2, double *nr_lovituri_totale2,
				 double *nr_lovituri_totale1)
{
	char nava, orientare;
	int m, n, x, y, k = 0;
	for (int meci = 1; meci <= jocuri; meci++) {
		scanf("%d%d", &n, &m);
		int gasit1 = 0, gasit2 = 0, pers = 1;
		int **mat1 = calloc(n + 1, sizeof(int *));
		int **mat2 = calloc(n + 1, sizeof(int *));
		k = calcul_k(k, m, n);
		for (int i = 1; i <= k; i++) {
			scanf(" %c %c %d %d", &nava, &orientare, &x, &y);
			nr_nave[meci]++;
			int nr, e_nava = 0;
			nr = determinare_barca(nr, nava);
			if (orientare == 'H') {
				if (y + nr - 1 <= m && y >= 1 && y <= m) {
					amplasare_H(mat1, mat2, m, x, y, nr, &pers,
								&e_nava, &gasit1, &gasit2);
				}
				if (y + nr - 1 > m || y < 1 || y > m || e_nava == 1) {
					k++;
					nr_nave[meci]--;
					afisare_mesaj1(x, y, nava);
					continue;
				}
			} else {
				if (x - nr + 1 >= 1 && x >= 1 && x <= n) {
					amplasare_V(mat1, mat2, m, x, y, nr, &pers,
								&e_nava, &gasit1, &gasit2);
				}
				if (x - nr + 1 < 1 || x < 1 || x > n || e_nava == 1) {
					k++;
					nr_nave[meci]--;
					afisare_mesaj2(x, y, nava);
					continue;
				}
			}
		}
		afisare_matrice(mat1, mat2, m, n);
		alegere_castigator(0, mat2, mat1, x, y, 1, m, &gasit1, &gasit2,
						   nr_lovituri_nimerite1, nr_lovituri_nimerite2,
						   nr_lovituri_totale1, nr_lovituri_totale2, meci);
		eliberare_memorie(mat1, mat2, n);
	}
}

int main(void)
{
	int jocuri;
	scanf("%d", &jocuri);
	int *index = calloc(jocuri + 1, sizeof(int));
	for (int i = 1; i <= jocuri; i++)
		index[i] = i;
	int **mat_msj = calloc(10, sizeof(int *));
	int **mat_cheie = calloc(10, sizeof(int *));
	for (int i = 0; i < 10; i++)
		mat_msj[i] = calloc(3, sizeof(int));
	for (int i = 0; i < 10; i++)
		mat_cheie[i] = calloc(4, sizeof(int));
	double *nr_nave = calloc(jocuri + 1, sizeof(double));
	double *acc_meci = calloc(jocuri + 1, sizeof(double));
	copie_acc_meci = acc_meci;
	copie_nr_nave = nr_nave;
	double *nr_lovituri_nimerite1 = calloc(jocuri + 1, sizeof(double));
	double *nr_lovituri_nimerite2 = calloc(jocuri + 1, sizeof(double));
	double *nr_lovituri_totale1 = calloc(jocuri + 1, sizeof(double));
	double *nr_lovituri_totale2 = calloc(jocuri + 1, sizeof(double));
	battleships(jocuri, nr_nave, nr_lovituri_nimerite1, nr_lovituri_nimerite2,
				nr_lovituri_totale2, nr_lovituri_totale1);
	char cheie[15], msj[15], rez[15], rasp[15];
	scanf(" %s", cheie);
	while (scanf("%s", msj) == 1 && strlen(msj) > 2) {
		if (cheie[0] == '-') {
			statistics(index, jocuri, msj, nr_lovituri_nimerite1,
					   nr_lovituri_totale1, nr_nave, acc_meci,
					   nr_lovituri_totale2, nr_lovituri_nimerite2, rasp, cheie);
		} else {
			algoritmul_hill_cipher(msj, cheie, rez, mat_cheie, index,
								   rasp, acc_meci,
								   nr_lovituri_nimerite1, nr_nave, mat_msj,
								   jocuri, nr_lovituri_totale1,
								   nr_lovituri_nimerite2,
								   nr_lovituri_totale2);
		}
		printf("\n");
	}

	free(nr_lovituri_nimerite1);
	free(nr_lovituri_nimerite2);
	free(nr_lovituri_totale1);
	free(nr_lovituri_totale2);
	free(nr_nave);
	free(acc_meci);
	free(index);
	for (int i = 0; i < 10; i++)
		free(mat_msj[i]);
	for (int i = 0; i < 10; i++)
		free(mat_cheie[i]);
	free(mat_cheie);
	free(mat_msj);
	return 0;

}
