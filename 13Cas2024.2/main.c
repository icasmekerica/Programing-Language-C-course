#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor* PCVOR;

typedef struct cvor
{
	int broj;
	PCVOR sledeci;
}CVOR;


int pomocnaFunkcija() {
	int* px = malloc(sizeof(int));
	free(px);
}

void ispisiListu(PCVOR glava) {
	while (glava != NULL) {
		printf("%d -> ", glava->broj);
		glava = glava->sledeci;
	}
	printf("NULL \n");
}

PCVOR dodajNaPocetak(PCVOR* glava, int broj) {

	PCVOR novi = malloc(sizeof(CVOR));
	novi->broj = broj;
	novi->sledeci = *glava;
	*glava = novi;

}

void izbaciSaPocetka(PCVOR* glava) {

	if (*glava == NULL)
	{
		return;
	}

	PCVOR temp = *glava;
	*glava = (*glava)->sledeci;
	free(temp);

}

int duzinaListe(PCVOR glava) {

	if (glava == NULL)
	{
		return 0;
	}

	int brojac = 0;
	while (glava != NULL) {
		brojac++;
		glava = glava->sledeci;
	}
	return brojac;
}

PCVOR dodajNaKraj(PCVOR* glava, int broj) {

	PCVOR novi = malloc(sizeof(CVOR));
	novi->broj = broj;
	novi->sledeci = NULL;

	if ((*glava) == NULL)
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

void izbaciSaKraja(PCVOR* glava) {

	if (*glava == NULL)
	{
		return;
	}

	if ((*glava)->sledeci == NULL)
	{
		PCVOR temp = *glava;
		*glava = NULL;
		free(temp);
		return;
	}

	PCVOR temp = *glava;
	while (temp->sledeci->sledeci != NULL) {
		temp = temp->sledeci;
	}
	PCVOR temp2 = temp->sledeci;
	temp->sledeci = NULL;
	free(temp2);
	//free(temp);

}

void izbaciSaPozicije(PCVOR* glava, int pozicija) {

	int n = duzinaListe(*glava);

	if (pozicija >= n || pozicija < 0)
	{
		return;
	}

	if (pozicija == 0)
	{
		PCVOR temp = *glava;
		*glava = (*glava)->sledeci;
		free(temp);
		return;
	}

	PCVOR temp1 = *glava;
	/*while (pozicija != 1) {
		temp1 = temp1->sledeci;
		pozicija--;

	}*/
	for (int i = 0; i < pozicija - 1; i++) {
		temp1 = temp1->sledeci;
	}

	PCVOR temp2 = temp1->sledeci;
	temp1->sledeci = temp2->sledeci;
	free(temp2);

}

void sortirajListu(PCVOR glava) {

	/*int niz[100];
	int n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (niz[i] > niz[j])
			{
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}


		}
	}*/

	PCVOR temp1 = glava;
	PCVOR temp2;
	while (temp1 != NULL) {
		temp2 = temp1;
		while (temp2 != NULL) {

			if (temp1->broj > temp2->broj)
			{
				int x = temp1->broj;
				temp1->broj = temp2->broj;
				temp2->broj = x;
			}
			temp2 = temp2->sledeci;
		}
		temp1 = temp1->sledeci;
	}


}

int pronadjiNajveciBroj(PCVOR glava) {

	if (glava == NULL)
	{
		return INT_MIN;
	}

	int max = glava->broj;
	while (glava != NULL) {
		if (max < glava->broj)
		{
			max = glava->broj;
		}

		glava = glava->sledeci;
	}
	return max;
}

int frekvencija(PCVOR glava, int broj) {

	int brojac = 0;
	while (glava != NULL) {

		if (glava->broj == broj)
		{
			brojac++;
		}
		glava = glava->sledeci;
	}
	return brojac;
}

int sviRazliciti(PCVOR glava) {
	PCVOR temp = glava;
	while (temp != NULL) {

		if (frekvencija(glava, temp->broj) != 1)
		{
			return 0;
		}

		temp = temp->sledeci;
	}
	return 1;
}

void prebaciNaPocetak(int broj, PCVOR glava) {

	PCVOR temp = glava;
	while (temp != NULL) {

		if (temp->broj == broj)
		{
			int x = glava->broj;
			glava->broj = temp->broj;
			temp->broj = x;
			return;
		}
		temp = temp->sledeci;
	}

}

void obrisiListu(PCVOR* glava) {

	while (*glava != NULL) {
		PCVOR temp = *glava;
		*glava = (*glava)->sledeci;
		free(temp);


	}

}

int vratiSaPozicije(PCVOR glava, int pozicija) {

	int n = duzinaListe(glava);
	if (pozicija < 0 || pozicija >= n)
	{
		return -1;
	}

	for (int i = 0; i < pozicija; i++)
	{
		glava = glava->sledeci;
	}
	return glava->broj;
}



int main() {

	PCVOR glava = NULL;
	/*dodajNaPocetak(&glava, 10);
	dodajNaPocetak(&glava, 9);
	ispisiListu(glava);
	printf("%d \n", duzinaListe(glava));
	izbaciSaPocetka(&glava);
	ispisiListu(glava);
	printf("%d \n", duzinaListe(glava));*/

	dodajNaKraj(&glava, 5);
	dodajNaKraj(&glava, 3);
	dodajNaKraj(&glava, 2);
	dodajNaKraj(&glava, 4);
	ispisiListu(glava);

	obrisiListu(&glava);
	ispisiListu(glava);

	/*izbaciSaPozicije(&glava, 7);
	ispisiListu(glava);*/
	

	
}
