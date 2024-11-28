#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int daLiJeDobroIme(char* imeiprezime) {
	int brojac = 0;
	if (strlen(imeiprezime) == 0) {
		return 0;
	}

	if (imeiprezime[0] < 'A' || imeiprezime[0] > 'Z') {
		return 0;
	}
	for (int i = 1; i < strlen(imeiprezime); i++) {
		if (imeiprezime[i] == ' ' && imeiprezime[i + 1] != '\0') {
			brojac++;
			if (imeiprezime[i + 1] < 'A' || imeiprezime[i + 1] > 'Z') {
				return 0;
			}
		}
	}
	if (brojac > 1) {
		return 1;
	}
	return 0;
}

typedef struct knjiga {
	char isbn[18];
	double cena;
	char naziv[50];
	char imeIPrezimeAutora[50];
} KNJIGA;

typedef struct cvor* PCVOR;

struct cvor {
	KNJIGA info;
	PCVOR sledeci;
} CVOR;

KNJIGA vratiKnjigu() {
	KNJIGA k;

	while (1) {
		printf("Unesite isbn: ");
		gets(k.isbn);
		printf("Unesite naziv: ");
		gets(k.naziv);
		printf("Unesite ime autora: ");
		gets(k.imeIPrezimeAutora);
		printf("Unesite cenu: ");
		scanf("%lf", &k.cena);
		getchar();

		if (k.cena > 0 && daLiJeDobroIme(k.imeIPrezimeAutora) == 1) {
			printf("Knjiga je uspesno uneta!\n");
			break;
		}
		printf("Greska pri unosu. Pokusajte ponovo.\n");
	}
	return k;
}

void ispisiKnjigu(KNJIGA k) {
	printf("%s, %s, %s, %.2lf \n", k.isbn, k.naziv, k.imeIPrezimeAutora, k.cena);
}

void ubaciNaKraj(PCVOR* glava, KNJIGA k) {

	PCVOR novi = malloc(sizeof(CVOR));
	novi->info = k;
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
	temp = temp->sledeci;
}

void prikazi(PCVOR glava) {

	glava = NULL;
	while (glava != NULL) {

		ispisiKnjigu(glava->info);
		glava = glava->sledeci;

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

	int len = strlen(sifra);

	if (len < 6 || len > 7) {
		return 0;
	}

	for (int i = 0; i < 4; i++) {
		if (!isDigit(sifra[i])) {
			return 0;
		}
	}

	// Check specific patterns based on length
	if (len == 6) {
		if ((sifra[4] == 'R' && sifra[5] == 'S') ||
			(sifra[4] == 'E' && sifra[5] == 'U')) {
			return 1;
		}
		return 0;  // Reject all other 6-character patterns
	}

	if (len == 7) {
		if ((sifra[4] == 'P' && sifra[5] == 'R' && sifra[6] == 'C') ||
			(sifra[4] == 'U' && sifra[5] == 'S' && sifra[6] == 'A') ||
			(sifra[4] == 'A' && sifra[5] == 'U' && sifra[6] == 'S')) {
			return 1;
		}
		return 0;  // Reject all other 7-character patterns
	}

	return 0;
}

int main() {
	printf("%d\n", proveriSifru("0128USA"));
	
}



