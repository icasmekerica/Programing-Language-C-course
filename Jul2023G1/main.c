#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor CVOR;

typedef struct cvor* PCVOR;

typedef struct pitanje {

	int redni_broj;
	char tekst_pitanja[50];
	char tacan_odgovor[20];
	int odgovoreno;
} PITANJE;

struct cvor {
	PITANJE pitanje;
	PCVOR sledeci;
};

void dodaj_u_listu(PITANJE pitanje, PCVOR* glava);

int duzina_liste(PCVOR glava);

void ispisi_listu(PCVOR glava);

void dodaj_pitanje(PCVOR* glava);

void sacuvaj_u_bin_dat(char* naziv, PCVOR glava);

int ucitaj_pitanja_iz_bin_dat(char* naziv, PCVOR* glava);

void pokreni_igru(PCVOR* glava);

void sortiraj(PCVOR glava);

int vrati_broj_odgovorenih(PCVOR glava);

void izbaci_sa_kraja(PCVOR* glava);

void izbaci_odgovorene(PCVOR* glava);

void prikazi_statistiku(PCVOR glava);

int main() {

	PCVOR glava = NULL;
	PITANJE p;
	strcpy(p.tekst_pitanja, "Koja je najbrza zivotinja?");
	strcpy(p.tacan_odgovor, "Gepard");
	dodaj_u_listu(p, &glava);
	
	PITANJE p1;
	strcpy(p1.tekst_pitanja, "Koja je najsporija zivotinja?");
	strcpy(p1.tacan_odgovor, "Kornjaca");
	dodaj_u_listu(p1, &glava);

	PITANJE p2;
	strcpy(p2.tekst_pitanja, "Ko ce da polozi P1?");
	strcpy(p2.tacan_odgovor, "Ica");
	dodaj_u_listu(p2, &glava);

	ispisi_listu(glava);

	pokreni_igru(&glava);
	
	sortiraj(glava);

	ispisi_listu(glava);

	prikazi_statistiku(glava);

	izbaci_odgovorene(&glava);
	ispisi_listu(glava);

	prikazi_statistiku(glava);


	/*sacuvaj_u_bin_dat("pitanja.dat", glava);
	ucitaj_pitanja_iz_bin_dat("pitanja.dat", &glava);
	ispisi_listu(glava);*/

	/*dodaj_pitanje(&glava);
	ispisi_listu(glava);*/
}

