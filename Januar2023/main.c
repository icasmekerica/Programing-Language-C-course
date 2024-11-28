#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cvor CVOR;

typedef struct cvor* PCVOR;

struct cvor {
	PRIJAVA prijava;
	PCVOR sledeci;
};

typedef struct prijava {

	int broj_indeksa;
	int godina_upisa;
	int sifra_predmeta;
	int ocena;

}PRIJAVA;

void procitaj_datoteku(char* naziv, int infor[][4], int* n);

void ispisiMat(int info[][4], int n) {

	for (int i = 0; i < n; i++)
	{
		printf("%d %d %d %d\n", info[i][0], info[i][1], info[i][2], info[i][3]);
	}
	printf("\n");
}

double prosecna_ocena_predmeta(int sifra_predmeta, int infor[][4], int n);

void prikazi(int sifra_predmeta, int info[][4], int n);

void dodaj(PCVOR* glava, int broj_indeksa, int godina_upisa, int ocena, int sifra_predmeta);

int main() {

	int info[20][4];
	int n = 0;
	procitaj_datoteku("ispiti.txt", info, &n);
	ispisiMat(info, n);
	//printf("%.2lf\n", prosecna_ocena_predmeta(2220, info, n));
	//prikazi(1113, info, n);
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