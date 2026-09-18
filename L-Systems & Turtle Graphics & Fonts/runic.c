#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.14159265358979323846
#include <math.h>

//Tiepac Anduena-Maria CB311

struct regula { // un struct pt simbol si succesor ca sa fie salvate impreuna
	char simbol[100];
	char succesor[100];
} pereche[100];

struct caracter {
	char nume_caracter;
	int dwx, dwy, bbw, bbh, bbxoff, bbyoff;
	unsigned char *bitmap;
};

void realocare(int *lung, int lungime_raspuns,
			   int lungime_pereche_succesor, char **raspuns)
{ // realoc daca nu mai exista suficient spatiu pt derivare
	*lung = (lungime_raspuns + lungime_pereche_succesor + 1) * 100;
	char *aux = realloc(*raspuns, (*lung) * sizeof(char));
	if (!aux) {
		printf("Eroare la realocare");
		exit(1);
	}
	*raspuns = aux;
}

void undo(int *numar, int *anulat, char **fisier,
		  char *axioma, int *nrules, FILE *f)
{
	if (*numar >= 1) {
		(*numar)--; // fac undo
		*anulat = 1; // retin ca s a fc undo
	} else
		printf("Nothing to undo\n");
	if (*numar >= 1) {
		f = fopen(fisier[*numar], "r");
		if (!f) {
			printf("Eroare la deschidere");
			exit(1);
		}
		fscanf(f, "%s%d", axioma, nrules); // retin din nou ultimul lsystem
		for (int i = 1; i <= *nrules; i++) {
			fscanf(f, "%s%s", pereche[i].simbol, pereche[i].succesor);
		}
		fclose(f);
	}
}

void deriv(int lungime, char *axioma, int lung, int nrules, char **copie_axioma)
{
	char *derivare;
	derivare = strtok(NULL, " ");
	int nr = atoi(derivare); // retin de cate ori derivez
	lungime = 100; // m grija sa updatez lungimile pt realocare
	strcpy(*copie_axioma, axioma);
	char *raspuns = calloc(100, sizeof(char));
	if (!raspuns) {
		printf("Eroare la alocare");
		exit(1);
	}
	int lungime_raspuns = 0;
	lung = 100;
	for (int i = 0; i < nr; i++) { // fiecare derivare
		int len = strlen(*copie_axioma);
		for (int j = 0; j < len; j++) {
//parcurg fiecare element al axiomei derivate sau initiale
			int ok = 0; // retin daca am gasit elementul printre simbluri sau nu
			for (int k = 1; k <= nrules; k++) { // parcurg fiecare simbol
				if ((*copie_axioma)[j] == pereche[k].simbol[0]) {
// daca gasesc simbolul il pun in vectorul raspuns
//(la sfarsit de bucla el va reprezenta derivarea)
					int lungime_pereche_succesor =
					strlen(pereche[k].succesor);
					if (lungime_raspuns + lungime_pereche_succesor
						+ 1 > lung) {
						realocare(&lung, lungime_raspuns,
								  lungime_pereche_succesor, &raspuns);
					}
					strcpy(raspuns + lungime_raspuns, pereche[k].succesor);
					lungime_raspuns += lungime_pereche_succesor;
					ok = 1;
				}
			}
			if (ok == 0) {
// daca n am gasit simbolul atunci il pun pur si simplu in raspuns
				int len_rsp = strlen(raspuns);
				if (len_rsp + 1 > lung) {
					lung++;
					char *aux = realloc(raspuns, lung * sizeof(char));
					if (!aux) {
						free(raspuns);
						printf("Eroare la realocare");
						exit(1);
					}
					raspuns = aux;
				}
				raspuns[len_rsp] = (*copie_axioma)[j];
				raspuns[len_rsp + 1] = '\0';
				lungime_raspuns++;
			}
		}
		int lungime_copie_axioma = strlen(*copie_axioma);
		if (lungime_raspuns + lungime_copie_axioma + 1 > lungime) {
			lungime = (lungime_raspuns +
					   lungime_copie_axioma + 1) * 100;
			char *aux = realloc(*copie_axioma, lungime * sizeof(char));
			if (!aux) {
				free(*copie_axioma);
				printf("Eroare la realocare");
				exit(1);
			}
			*copie_axioma = aux;
		}
// transfer din raspuns in copie axioma ca sa mai derivez o data daca e necesar
		strcpy(*copie_axioma, raspuns);
		raspuns[0] = '\0'; //"sterg" ce era in raspuns
		lungime_raspuns = 0;
	}
	printf("%s\n", *copie_axioma); // afisez raspunsul
	free(raspuns);
}

