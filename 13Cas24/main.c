#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor* PCVOR;

typedef struct cvor {
	int broj;
	PCVOR sledeci;
}CVOR;

PCVOR kreirajCvor(int broj) {

	PCVOR novi = malloc(sizeof(CVOR));
	novi->broj = broj;
	novi->sledeci = NULL;
	return novi;
}

void dodajNaPocetak(PCVOR* glava, int broj) {

	PCVOR novi = malloc(sizeof(CVOR));
	novi->broj = broj;
	novi->sledeci = *glava;

	*glava = novi;

}

void ispisiListu(PCVOR glava) {

	while (glava != NULL) {
		printf("%d -> ", glava->broj);
		glava = glava->sledeci;
	}
	printf(" NULL\n");
}

int sumaListe(PCVOR glava) {
	int suma = 0;

	while (glava != NULL) {
		suma += glava->broj;
		glava = glava->sledeci;
	}
	return suma;
}

void izbaciSaPocetka(PCVOR* glava) {

	if (*glava == NULL)
	{
		printf("Lista je prazna!");
		return;
	}

	PCVOR temp = *glava;
	*glava = (*glava)->sledeci;
	free(temp);
}

int duzinaListe(PCVOR glava) {

	int brojac = 0;

	while (glava != NULL) {
		glava = glava->sledeci;
		brojac++;
	}

	if (brojac == 0)
	{
		printf("Lista je prazna!\n");
		return;
	}

	return brojac;

}

void dodajNaKraj(PCVOR* glava, int broj) {

	PCVOR novi = malloc(sizeof(CVOR));
	novi->broj = broj;
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
	//free(temp);

}

void izbaciSaKraja(PCVOR* glava) {

	if (*glava == NULL)
	{
		printf("Lista je prazna!");
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
}

void izbaciSaPozicije(PCVOR* glava, int pozicija) {

	int n = duzinaListe(*glava);
	if (pozicija >=  n || pozicija < 0)
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
	while (pozicija != 1) {
		temp1 = temp1->sledeci;
		pozicija--;
	}

	PCVOR temp2 = temp1->sledeci;
	temp1->sledeci = temp2->sledeci;
	free(temp2);

}

void sortirajListu(PCVOR glava) {

	PCVOR temp1 = glava;
	PCVOR temp2 = glava;
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

int frekvencija(PCVOR glava, int broj) {

	int i = 0;
	while (glava != NULL) {

		if (glava->broj == broj)
		{
			i++;
		}
		glava = glava->sledeci;
	}
	return i;
}

int sviRazliciti(PCVOR glava) {

	PCVOR temp = glava;
	while (glava != NULL) {
		if (frekvencija(glava, glava->broj) != 1)
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
		if (temp->broj == broj) {

			int x = glava->broj;
			glava->broj = temp->broj;
			temp->broj = x;
			return;
		}
		temp = temp->sledeci;
	}

}

void obrisiListu(PCVOR* glava) {

	if (*glava == NULL)
	{
		printf("Lista je prazna!");
		return;
	}

	while (*glava != NULL) {

		PCVOR temp = *glava;
		*glava = (*glava)->sledeci;
		free(temp);

	}

}

int main()  {

	PCVOR glava = NULL;
	dodajNaKraj(&glava, 5);
	dodajNaKraj(&glava, 3);
	dodajNaKraj(&glava, 2);
	dodajNaKraj(&glava, 4);
	ispisiListu(glava);
	
	obrisiListu(&glava);
	ispisiListu(glava);
	
}

