#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct prijava {

	int broj_indeksa;
	int godina_upisa;
	int sifra_predmeta;
	int ocena;

}PRIJAVA;

typedef struct cvor CVOR;

typedef struct cvor* PCVOR;

struct cvor {
	PRIJAVA prijava;
	PCVOR sledeci;
};

void procitaj_datoteku(char* naziv, int infor[][4], int* n);

void ispisiMat(int info[][4], int n) {

	for (int i = 0; i < n; i++)
	{
		printf("%d %d %d %d\n", info[i][0], info[i][1], info[i][2], info[i][3]);
	}
	printf("\n");
}

void ispisiListu(PCVOR glava) {

	while (glava != NULL) {
		printf("%d/%d %d ==> %d \n", glava->prijava.broj_indeksa, glava->prijava.godina_upisa,
			glava->prijava.sifra_predmeta, glava->prijava.ocena);
			glava = glava->sledeci;
	}
	printf("\n");
}

double prosecna_ocena_predmeta(int sifra_predmeta, int infor[][4], int n);

void prikazi(int sifra_predmeta, int info[][4], int n);

void dodaj(PCVOR* glava, int broj_indeksa, int godina_upisa, int ocena, int sifra_predmeta);

int da_li_postoji(PCVOR glava, int broj_indeksa, int godina_upisa, int sifra_predmeta);

void kreiraj_listu(int info[][4], int godina_upisa, PCVOR* glava, int n);

int main() {

	int info[20][4];
	int n = 0;
	procitaj_datoteku("ispiti.txt", info, &n);
	ispisiMat(info, n);
	//printf("%.2lf\n", prosecna_ocena_predmeta(2220, info, n));
	//prikazi(1113, info, n);

	PCVOR* glava = NULL;
	/*dodaj(&glava, 252, 2018, 10, 1113);
	dodaj(&glava, 25, 2016, 7, 1113);
	dodaj(&glava, 52, 2018, 8, 1113);
	dodaj(&glava, 2152, 2019, 9, 1113);*/
	//ispisiListu(glava);
	//printf("%d", da_li_postoji(glava, 252, 2018, 2211));
	kreiraj_listu(info, 2019, &glava, n);
	ispisiListu(glava);

}

void procitaj_datoteku(char* naziv, int info[][4], int* n) {

	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL)
	{
		printf("Greska prilikom otvaranja fajla\n"); 
		return;
	}

	*n = 0;
	//fsacanf vraca EOF kad dodje do kraja, fgets vraca NULL kad dodje do kraja
	while (fscanf(fajl, "%d %d %d %d", &info[*n][0], &info[*n][1], &info[*n][2], &info[*n][3]) != EOF) {
		(*n)++;

	}


	fclose(fajl);
}

double prosecna_ocena_predmeta(int sifra_predmeta, int info[][4], int n) {

	int suma = 0;
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		if (info[i][2] == sifra_predmeta)
		{
			suma += info[i][3];
			brojac++;
		}
	}
	if (brojac == 0)
	{
		return -1;
	}

	return (double)suma / brojac;

}

void prikazi(int sifra_predmeta, int info[][4], int n) {
	int brojac = 1;
	for (int i = 0; i < n; i++)
	{
		if (info[i][2] == sifra_predmeta && info[i][3] > 5 && info[i][3] <= 10)
		{
			printf("%d. %d/%d %d %d\n", brojac, info[i][1], info[i][0], sifra_predmeta, info[i][3]);
				brojac++;
		}
	}


}

void dodaj(PCVOR* glava, int broj_indeksa, int godina_upisa, int ocena, int sifra_predmeta) {

	PCVOR novi = malloc(sizeof(CVOR));
	PRIJAVA p;
	p.broj_indeksa = broj_indeksa;
	p.godina_upisa = godina_upisa;
	p.ocena = ocena;
	p.sifra_predmeta = sifra_predmeta;

	novi->prijava = p;
	novi->sledeci = NULL;

	if (*glava == NULL)
	{
		*glava = novi;
		return;
	}

	PCVOR temp = *glava;
	while (temp->sledeci != NULL) {
		temp = temp->sledeci;
	}
	temp->sledeci = novi;

}

int da_li_postoji(PCVOR glava, int broj_indeksa, int godina_upisa, int sifra_predmeta) {

	while (glava != NULL) {

		if (glava->prijava.broj_indeksa == broj_indeksa &&
			glava->prijava.godina_upisa == godina_upisa &&
			glava->prijava.sifra_predmeta == sifra_predmeta &&
			glava->prijava.ocena >= 6 &&
			glava->prijava.ocena <= 10)
		{
			return glava->prijava.ocena;
		}
		glava = glava->sledeci;
	}
	return -1;
}

void kreiraj_listu(int info[][4], int godina_upisa, PCVOR* glava, int n) {

	for (int i = 0; i < n; i++)
	{
		int trenBroj = info[i][0];
		int trenPred = info[i][2];
		int trenOcena = info[i][3];

		if (info[i][1] == godina_upisa)
		{
			if (da_li_postoji(*glava, trenBroj, godina_upisa, trenPred) == -1)
			{
				dodaj(glava, trenBroj, godina_upisa, trenOcena, trenPred);
			}
		}
	}

}