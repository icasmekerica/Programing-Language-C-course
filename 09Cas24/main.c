#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	char broj[20];
	char naziv[100];
}STRUKTURA;

void ukloniNoviRed(char string[]) {

	int duzinaStringa = strlen(string);
	if (duzinaStringa == 0)
	{
		return;
	}
	if (string[duzinaStringa - 1] == '\n')
	{
		string[duzinaStringa - 1] = '\0';
	}
}

void ispisiNiz(STRUKTURA niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		STRUKTURA s = niz[i];
		printf("%d\t%s\t%s\n", s.id, s.broj, s.naziv);
	}

}

void ispisNizInta(int niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", niz[i]);
	}
}

void ucitaj_iz_dat_1(char naziv[], STRUKTURA niz[], int* n) {

	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL)
	{
		return;
	}

	STRUKTURA s;
	while (fscanf(fajl, "%d\n", &s.id) != EOF) {
		fgets(s.broj, 20, fajl);
		ukloniNoviRed(s.broj);
		fgets(s.naziv, 50, fajl);
		ukloniNoviRed(s.naziv);
		niz[*n] = s;
		(*n)++;
	}

	fclose(fajl);
}

void ucitaj_iz_dat_2(char naziv[], int niz[], int* n) {

	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL)
	{
		return;
	}

	int s;
	while (fscanf(fajl, "%d\n", &s) != EOF) {
		niz[*n] = s;
		(*n)++;
	}

	fclose(fajl);
}

void ucitaj_iz_dat_3(char naziv[], STRUKTURA niz[], int* n) {

	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL)
	{
		return;
	}

	STRUKTURA s;
	while (fgets(s.broj, 20, fajl) != NULL) {
		ukloniNoviRed(s.broj);
		fgets(s.naziv, 50, fajl);
		fscanf(fajl, "%d\n", &s.id);
		ukloniNoviRed(s.naziv);
		niz[*n] = s;
		(*n)++;
	}

	fclose(fajl);
}

STRUKTURA podeliRed(char red[]) {
	const char s[2] = ",";
	char* token;
	int i = 0;

	token = strtok(red, s);

	STRUKTURA temp;

	while (token != NULL) {
		if (i == 0) {
			strcpy(temp.broj, token);
		}
		if (i == 1) {
			strcpy(temp.naziv, token);
		}
		if (i == 2) {
			sscanf(token, "%d", &temp.id);
		}
		token = strtok(NULL, s);
		i++;
	}
	return temp;
}

void ucitaj_iz_dat_4(char naziv[], STRUKTURA niz[], int* n) {
	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL) {
		printf("GRESKA U OTVARANJU FAJLA");
		return;
	}

	char red[150];
	while (fgets(red, 150, fajl) != NULL) {
		printf("%s", red);
		STRUKTURA s = podeliRed(red);
		niz[*n] = s;
		(*n)++;
	}

	fclose(fajl);
}



void main() {

	/*STRUKTURA niz1[100];
	int n = 0;
	ucitaj_iz_dat_1("tip1.txt", niz1, &n);
	ispisiNiz(niz1, n);*/
	/*int niz2[100];
	int n = 0;
	ucitaj_iz_dat_2("tip2.txt", niz2, &n);
	ispisNizInta(niz2, n);*/
	/*STRUKTURA niz3[100];
	int n = 0;
	ucitaj_iz_dat_3("tip3.txt", niz3, &n);
	ispisiNiz(niz3, n);*/

	STRUKTURA niz4[100];
	int n = 0;
	ucitaj_iz_dat_4("tip4.txt", niz4, &n);
	ispisiNiz(niz4, n);
	return 0;
}