void derivam(int nn, char *axioma, int nrules, char **copie_axioma)
{
//asemanatoare ca mod de gandire cu functia deriv doar ca nu afiseaza la sfarsit
//e facuta special pt turtle
	int lungime = 100;
	strcpy(*copie_axioma, axioma);
	char *raspuns = calloc(100, sizeof(char));
	if (!raspuns) {
		printf("Eroare la alocare");
		exit(1);
	}
	int lungime_raspuns = 0;
	int lung = 100;
	for (int i = 0; i < nn; i++) {
		int len = strlen(*copie_axioma);
		for (int j = 0; j < len; j++) {
			int ok = 0;
			for (int k = 1; k <= nrules; k++) {
				if ((*copie_axioma)[j] == pereche[k].simbol[0]) {
					int lungime_pereche_succesor =
					strlen(pereche[k].succesor);
					if (lungime_raspuns + lungime_pereche_succesor
						+ 1 > lung) {
						realocare(&lung, lungime_raspuns,
								  lungime_pereche_succesor, &raspuns);
					}
					strcpy(raspuns + lungime_raspuns, pereche[k].succesor);
					lungime_raspuns += lungime_pereche_succesor;
					ok = 1;
					break;
				}
			}
			if (ok == 0) {
				if (lungime_raspuns + 2 > lung) {
					lung += 2;
					char *aux = realloc(raspuns, lung * sizeof(char));
					if (!aux) {
						free(raspuns);
						printf("Eroare la realocare");
						exit(1);
					}
					raspuns = aux;
				}
				raspuns[lungime_raspuns] = (*copie_axioma)[j];
				raspuns[lungime_raspuns + 1] = '\0';
				lungime_raspuns += 1;
			}
		}
		if (lungime_raspuns + 1 > lungime) {
			lungime = (lungime_raspuns + 1) * 100;
			char *aux = realloc(*copie_axioma, lungime * sizeof(char));
			if (!aux) {
				free(*copie_axioma);
				printf("Eroare la realocare");
				exit(1);
			}
			*copie_axioma = aux;
		}
		strcpy(*copie_axioma, raspuns);
		raspuns[0] = '\0';
		lungime_raspuns = 0;
	}
		free(raspuns);
}

void set_pixel(unsigned char *img, int width, int x0,
			   int y0, int R, int G, int B, int height)
{
//calculez pe i tinand cont de faptul ca coltul din
//stanga jos al imaginii este cel (0,0)
	int i = ((height - 1 - y0) * width + x0) * 3;
//verific daca este in imagine
	if (x0 < 0 || x0 >= width || y0 < 0 || y0 >= height)
		return;
	if (i < 0 || i + 2 > width * height * 3) {
		return;
	}
//adaug culorile
	img[i] = R;
	img[i + 1] = G;
	img[i + 2] = B;
}

void draw_line(unsigned char *img, int width, int x0,
			   int y0, int x1, int y1, int R, int G, int B, int height)
{
//desenez linia cu algoritmul din cerinta
	int dx = abs(x1 - x0);
	int sx = (x0 < x1) ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy;
	while (1) {
		set_pixel(img, width, x0, y0, R, G, B, height);
		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		}
	}
}

void turtle(unsigned char *img, char *copie_axioma, double pas_deplasare,
			double pas_unghiular, double orientare_initiala,
			int R, int G, int B, int width, int height, double x0, double y0)
{
	double x1, y1;
	double orientare1 = orientare_initiala;
	double *orientare = calloc(100000, sizeof(double));
// fac un vector de coordonate x si y pt ca la problema
//cu broasca testoasa sa ma pot intoarce la o pozitie anterioara
	double *coordonate_x = calloc(100000, sizeof(double));
	double *coordonate_y = calloc(100000, sizeof(double));
	if (!coordonate_x || !coordonate_y || !orientare) {
		printf("Eroare la alocare");
		exit(1);
	}
	int lungime_axioma = strlen(copie_axioma);
	int coord = 0, spatiu = 100000;
//parcurg fiecare element al derivarii pt a face operatiile
	for (int i = 0; i < lungime_axioma; i++) {
		if (copie_axioma[i] == 'F') {
//calculez coordonatele pt a trasa linia
//unghiul trb sa fie in radiani pt sin si cos
			double unghi = orientare1 * PI / 180.0;
			x1 = x0 + pas_deplasare * cos(unghi);
			y1 = y0 + pas_deplasare * sin(unghi);
//trasez linia
			draw_line(img, width, (int)round(x0), (int)round(y0),
					  (int)round(x1), (int)round(y1), R, G, B, height);
//mut testoasa la finalul liniei
			x0 = x1;
			y0 = y1;
		} else if (copie_axioma[i] == '[') {
//retin pozitia
			if (coord + 2 >= spatiu) {
				double *aux = realloc(coordonate_x, spatiu * 2 *
									  sizeof(double));
				if (!aux) {
					free(coordonate_x);
					printf("Eroare la realocare");
					exit(1);
				}
				coordonate_x = aux;
				double *aux2 = realloc(coordonate_y, spatiu * 2 *
									   sizeof(double));
				if (!aux2) {
					printf("Eroare la realocare");
					free(coordonate_y);
					exit(1);
				}
				coordonate_y = aux2;
				double *aux3 = realloc(orientare, spatiu * 2 * sizeof(double));
				if (!aux3) {
					printf("Eroare la realocare");
					free(orientare);
					exit(1);
				}
				orientare = aux3;
				spatiu *= 2;
			}
			orientare[coord] = orientare1;
			coordonate_x[coord] = x1;
			coordonate_y[coord] = y1;
			coord++;
		} else if (copie_axioma[i] == ']') {
//elimin ultima pozitie retinuta
			coord--;
			x0 = coordonate_x[coord];
			y0 = coordonate_y[coord];
			orientare1 = orientare[coord];
		} else if (copie_axioma[i] == '+') {
//cresc unghiul
			orientare1 += pas_unghiular;
		} else if (copie_axioma[i] == '-') {
//scand unghiul
			orientare1 -= pas_unghiular;
		}
	}
	free(orientare);
	free(coordonate_x);
	free(coordonate_y);
}