void dodaj_u_listu(PITANJE pitanje, PCVOR* glava){

	int duzinaPreDodavanje = duzina_liste(*glava);

	PCVOR novi = malloc(sizeof(CVOR));
	novi->pitanje = pitanje;
	novi->pitanje.odgovoreno = 0;
	novi->pitanje.redni_broj = duzinaPreDodavanje + 1;
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

int duzina_liste(PCVOR glava){
	
	int brojac = 0;
	while (glava != NULL) {
		brojac++;
		glava = glava->sledeci;
	}
	return brojac;
}

void ispisi_listu(PCVOR glava){

	//printf("Vasa lista: \n");
	while (glava != NULL) {

		printf("%d. %s (%d)\n", glava->pitanje.redni_broj, glava->pitanje.tekst_pitanja, glava->pitanje.odgovoreno);
		printf("Ogovor: %s\n\n", glava->pitanje.tacan_odgovor);
		glava = glava->sledeci;
		
	}
	printf("Kraj liste!\n\n");
}

void dodaj_pitanje(PCVOR* glava){

	int unos = 1;
	char pitanje[100];
	char odgovor[100];
	while (unos != -1) {
		printf("Unesite pitanje: \n");
		gets(pitanje);
		printf("Unesite odgovor: \n");
		gets(odgovor);

		int duzinaPitanja = strlen(pitanje);
		char poslednjeSlovo = pitanje[duzinaPitanja - 1];
		char prvoSlovo = pitanje[0];

		if (prvoSlovo >= 'A' && prvoSlovo <= 'Z' && poslednjeSlovo == '?') {
			printf("Dobar unos!\n");
			PITANJE p;
			strcpy(p.tekst_pitanja, pitanje);
			strcpy(p.tacan_odgovor, odgovor);
			dodaj_u_listu(p, glava);
		}
		else
		{
			printf("Nesuspesan unos!\n");
		}

		printf("Da li zelite da uneste jos pitanja? (1 - da, -1 - ne)");
		scanf("%d", &unos);
		getchar();
	}

}

void sacuvaj_u_bin_dat(char* naziv, PCVOR glava){

	FILE* fajl = fopen(naziv, "wb");

	if (fajl == NULL)
	{
		printf("Greska pri otvaranju fajla!\n");
		return;
	}

	while (glava != NULL) {

		fwrite(&glava->pitanje, sizeof(PITANJE), 1, fajl);
		glava = glava->sledeci;
	}
	fclose(fajl);
}

int ucitaj_pitanja_iz_bin_dat(char* naziv, PCVOR* glava){

	*glava = NULL;
	FILE* fajl = fopen(naziv, "rb");

	if (fajl == NULL)
	{
		printf("Greska pri otvaranju fajla!\n");
		return;
	}

	int brojac = 0;
	PITANJE p;
	while (fread(&p, sizeof(PITANJE), 1, fajl) > 0) {
		brojac++;
		dodaj_u_listu(p, glava);

	}
	fclose(fajl);
	return brojac;
}

void pokreni_igru(PCVOR* glava){

	PCVOR temp = *glava;
	char korisnikovOdgovro[100];
	while (temp != NULL) {
		printf("%d. %s\n", temp->pitanje.redni_broj, temp->pitanje.tekst_pitanja);
		printf("Unestie odgovor: \n");
		gets(korisnikovOdgovro);

		if (strcmp(korisnikovOdgovro, temp->pitanje.tacan_odgovor) == 0){

			temp->pitanje.odgovoreno = 1;
			printf("Tacan Odgovor!\n\n");

		}
		else
		{
			printf("GRESKA!\n\n");
		}

		temp = temp->sledeci;
	}

}

void sortiraj(PCVOR glava) {

	for (PCVOR leviCvor = glava; leviCvor != NULL; leviCvor = leviCvor->sledeci){
	
		for (PCVOR desniCvor = leviCvor; desniCvor != NULL; desniCvor = desniCvor->sledeci) {

			if (leviCvor->pitanje.odgovoreno > desniCvor->pitanje.odgovoreno){
				PITANJE temp = leviCvor->pitanje;
				leviCvor->pitanje = desniCvor->pitanje;
				desniCvor->pitanje = temp;

				int temp2 = leviCvor->pitanje.redni_broj;
				leviCvor->pitanje.redni_broj = desniCvor->pitanje.redni_broj;
				desniCvor->pitanje.redni_broj = temp2;

			}

		}

	}

}

int vrati_broj_odgovorenih(PCVOR glava){

	int brojac = 0;
	while (glava != NULL) {
		if (glava->pitanje.odgovoreno == 1)
		{
			brojac++;
		}
		glava = glava->sledeci;
	}
	return brojac;
}

void izbaci_sa_kraja(PCVOR* glava) {
	////ChatGPT verzija
	//if (*glava == NULL) {
	//	printf("Lista je prazna!\n");
	//	return;
	//}
	//// Remove answered nodes from the head of the list
	//while (*glava != NULL && (*glava)->pitanje.odgovoreno == 1) {
	//	PCVOR toDelete = *glava;
	//	*glava = (*glava)->sledeci;
	//	free(toDelete);
	//}
	//// If the list is now empty, we're done
	//if (*glava == NULL) {
	//	printf("Svi odgovori su uklonjeni.\n");
	//	return;
	//}
	//// Remove answered nodes from the rest of the list
	//PCVOR temp = *glava;
	//while (temp->sledeci != NULL) {
	//	if (temp->sledeci->pitanje.odgovoreno == 1) {
	//		PCVOR toDelete = temp->sledeci;
	//		temp->sledeci = temp->sledeci->sledeci;
	//		free(toDelete);
	//	}
	//	else {
	//		temp = temp->sledeci; // Only move to next node if no deletion
	//	}
	//}
	//printf("Odgovoreni cvorovi su uklonjeni.\n");

	if (*glava == NULL){
		return;
	}

	if ((*glava)->sledeci == NULL){
		free(*glava);
		*glava = NULL;
	}

	PCVOR temp = *glava;
	while (temp->sledeci->sledeci != NULL) {
		temp = temp->sledeci;
	}
	free(temp->sledeci);
	temp->sledeci = NULL;


}

void izbaci_odgovorene(PCVOR* glava){

	printf("Netacno odgovorena pitanja: \n");

	int broj_odgovorenih = vrati_broj_odgovorenih(*glava);

	for (int i = 0; i < broj_odgovorenih; i++)
	{
		izbaci_sa_kraja(glava);
	}

}

void prikazi_statistiku(PCVOR glava){

	int odgovorena = vrati_broj_odgovorenih(glava);
	int ukupno = duzina_liste(glava);
	int neodgovorena = ukupno - odgovorena;

	printf("Odgovorena: %d\n", odgovorena);
	printf("Neodgovrena: %d\n", neodgovorena);
	printf("Ukupno: %d\n\n", ukupno);

}
