#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct prijava {
	int broj_indeksa;
	int poeni_prakticni;
	int poeni_usmeni;
	int rok;
} PRIJAVA;

typedef struct cvor CVOR;

typedef struct cvor* PCVOR;

struct cvor {
	PRIJAVA prijava;
	PCVOR sledeci;
};

int ocena(int broj_indeksa, int rok, int info[][4], int n);

int vrati_ocenu(int pismeni, int usmeni) {

	if (pismeni < 51 || usmeni < 51)
	{
		return 5;
	}
	double ukupno = (pismeni + usmeni) / (double)2;

	if (ukupno > 50 && ukupno < 61)
	{
		return 6;
	}
	else if (ukupno > 60 && ukupno < 71)
	{
		return 7;
	}
	else if (ukupno > 70 && ukupno < 81)
	{
		return 8;
	}
	else if (ukupno > 80 && ukupno < 91)
	{
		return 9;
	}
	else {
		return 10;
	}

}

double prosek(char deo_ispita, int rok, int info[][4], int n);

void dodaj(PCVOR* glava, PRIJAVA p);

void ispis_Listu(PCVOR glava);

void kreiraj_listu(int info[][4], int n, PCVOR* glava);

void sortiraj(PCVOR glava);

void pronadji(int rok, PCVOR glava, PRIJAVA* prijava);

void sacuvaj(int rok, char* naziv, PCVOR glava);

int proveri_indeks(int indeks);

int main() {

	int info[100][4] = {
		{20180018, 99, 12, 1},
		{20200001, 52, 76, 2},
		{20100005, 78, 66, 1},
		{20180252, 100, 100, 2} 
	};
	int n = 4;

	/*printf("%d\n", ocena(20200001, 2, info, n));
	printf("%lf\n", prosek('u', 3, info, n));*/
	
	PCVOR glava = NULL;
	kreiraj_listu(info, n, &glava);

	ispis_Listu(glava);
	printf("\n");
	sortiraj(glava);
	ispis_Listu(glava);

	PRIJAVA p;
	pronadji(1, glava, &p);
	printf("%d %d %d %d", p.broj_indeksa, p.poeni_prakticni, p.poeni_usmeni, p.rok);

	//sacuvaj(1, "polozili.txt", glava);

	proveri_indeks(20180252);

}

int ocena(int broj_indeksa, int rok, int info[][4], int n) {

	for (int i = 0; i < n; i++)
	{
		if (info[i][0] == broj_indeksa && info[i][3] == rok)
		{
			int pismeni = info[i][1];
			int usmeni = info[i][2];
			return vrati_ocenu(pismeni, usmeni);


		}
	}
	return 5;
}

double prosek(char deo_ispita, int rok, int info[][4], int n) {

	int kolonaSaBodovima;

	if (deo_ispita == 'p' || deo_ispita == 'P')
	{
		kolonaSaBodovima = 1;
	}
	else if (deo_ispita == 'u' || deo_ispita == 'U')
	{
		kolonaSaBodovima = 2;
	}
	else
	{
		printf("GRESKA niste unei ispravno slovo (p/u)!!!\n");
		return - 1;
	}

	int suma = 0;
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		if (info[i][3] == rok)
		{
			suma += info[i][kolonaSaBodovima];
			brojac++;
		}
		
	}

	if (brojac == 0)
	{
		printf("Niko nije izasao u roku sa datom sifrom %d", rok);
		return -1;
	}
	return (double)suma / brojac;
}

void dodaj(PCVOR* glava, PRIJAVA p){

	PCVOR novi = malloc(sizeof(CVOR));
	novi->prijava = p;
	novi->sledeci = NULL;

	if (*glava == NULL) {

		*glava = novi;
		return;
	}

	PCVOR temp = *glava;
	while (temp->sledeci != NULL) {
		temp = temp->sledeci;
	}
	temp->sledeci = novi;
}

void ispis_Listu(PCVOR glava){

	printf("BrojIndeksa/Pisemni/Usmeni/Rok \n");
	while (glava != NULL) {
		PRIJAVA p = glava->prijava;
		const char* rok;
		if (p.rok == 1) {
			rok = "Januar";
		}
		else if (p.rok == 2) {
			rok = "Februar";
		}
		else if (p.rok == 3) {
			rok = "Jun";
		}
		else if (p.rok == 4) {
			rok = "Jul";
		}
		else if (p.rok == 5) {
			rok = "Septembar";
		}
		else if (p.rok == 6) {
			rok = "Oktobar";
		}
		else {
			rok = "Nepoznat";
		}
		printf("%d / %d / %d / %s\n", p.broj_indeksa, p.poeni_prakticni, p.poeni_usmeni, rok);
		glava = glava->sledeci;
	}

}

void kreiraj_listu(int info[][4], int n, PCVOR* glava) {

	for (int i = 0; i < n; i++)
	{
		PRIJAVA p;
		p.broj_indeksa = info[i][0];
		p.poeni_prakticni = info[i][1];
		p.poeni_usmeni = info[i][2];
		p.rok = info[i][3];
		if (info[i][1] > 50 && info[i][2] > 50)
		{
			dodaj(glava, p);
		}


	}

}

void sortiraj(PCVOR glava){

	for (PCVOR i = glava; i != NULL; i = i->sledeci)
	{
		for (PCVOR j = i; j != NULL; j = j->sledeci)
		{
			double iProsek = (i->prijava.poeni_prakticni + i->prijava.poeni_usmeni) / (double)2;
			double jProsek = (j->prijava.poeni_prakticni + j->prijava.poeni_usmeni) / (double)2;
			if (iProsek < jProsek)
			{
				PRIJAVA temp = i->prijava;
				i->prijava = j->prijava;
				j->prijava = temp;
			}

		}

	}

}

void pronadji(int rok, PCVOR glava, PRIJAVA* prijava) {

	PRIJAVA p;
	p.poeni_prakticni = -1;

	while (glava != NULL) {

		if (glava->prijava.rok == rok && 
			glava->prijava.poeni_prakticni > p.poeni_prakticni)
		{
			p = glava->prijava;
		}
		glava = glava->sledeci;
	}
	if (p.poeni_prakticni == -1)
	{
		return;
	}*prijava = p;
}

void sacuvaj(int rok, char* naziv, PCVOR glava){

	FILE* fajl = fopen(naziv, "w");
	if (fajl == NULL)
	{
		printf("Ne moze se otvoriti fajl");
		return;
	}

	while (glava != NULL) {
		if (glava->prijava.rok == rok)
		{
			fprintf(fajl, "%d\n", glava->prijava.broj_indeksa);
		}
		glava = glava->sledeci;

	}


	fclose(fajl);
}

int proveri_indeks(int indeks)
{
	if (indeks < 10000000 || indeks > 99999999)
	{
		return -1;
	}

	int godina = indeks / 10000;
	int broj = indeks % 10000;
	printf("\n%d/%d", godina, broj);
	if (godina < 2000 || godina > 2022)
	{
		return 0;
	}
	if (broj < 1 || broj > 999)
	{
		return 0;
	}
	return 1;
}