void redo(int ultima_operatie, int *anulat, int *numar, char **fisier,
		  char *axioma, int *nrules, int height, FILE *f,
		  int width, unsigned char *img, unsigned char *img_pt_redo,
		  unsigned char *img_text_redo)
{
	if (ultima_operatie == 1) {
// verific daca s a anulat ceva inainte ca sa ii facem redo
		if (*anulat == 1) {
			*anulat = 0;
			(*numar)++; // se face redo la lsystem
			f = fopen(fisier[*numar], "r");
			if (!f) {
				printf("Eroare la deschidere");
				exit(1);
			}
// extragem din nou ce avem nevoie din el
			fscanf(f, "%s%d", axioma, nrules);
			printf("Loaded %s (L-system with %d rules)\n",
				   fisier[*numar], *nrules);
			for (int i = 1; i <= *nrules; i++)
				fscanf(f, "%s%s", pereche[i].simbol,
					   pereche[i].succesor);
			fclose(f);
		} else
			printf("Nothing to redo\n");
	} else if (ultima_operatie == 3) {
		printf("Drawing done\n");
//retin stadiul de dupa redo
		for (int j = 0; j < width * height * 3; j++) {
			img[j] = img_pt_redo[j];
		}
	} else if (ultima_operatie == 4) {
		printf("Text written\n");
//retin stadiul de dupa redo
		for (int j = 0; j < width * height * 3; j++) {
			img[j] = img_text_redo[j];
		}
	}
}

void load(int *numar_img, int *anulat, int *copie_numar_img,
		  char **nume_imagine, FILE *imagine, int *nr_img,
		  int *ultima_operatie, int *width, int *height, int *maxval,
		  char *magic, unsigned char **img, unsigned char **img_pt_redo,
		  unsigned char **img_pt_undo, unsigned char **img_text_undo,
		  unsigned char **img_text_redo)
{
	(*numar_img)++;
	*anulat = 0;
	(*copie_numar_img)++;
// daca sunt cu contorul la sfarsit de vector mai
//declar o linie, daca nu o suprascriu pe urm
	if (*numar_img == *copie_numar_img) {
		nume_imagine[*numar_img] = calloc(100, sizeof(char));
		if (!nume_imagine[*numar_img]) {
			printf("Eroare la alocare");
			exit(1);
		}
	}
	strcpy(nume_imagine[*numar_img], strtok(NULL, " "));
	imagine = fopen(nume_imagine[*numar_img], "rb");
	if (!imagine) {
		printf("Failed to load %s\n", nume_imagine[*numar_img]);
	} else {
		(*nr_img)++;
//retin ca am fc load la ultima operatie
		*ultima_operatie = 2;
//citesc ce e nevoie din imagine
		fscanf(imagine, "%2s %d %d %d",
			   magic, width, height, maxval);
		fgetc(imagine);
		*img = malloc(*width * (*height) * 3);
		*img_pt_redo = malloc(*width * (*height) * 3);
		*img_pt_undo = malloc(*width * (*height) * 3);
		*img_text_undo = malloc(*width * (*height) * 3);
		*img_text_redo = malloc(*width * (*height) * 3);
		if (!*img || !*img_pt_redo || !*img_pt_undo ||
			!*img_text_undo || !*img_text_redo) {
			printf("Memory allocation failed\n");
			exit(1);
		}
		fread(*img, 1, *width * (*height) * 3, imagine);
//retin in caz ca e nevoie la undo sau redo
		for (int j = 0; j < *width * (*height) * 3; j++) {
			(*img_pt_redo)[j] = (*img)[j];
			(*img_pt_undo)[j] = (*img)[j];
		}
		printf("Loaded %s (PPM image %dx%d)\n",
			   nume_imagine[*numar_img], *width, *height);
	}
	if (imagine)
		fclose(imagine);
}

