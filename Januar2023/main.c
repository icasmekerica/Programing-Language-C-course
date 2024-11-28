#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void procitaj_datoteku(char* naziv, int infor[][4], int* n);

void ispisiMat(int info[][4], int n) {

	for (int i = 0; i < n; i++)
	{
		printf("%d %d %d %d\n", info[i][0], info[i][1], info[i][2], info[i][3]);
	}

}

double prosecna_ocena_predmeta(int sifra_predmeta, int infor[][4], int n);

int main() {

	int info[20][4];
	int n = 0;
	procitaj_datoteku("ispiti.txt", info, &n);
	ispisiMat(info, n);
	printf("%.2lf\n", prosecna_ocena_predmeta(2220, info, n));

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

