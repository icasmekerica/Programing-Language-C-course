#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void upisiUFajl() {
	FILE* datoteka = fopen("proizvodi.txt", "w");
	if (datoteka == NULL)
	{
		printf("Greska!");
		return;
	}

	char naziv[20];
	double cena;
	char znak;

	do
	{	
		
		printf("Unesite naziv proizvoda: ");
		gets(naziv);
		fprintf(datoteka, "%s - ", naziv);
		printf("Unesite cenu proizvoda: ");
		scanf("%lf", &cena);
		getchar();
		fprintf(datoteka, "%.2lf\n", cena);
		printf("Da li zelite da unesete novi proizvod (d/n): ");
		znak = getchar();
		getchar();
	
	} while (znak != 'n');
	fclose(datoteka);
}

void upisiUFajl2() {
	FILE* datoteka = fopen("proizvodi.txt", "w");
	if (datoteka == NULL)
	{
		printf("Greska!");
		return;
	}

	char naziv[20];
	double cena;
	char znak;

	do
	{

		printf("Unesite naziv proizvoda: ");
		gets(naziv);
		fputs(naziv, datoteka);
		fputs(" - ", datoteka);
		//fprintf(datoteka, "%s - ", naziv);
		printf("Unesite cenu proizvoda: ");
		scanf("%lf", &cena);
		getchar();
		//fputs(cena, datoteka);
		//fputs("\n", datoteka);
		fprintf(datoteka, "%.2lf\n", cena);
		printf("Da li zelite da unesete novi proizvod (d/n): ");
		znak = getchar();
		getchar();

	} while (znak != 'n');
	fclose(datoteka);
}

void procitajIzFajla() {

	FILE* datoteka = fopen("proizvodi.txt", "r");
	if (datoteka == NULL)
	{
		printf("GRESKA U OTVARNJU FAJLA");
		return;
	}
	char znak;
	/*while (!feof(datoteka)) {
		znak = fgetc(datoteka);
		fprintf(stdout, "%c", znak);
	}
	//Nacin 2
	while ((znak = fgetc(datoteka)) != EOF) {
		printf("%c", znak);
	}
	*/
	while (1) {
		znak = fgetc(datoteka);
		if (znak == EOF)
		{
			break;
		}
		printf("%c", znak);
	}
	fclose(datoteka);
}

void procitajIzFalja2() {

	FILE* datoteka = fopen("proizvodi.txt", "r");
	if (datoteka == NULL)
	{
		printf("GRESKA U OTVARNJU FAJLA");
		return;
	}
	char red[100];
	//nacin 1
	//while (!feof(datoteka)) {
	//	fgets(red, 100, datoteka);
	//	printf("%s", red);
	//}
	while (fgets(red, 100, datoteka) != NULL) {
		printf("%s", red);
	}
	fclose(datoteka);
}

void procitajIzFalja3() {

	FILE* datoteka = fopen("proizvodi.txt", "r");
	if (datoteka == NULL)
	{
		printf("GRESKA U OTVARANJU FAJLA");
		return;
	}

	char red[100];  // Buffer for reading lines from the file
	char naziv[100];  // Buffer for storing product name
	double cena;      // Variable for storing price

	while (fgets(red, 100, datoteka) != NULL) {
		// Parsing the line to extract the product name and price
		sscanf(red, "%[^-] - %lf", naziv, &cena);
		printf("Naziv: %s, Cena: %.2lf\n", naziv, cena);
	}

	fclose(datoteka);
}

void main() {

	procitajIzFalja3();

}