void turtle_inceput(int *anulat, int nr_img, int numar, int *ultima_operatie,
					char *axioma, int nrules, char **copie_axioma,
					int width, int height,
					unsigned char *img, unsigned char *img_pt_undo, FILE *f)
{
	int nn, x, y, pas_deplasare, R, G, B;
	double orientare, pas_unghiular;
	*anulat = 0;
	if (nr_img < 1) {
		printf("No image loaded\n");
	} else if (!f || numar < 1) {
		printf("No L-system loaded\n");
	} else {
		*ultima_operatie = 3;
		printf("Drawing done\n");
//retin datele necesare din citire
		char *p = strtok(NULL, " ");
		x = atoi(p);
		p = strtok(NULL, " ");
		y = atoi(p);
		p = strtok(NULL, " ");
		pas_deplasare = atoi(p);
		p = strtok(NULL, " ");
		orientare = atoi(p);
		p = strtok(NULL, " ");
		pas_unghiular = atoi(p);
		p = strtok(NULL, " ");
		nn = atoi(p);
		p = strtok(NULL, " ");
		R = atoi(p);
		p = strtok(NULL, " ");
		G = atoi(p);
		p = strtok(NULL, " ");
		B = atoi(p);
//derivez
		derivam(nn, axioma, nrules, copie_axioma);
//retin imaginea in caz ca trb sa fac undo
		for (int j = 0; j < width * height * 3; j++)
			img_pt_undo[j] = img[j];
//desenez
		turtle(img, *copie_axioma, pas_deplasare, pas_unghiular,
			   orientare, R, G, B, width, height, x, y);
	}
}

void functie_free(int copie_numar, int copie_numar_img,
				  char **copie_axioma, char **linie, char **axioma,
				  char ***fisier, char **copie_linie,
				  char ***nume_imagine, unsigned char **img,
				  unsigned char **img_pt_undo, unsigned char **img_pt_redo,
				  char **copie_linie2, unsigned char **img_text_undo,
				  unsigned char **img_text_redo, char ***nume_font,
				  char **linie_font,
				  char **chars, struct caracter *date_caracter,
				  int copie_nr_font)
{
//eliberez memoria
	free(*copie_axioma);
	free(*linie);
	free(*axioma);
	for (int i = 1; i <= copie_numar; i++)
		free((*fisier)[i]);
	free(*fisier);
	for (int i = 1; i <= copie_numar_img; i++)
		free((*nume_imagine)[i]);
	if (*nume_imagine)
		free(*nume_imagine);
	if (*img)
		free(*img);
	if (*img_pt_undo)
		free(*img_pt_undo);
	if (*img_pt_redo)
		free(*img_pt_redo);
	if (*img_text_undo)
		free(*img_text_undo);
	if (*img_text_redo)
		free(*img_text_redo);
	free(*copie_linie);
	free(*copie_linie2);
	for (int i = 1; i <= copie_nr_font; i++)
		free((*nume_font)[i]);
	if (*nume_font)
		free(*nume_font);
	free(*linie_font);
	free(*chars);
	for (int i = 0; i < 1072; i++) {
		free(date_caracter[i].bitmap);
	}
	free(date_caracter);
}

void save(int nr_img, int width, int height, int maxval, unsigned char *img)
{
//salvez infomatiile cerute
	if (nr_img < 1) {
		printf("No image loaded\n");
	} else {
		char *cuvant = strtok(NULL, " ");
		printf("Saved %s\n", cuvant);
		FILE *imagine_creata = fopen(cuvant, "wb");
		if (!imagine_creata) {
			printf("Eroare la deschidere");
			exit(1);
		}
		fprintf(imagine_creata, "P6\n%d %d\n%d\n",
				width, height, maxval);
		fwrite(img, 1, width * height * 3, imagine_creata);
		fclose(imagine_creata);
	}
}

