#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct karta {
	char naziv[50];
	int izdrzljivost;
	int napad;
}KARTA;

typedef struct knjiga {
	char isbn[18];
	double cena;
	char naziv[50];
	char imeIPrezimeAutora[50];
}KNJIGA;

typedef struct cvor* PCVOR;

typedef struct cvor {
	//KNJIGA info;
	KARTA info;
	PCVOR sledeci;
}CVOR;

int daLiJeDobroIme(char* imeiprezime) {

	if (strlen(imeiprezime) == 0)
	{
		return 0;
	}

	if (imeiprezime[0] < 'A' || imeiprezime[0] > 'Z') {
		return 0;
	}

	for (int i = 1; i < strlen(imeiprezime); i++)
	{
		if (imeiprezime[i] == ' ' && imeiprezime[i + 1] != '\0')
		{	
	
			if (imeiprezime[i + 1] < 'A' || imeiprezime[i + 1] > 'Z')
			{
				return 0;
			}
		}
	}

	return 1;
	

}

int proveriKartu(KARTA karta) {

	if (karta.izdrzljivost < 1 || karta.izdrzljivost > 10)
	{
		return 0;
	}
	if (karta.napad < 1 || karta.napad > 10)
	{
		return 0;
	}
	if (daLiJeDobroIme(karta.naziv) == 0)
	{
		return 0;
	}
	return 1;
}

int jedinstvenoIme(KARTA k, PCVOR spil) {
	while (spil != NULL) {
		if (strcmp(k.naziv, spil->info.naziv) == 0) {
			return 0;
		}
		spil = spil->sledeci; 
	}
	return 1;
}

int dodajKartu(KARTA karta, PCVOR* spil) {

	if (proveriKartu(karta) == 0 || !jedinstvenoIme(karta, *spil))
	{
		return 0;
	}

	PCVOR novi = malloc(sizeof(CVOR));
	novi->info = karta;
	novi->sledeci = *spil;
	*spil = novi;
	return 1;

}
void ispisiSpil(PCVOR spil) {
	while (spil != NULL) {
		printf("%s %d %d\n", spil->info.naziv, spil->info.napad, spil->info.izdrzljivost);
		spil = spil->sledeci;
	}
}

int isDigit(char karakter) {

	if (karakter < '0' || karakter > '9')
	{
		return 0;
	}
	return 1;
}

int proveriSifru(char* sifra) {

	if (strlen(sifra) < 6 || strlen(sifra) > 7)
	{
		return 0;
	}

	if (!isDigit(sifra[0]) || !isDigit(sifra[0]) || 
		!isDigit(sifra[0]) || !isDigit(sifra[0]))
	{
		return 0;
	}

	if (sifra[4] == 'R' && sifra[5] == 'S')
	{
		return 1;
	}
	if (sifra[4] == 'E' && sifra[5] == 'U')
	{
		return 1;
	}
	if (sifra[4] == 'P' && sifra[5] == 'R' && sifra[6] == 'C')
	{
		return 1;
	}
	if (sifra[4] == 'U' && sifra[5] == 'S' && sifra[6] == 'A')
	{
		return 1;
	}
	if (sifra[4] == 'A' && sifra[5] == 'U' && sifra[6] == 'S')
	{
		return 1;
	}
	return 0;
}

KNJIGA vratiKnjigu() {

	KNJIGA k;

	while (10) {
		printf("Unesite isbn: ");
		gets(k.isbn);
		printf("Unesite naziv: ");
		gets(k.naziv);
		printf("Unesite ime autora: ");
		gets(k.imeIPrezimeAutora);
		printf("Unesite cenu: ");
		scanf("%lf", &k.cena);
		getchar();

		if (k.cena > 0 && daLiJeDobroIme(k.imeIPrezimeAutora) == 1)
		{
			break;
		}
		printf("Greska pri unosu!\n");
	}
	return k;

}

void ispisiKnjigu(KNJIGA k) {
	printf("%s %s %s %.2lf\n", k.isbn, k.naziv, k.imeIPrezimeAutora, k.cena);
}

PCVOR dodajNaKraj(PCVOR* glava, KNJIGA k) {

	PCVOR novi = malloc(sizeof(CVOR));
	novi->info = k;
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

void prikazi(PCVOR glava) {

	while (glava != NULL) {
		ispisiKnjigu(glava->info);
		glava = glava->sledeci;
	}
	printf("\n");
}

void zadatak2(PCVOR* glava) {

	while (1) {
		char unos;
		KNJIGA k = vratiKnjigu();
		dodajNaKraj(&glava, k);
		printf("Da li zelite da uneste ponovo knjigu (d/n): ");
		scanf("$c", &unos);

		if (unos == 'n') {
			break;
		}

	}

}

int main() {
	/*PCVOR glava = NULL;
	KNJIGA k = {"31233333", 300, "ZlociniKazna", "Fjodor Dostojevski"};
	KNJIGA k1 = { "68718781274", 600, "GlociniMazna", "Bjodor Hostojevski" };
	KNJIGA k2 = { "219839128391", 800, "ClociniPrazna", "Pjodor Grofstojevski" };
	dodajNaKraj(&glava, k);
	dodajNaKraj(&glava, k1);
	prikazi(glava);
	dodajNaKraj(&glava, k2);
	prikazi(glava);*/

	//printf("%d", proveriSifru("0128G"));
	PCVOR spil = NULL;
	KARTA k1 = { "Ica DA", 7, 9 };
	KARTA k2 = { "Ica SA", 8, 9 };
	dodajKartu(k1, &spil);
	dodajKartu(k2, &spil);
	ispisiSpil(spil);
}