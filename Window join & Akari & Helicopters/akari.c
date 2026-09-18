#include <stdio.h>

int main(void)
{
	int o, n, m;
	char mat[51][51];
	scanf("%d%d%d", &o, &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%19s", &mat[i][j]);
		}
	}
if (o == 1) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'L') {
				int copie_i = i;
				int copie_j = j;
				copie_j++;
				while (copie_j < m &&
				       (mat[i][copie_j] == '-' || mat[i][copie_j] == 'x')) {
					mat[i][copie_j] = 'x';
					copie_j++;
}

				copie_j = j - 1;
				while (copie_j >= 0 &&
				       (mat[i][copie_j] == '-' || mat[i][copie_j] == 'x')) {
					mat[i][copie_j] = 'x';
					copie_j--;
				}
				copie_i = i + 1;
				while (copie_i < n &&
					   (mat[copie_i][j] == '-' || mat[copie_i][j] == 'x')) {
					mat[copie_i][j] = 'x';
					copie_i++;
				}
				copie_i = i - 1;
				while (copie_i >= 0 &&
					   (mat[copie_i][j] == '-' || mat[copie_i][j] == 'x')) {
					mat[copie_i][j] = 'x';
					copie_i--;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '1' || mat[i][j] == '2' ||
				mat[i][j] == '3' || mat[i][j] == '4' || mat[i][j] == '0') {
				int nr = 0;
			if (mat[i][j + 1] == 'L' && j + 1 < m) {
				nr++;
			}
			if (mat[i][j - 1] == 'L' && j - 1 >= 0) {
				nr++;
			}
			if (mat[i + 1][j] == 'L' && i + 1 < n) {
				nr++;
			}
			if (mat[i - 1][j] == 'L' && i - 1 >= 0) {
				nr++;
			}
		if (nr == mat[i][j] - '0') {
			if (mat[i][j + 1] == '-' && j + 1 < m) {
				mat[i][j + 1] = 'x';
			}
			if (mat[i][j - 1] == '-' && j - 1 >= 0) {
				mat[i][j - 1] = 'x';
			}
			if (mat[i + 1][j] == '-' && i + 1 < n) {
				mat[i + 1][j] = 'x';
			}
			if (mat[i - 1][j] == '-' && i - 1 >= 0)
				mat[i - 1][j] = 'x';
			}
		}
	}
}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'L') {
					int copie_i = i;
					int copie_j = j;
					copie_j++;
					while (copie_j < m &&
						   (mat[i][copie_j] == '-' || mat[i][copie_j] == 'x')) {
						mat[i][copie_j] = 'x';
						copie_j++;
					}
					copie_j = j - 1;
				while (copie_j >= 0 &&
					   (mat[i][copie_j] == '-' || mat[i][copie_j] == 'x')) {
					mat[i][copie_j] = 'x';
					copie_j--;
				}
				copie_i = i + 1;
				while (copie_i < n &&
					   (mat[copie_i][j] == '-' || mat[copie_i][j] == 'x')) {
					mat[copie_i][j] = 'x';
					copie_i++;
				}
				copie_i = i - 1;
				while (copie_i >= 0 &&
					   (mat[copie_i][j] == '-' || mat[copie_i][j] == 'x')) {
					mat[copie_i][j] = 'x';
					copie_i--;
				}
			}
		}
	}
	int gresit = 0;
		for (int i = 0; i < n && gresit == 0; i++) {
			for (int j = 0; j < m && gresit == 0; j++) {
				if (mat[i][j] == 'L') {
					int copie_i = i;
					int copie_j = j;
				copie_j++;
					while (copie_j < m &&
						   (mat[i][copie_j] == '-' || mat[i][copie_j] == 'x')) {
						copie_j++;
					}
				if (mat[i][copie_j] == 'L' && copie_j < m) {
					gresit = 1;
				}
				copie_j = j - 1;
					while (copie_j >= 0 &&
						   (mat[i][copie_j] == '-' || mat[i][copie_j] == 'x')) {
						copie_j--;
					}
				if (mat[i][copie_j] == 'L' && copie_j >= 0) {
					gresit = 1;
				}
				copie_i = i + 1;
					while (copie_i < n &&
						   (mat[copie_i][j] == '-' || mat[copie_i][j] == 'x')) {
						copie_i++;
					}
				if (mat[copie_i][j] == 'L' && copie_i < n) {
					gresit = 1;
				}
					copie_i = i - 1;
					while (copie_i >= 0 &&
						   (mat[copie_i][j] == '-' || mat[copie_i][j] == 'x')) {
						copie_i--;
					}
				if (mat[copie_i][j] == 'L' && copie_i >= 0) {
					gresit = 1;
				}
			}
				if (mat[i][j] == '1' ||
					mat[i][j] == '2' || mat[i][j] == '3' ||
					mat[i][j] == '4' || mat[i][j] == '0') {
					int nr = 0;
					if (mat[i][j + 1] == 'L' && j + 1 < m) {
						nr++;
			}
					if (mat[i][j - 1] == 'L' && j - 1 >= 0) {
						nr++;
			}
					if (mat[i + 1][j] == 'L' && i + 1 < n) {
						nr++;
			}
					if (mat[i - 1][j] == 'L' && i - 1 >= 0) {
						nr++;
			}
					if (mat[i][j] - '0' < nr)
						gresit = 1;
					nr = 0;
					if (mat[i][j + 1] != '-' &&
						mat[i][j + 1] != 'L' && j + 1 < m) {
						nr++;
			}
					if (mat[i][j - 1] != '-' &&
						mat[i][j - 1] != 'L' && j - 1 >= 0) {
						nr++;
			}
					if (mat[i + 1][j] != '-' &&
						mat[i + 1][j] != 'L' && i + 1 < n) {
						nr++;
			}
					if (mat[i - 1][j] != '-' &&
						mat[i - 1][j] != 'L' && i - 1 >= 0) {
						nr++;
			}
					if (mat[i][j] - '0' > 4 - nr)
						gresit = 1;
		}
	}
}

	if (gresit == 0)
		printf("ichi");
	else
		printf("zero");
	}
}