void lsystem(int *numar, int *anulat, int *copie_numar,
			 int *ultima_operatie, char *axioma, int *nrules,
			 FILE **f, char ***fisier)
{
// am gasit un Lsystem, cresc contorul pt vectorul de fisiere
	(*numar)++;
	*anulat = 0;
// numar va creste/descreste in functie de undo si redo,
//trebuie sa stiu cate linii am alocat ca sa stiu cate eliberez
	(*copie_numar)++;
// daca sunt cu contorul la sfarsit de vector mai declar o linie,
//daca nu o suprascriu pe urm
	if (*numar == *copie_numar) {
		(*fisier)[*numar] = calloc(100, sizeof(char));
		if (!(*fisier)[*numar]) {
			printf("Eroare la alocare");
			exit(1);
		}
	}
	strcpy((*fisier)[*numar], strtok(NULL, " "));
	*f = fopen((*fisier)[*numar], "r"); // deschid fisierul doar ca read
	if (!(*f)) {
		printf("Failed to load %s\n", (*fisier)[*numar]);
	} else {
		*ultima_operatie = 1;
		fscanf(*f, "%s%d", axioma, nrules); // extrag din el ce e nevoie
		printf("Loaded %s (L-system with %d rules)\n",
			   (*fisier)[*numar], *nrules);
// fac un vector pt simbol si succesor
		for (int i = 1; i <= *nrules; i++)
			fscanf(*f, "%s%s", pereche[i].simbol,
				   pereche[i].succesor);
	}
}

void undo_functie(int ultima_operatie, int *numar_img,
				  int *anulat, int *width, int *nrules, char *axioma,
				  int *numar, int *height, char *magic, FILE *f,
				  char **fisier, char **nume_imagine,
				  FILE *imagine, int *maxval, unsigned char **img,
				  unsigned char **img_pt_undo, unsigned char **img_pt_redo,
				  unsigned char **img_text_undo, unsigned char **img_text_redo)
{
// vad la ce operatie trebuie sa fac undo
	if (ultima_operatie == 1)
		undo(numar, anulat, fisier, axioma, nrules, f);
	else if (ultima_operatie == 2) {
		if (*numar_img >= 1) {
			(*numar_img)--; // fac undo
			*anulat = 2; // retin ca s a fc undo
		} else
			printf("Nothing to undo\n");
		if (*numar_img >= 1) {
//daca am fc undo la load, inarc imaginea de dinainte
			imagine = fopen(nume_imagine[*numar_img], "rb");
			if (!imagine) {
				printf("Eroare la deschidere");
				exit(1);
			}
			fscanf(imagine, "%2s %d %d %d", magic,
				   width, height, maxval);
			fgetc(imagine);
//eliberez imaginea precedenta ca sa i pot aloca marimea curenta
			if (*img)
				free(*img);
			if (*img_pt_undo)
				free(*img_pt_undo);
			*img = malloc(*width * (*height) * 3);
			*img_pt_undo = malloc(*width * (*height) * 3);
			if (!*img || !*img_pt_undo) {
				printf("Eroare la alocare");
				exit(1);
			}
			fread(*img, 1, *width * (*height) * 3, imagine);
//salvez ce e in img ca sa pot face undo la turtle daca e cazul
			for (int j = 0; j < *width * (*height) * 3; j++) {
				(*img_pt_undo)[j] = (*img)[j];
			}
			fclose(imagine);
		}
	} else if (ultima_operatie == 3) {
//fac undo la turtle
		if (*img_pt_redo)
			free(*img_pt_redo);
		*img_pt_redo = malloc(*width * (*height) * 3);
		if (!*img_pt_redo) {
			printf("Eroare la alocare");
			exit(1);
			}
//retin ce era in img ca sa pot face redo daca este cazul
		for (int j = 0; j < *width * (*height) * 3; j++)
			(*img_pt_redo)[j] = (*img)[j];
//reincarc ce era inainte de turtle-ul la care fac undo
		for (int j = 0; j < *width * (*height) * 3; j++)
			(*img)[j] = (*img_pt_undo)[j];
	} else if (ultima_operatie == 4) {
//fac undo la turtle
		if (*img_text_redo)
			free(*img_text_redo);
		*img_text_redo = malloc(*width * (*height) * 3);
		if (!*img_pt_redo) {
			printf("Eroare la alocare");
			exit(1);
		}
//retin ce era in img ca sa pot face redo daca este cazul
		for (int j = 0; j < *width * (*height) * 3; j++)
			(*img_text_redo)[j] = (*img)[j];
//reincarc ce era inainte de turtle-ul la care fac undo
		for (int j = 0; j < *width * (*height) * 3; j++)
			(*img)[j] = (*img_text_undo)[j];
	}
}

void set_pixel_text(unsigned char *img, int width, int height,
					int x, int y, int R_scris, int G_scris, int B_scris)
{
//setez pixelul
	if (x < 0 || x >= width || y < 0 || y >= height)
		return;
	int i = ((height - 1 - y) * width + x) * 3;
	if (i < 0 || i + 2 > width * height * 3)
		return;
	img[i] = R_scris;
	img[i + 1] = G_scris;
	img[i + 2] = B_scris;
}

int desen_caracter(int *x0, int *y0, int width, int height,
				   int R_scris, int G_scris, int B_scris,
				   unsigned char *img, struct caracter *date_caracter,
				   int j)
{
//parcurgem bitmap-ul
	for (int y = 0; y < date_caracter[j].bbh; y++) {
		for (int x = 0; x < date_caracter[j].bbw; x++) {
//daca pixel-ul este 1 il desenam
			if (date_caracter[j].bitmap[y * date_caracter[j].bbw + x] == 1) {
//calculam coordonatele din imagine
				int px = *x0 + date_caracter[j].bbxoff + x;
				int py = *y0 + date_caracter[j].bbyoff
				+ (date_caracter[j].bbh - 1 - y);
				set_pixel_text(img, width, height, px, py,
							   R_scris, G_scris, B_scris);
			}
		}
	}
//mut "cursorul" pt urmatorul caracter
	*x0 += date_caracter[j].dwx;
	*y0 += date_caracter[j].dwy;
	return 1;
}

void deseneaza_text(char *text, int x0, int y0,
					unsigned char *img, int R_scris, int G_scris,
					int B_scris, int nr_carac,
					struct caracter *date_caracter, int width, int height)
{
//parcurg fiecare litera care e de scris
	for (int i = 0; text[i]; i++) {
//parcurg si fiecare caracter din lista de caractere retinuta
//ca sa vad de care am nevoie
		for (int j = 1; j <= nr_carac; j++) {
//cand gasesc caracterul il desenez propiu-zis
			if (text[i] == date_caracter[j].nume_caracter) {
				if (desen_caracter(&x0, &y0, width, height,
								   R_scris, G_scris, B_scris,
								   img, date_caracter, j) == 1)
					break;
			}
		}
	}
}

void type(int nr_img, int nr_font, int *ultima_operatie,
		  char **string, char **cuvant,
		  char *copie_linie, char *copie_linie2, int *start_x,
		  int *start_y, int width,
		  int height, int *R_scris, int *G_scris, int *B_scris,
		  unsigned char *img,
		  unsigned char *img_text_undo, int numar_caractere,
		  struct caracter *date_caracter)
{
	if (nr_img < 1) {
		printf("No image loaded\n");
	} else if (nr_font < 1) {
		printf("No font loaded\n");
	} else {
		printf("Text written\n");
//retin ca am fc type
		*ultima_operatie = 4;
//caut textul de scris
		*string = strtok(copie_linie, "\"");
		*string = strtok(NULL, "\"");
		*cuvant = strtok(copie_linie2, " ");
		int nr = 1;
//retin ce mai e de salvat din linia citita
		while (nr <= 5) {
			if (*cuvant &&
				(((*cuvant)[0] >= '0' && (*cuvant)[0] <= '9') ||
				(*cuvant)[0] == '-')) {
				if (nr == 1) {
					*start_x = atoi(*cuvant);
					nr++;
				} else if (nr == 2) {
					*start_y = atoi(*cuvant);
					nr++;
				} else if (nr == 3) {
					*R_scris = atoi(*cuvant);
					nr++;
				} else if (nr == 4) {
					*G_scris = atoi(*cuvant);
					nr++;
				} else if (nr == 5) {
					*B_scris = atoi(*cuvant);
					nr++;
				}
			}
			if (nr != 6)
				*cuvant = strtok(NULL, " ");
		}
//retin imaginea in caz ca trb sa fac undo
		for (int j = 0; j < width * height * 3; j++)
			img_text_undo[j] = img[j];
		deseneaza_text(*string, *start_x, *start_y,
					   img, *R_scris, *G_scris, *B_scris,
					   numar_caractere, date_caracter, width, height);
	}
}

int citire(char **linie_font, FILE *font,
		   int *capacitate, int *nr_font, char **nume_font,
		   char *chars, int *numar_caractere)
{
//citesc liniile din font
	if (!fgets(*linie_font, 1000, font))
		return 1;
	int lg_linie = strlen(*linie_font);
	if ((*linie_font)[lg_linie - 1] == '\n') {
		(*linie_font)[lg_linie - 1] = '\0';
		lg_linie--;
	} else {
		while (1) {
//realoc daca nu s-a citit toata linia (nu are caracterul new line la sfarsit)
			*capacitate *= 2;
			char *aux = realloc(*linie_font, (*capacitate) * sizeof(char));
			if (!aux) {
				free(*linie_font);
				exit(1);
			}
			*linie_font = aux;
			lg_linie = strlen(*linie_font);
			if (!fgets(*linie_font + lg_linie, (*capacitate) - lg_linie, font))
				break;
			lg_linie = strlen(*linie_font);
			if ((*linie_font)[lg_linie - 1] == '\n') {
				(*linie_font)[lg_linie - 1] = '\0';
				lg_linie--;
				break;
			}
		}
	}
//afisez numele fontului
	if ((*linie_font)[0] == 'F' && (*linie_font)[1] == 'O' &&
		(*linie_font)[2] == 'N' && (*linie_font)[3] == 'T' &&
		(*linie_font)[4] == ' ') {
		printf("Loaded %s (bitmap font", nume_font[*nr_font]);
		for (int i = 4; i < lg_linie; i++) {
			printf("%c", (*linie_font)[i]);
		}
		printf(")\n");
	}
//caut numarul de caractere
	if ((*linie_font)[0] == 'C' && (*linie_font)[1] == 'H' &&
		(*linie_font)[2] == 'A' && (*linie_font)[3] == 'R' &&
		(*linie_font)[4] == 'S' && (*linie_font)[5] == ' ') {
		strcpy(chars, *linie_font + 6);
		*numar_caractere = atoi(chars);
		return 1;
	}
	return 0;
}

void retinere_font(char **linie_font, FILE *font,
				   struct caracter *date_caracter,
				   int j, int l, int nr_total_biti)
{
	fgets(*linie_font, 1000, font);
	unsigned int toti_bitii = 0;
//citesc bitii si ii transform in int
	if (sscanf(*linie_font, "%x", &toti_bitii) != 1) {
		printf("Invalid inpt");
		exit(1);
	}
	for (int o = 0; o < date_caracter[j].bbw; o++) {
//scot fiecare bit (0 sau 1)
		int bit = (toti_bitii >>
				  (nr_total_biti - 1 - o)) & 1;
//il salvez in bitmap
		date_caracter[j].bitmap[l *
		date_caracter[j].bbw + o] = bit;
	}
}

void font_functie(int *nr_font, int *copie_nr_font, int *anulat,
				  char **nume_font, FILE *font, char **linie_font,
				  int *capacitate, char *chars, int *numar_caractere,
				  struct caracter *date_caracter)
{
	(*nr_font)++;
	*anulat = 0;
	(*copie_nr_font)++;
// daca sunt cu contorul la sfarsit de vector mai
//declar o linie, daca nu o suprascriu pe urm
	if (*nr_font == *copie_nr_font) {
		nume_font[*nr_font] = calloc(100, sizeof(char));
		if (!nume_font[*nr_font]) {
			printf("Eroare la alocare");
			exit(1);
		}
	}
	strcpy(nume_font[*nr_font], strtok(NULL, " "));
	font = fopen(nume_font[*nr_font], "r");
	if (!font) {
		printf("Failed to load %s\n", nume_font[*nr_font]);
	} else {
		while (1) {
			if (citire(linie_font, font, capacitate, nr_font,
					   nume_font, chars, numar_caractere) == 1)
				break;
		}
//retin pt fiecare caracter datele necesare
		for (int j = 1; j <= *numar_caractere; j++) {
			for (int k = 1; k <= 6; k++) {
				fgets(*linie_font, 1000, font);
				if (k == 2) {
					strcpy(chars, *linie_font + 9);
					date_caracter[j].nume_caracter = atoi(chars);
				} else if (k == 4) {
					char *cuv;
					cuv = strtok(*linie_font, " ");
					cuv = strtok(NULL, " ");
					date_caracter[j].dwx = atoi(cuv);
					cuv = strtok(NULL, " ");
					date_caracter[j].dwy = atoi(cuv);
				} else if (k == 5) {
					if (sscanf(*linie_font, "BBX %d %d %d %d",
							   &date_caracter[j].bbw,
							   &date_caracter[j].bbh,
							   &date_caracter[j].bbxoff,
							   &date_caracter[j].bbyoff) != 4) {
						printf("Invalid inpt");
						exit(1);
					}
				} else if (k == 6) {
//retin bitmap-ul
//calculez nr total de biti, rotunjind la urmatorul multiplu de 8
					int nr_total_biti = ((date_caracter[j].bbw + 7) / 8) * 8;
//eliberez si realoc bitmap-ul de fiecare data
//cand recitesc un fond nou pt ca dimensiunile
//pot varia
					if (date_caracter[j].bitmap)
						free(date_caracter[j].bitmap);
					date_caracter[j].bitmap = malloc(date_caracter[j].bbw
					* date_caracter[j].bbh);
					if (!date_caracter[j].bitmap) {
						printf("Eroare la alocare");
						exit(1);
					}
//parcurge fiecare linie din bitmap
					for (int l = 0; l < date_caracter[j].bbh; l++) {
						retinere_font(linie_font, font, date_caracter,
									  j, l, nr_total_biti);
					}
				}
			}
			fgets(*linie_font, 1000, font);
		}
	}
	if (font) {
		fclose(font);
	}
}

void citire_linie(char *linie, char *copie_linie, char *copie_linie2)
{
	fgets(linie, 1000, stdin);
	int n = strlen(linie);
//elimin caracterul new line ca sa pot compara cu strcmp
	if (linie[n - 1] == '\n')
		linie[n - 1] = '\0';
	strcpy(copie_linie, linie);
	strcpy(copie_linie2, linie);
}

int main(void)
{
	int start_x, start_y, R_scris, G_scris, B_scris, nr_font = 0, nrules,
	anulat = 0, copie_numar = 0, nr_img = 0, lung = 100, copie_nr_font = 0,
	lungime = 100, numar = 0, width, height, maxval, ultima_operatie = 0,
	capacitate = 1000, numar_caractere, numar_img = 0, copie_numar_img = 0;
	struct caracter *date_caracter = calloc(1072, sizeof(struct caracter));
	char *axioma = calloc(100, sizeof(char));
	char *linie = calloc(1000, sizeof(char)), magic[3];
	char *copie_axioma = calloc(100, sizeof(char));
	char *linie_font = calloc(1000, sizeof(char));
	char *copie_linie = calloc(1000, sizeof(char));
	char *copie_linie2 = calloc(1000, sizeof(char));
	char *chars = calloc(100, sizeof(char)), *string;
	char **nume_imagine = calloc(100, sizeof(char *));
	char **nume_font = calloc(100, sizeof(char *));
	char **fisier = calloc(100, sizeof(char *));
	if (!axioma || !linie || !copie_axioma || !nume_imagine ||
		!fisier || !date_caracter || !linie_font || !copie_linie ||
		!copie_linie2 || !chars || !nume_font) {
		printf("Eroare la alocare");
		exit(1);
	}
	unsigned char *img = NULL, *img_pt_undo = NULL, *img_pt_redo = NULL;
	unsigned char *img_text_undo = NULL, *img_text_redo = NULL;
	citire_linie(linie, copie_linie, copie_linie2);
	FILE *f = NULL, *imagine = NULL, *font = NULL;
	while (strcmp(linie, "EXIT") != 0) {
		char *cuvant = strtok(linie, " ");
		if (strcmp(cuvant, "LSYSTEM") == 0) {
			lsystem(&numar, &anulat, &copie_numar,
					&ultima_operatie, axioma, &nrules, &f, &fisier);
		}
		if (strcmp(cuvant, "DERIVE") == 0 && f && numar > 0)
			deriv(lungime, axioma, lung, nrules, &copie_axioma);
		if (strcmp(cuvant, "DERIVE") == 0 && (!f || numar < 1))
			printf("No L-system loaded\n");
		if (strcmp(cuvant, "UNDO") == 0) {
			undo_functie(ultima_operatie, &numar_img, &anulat, &width,
						 &nrules, axioma, &numar, &height, magic, f, fisier,
						 nume_imagine, imagine, &maxval, &img, &img_pt_undo,
						 &img_pt_redo, &img_text_undo, &img_text_redo);
		}
		if (strcmp(cuvant, "REDO") == 0) {
			redo(ultima_operatie, &anulat, &numar, fisier, axioma,
				 &nrules, height, f, width, img, img_pt_redo, img_text_redo);
		}
		if (strcmp(cuvant, "LOAD") == 0) {
			load(&numar_img, &anulat, &copie_numar_img, nume_imagine,
				 imagine, &nr_img, &ultima_operatie,
				 &width, &height, &maxval, magic, &img,
				 &img_pt_redo, &img_pt_undo, &img_text_undo, &img_text_redo);
		}
		if (strcmp(cuvant, "TURTLE") == 0) {
			turtle_inceput(&anulat, nr_img, numar,
						   &ultima_operatie, axioma, nrules,
						   &copie_axioma, width, height, img, img_pt_undo, f);
		}
		if (strcmp(cuvant, "SAVE") == 0) {
			save(nr_img, width, height, maxval, img);
		}
		if (strcmp(cuvant, "TYPE") == 0) {
			type(nr_img, nr_font, &ultima_operatie, &string,
				 &cuvant, copie_linie, copie_linie2, &start_x,
				 &start_y, width, height, &R_scris, &G_scris,
				 &B_scris, img, img_text_undo, numar_caractere,
				 date_caracter);
		}
		if (strcmp(cuvant, "FONT") == 0) {
			font_functie(&nr_font, &copie_nr_font, &anulat,
						 nume_font, font, &linie_font, &capacitate,
						 chars, &numar_caractere, date_caracter);
		}
		citire_linie(linie, copie_linie, copie_linie2);
	}
	functie_free(copie_numar, copie_numar_img, &copie_axioma,
				 &linie, &axioma, &fisier, &copie_linie,
				 &nume_imagine, &img, &img_pt_undo, &img_pt_redo, &copie_linie2,
				 &img_text_undo, &img_text_redo, &nume_font, &linie_font,
				 &chars, date_caracter, copie_nr_font);
	return 0;
}
