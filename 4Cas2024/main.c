#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisiNiza(int niz[], int n) {
	
	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");

}

int sumaNiza(int niz[],int n) {

	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma = suma + niz[i];
	}
	return suma;
}

int srednjaVrednost(int niz[], int n) {

	int suma = 0;
	int srednjaVrednost = 0;
	for (int i = 0; i < n; i++)
	{
		suma = suma + niz[i];
	}
	if (n == 0)
	{
		printf("Niz je prazan!!!");
		return -1;
	}
	return suma / n;
}

double srednjaVrednostd(int niz[], int n) {

	int suma = 0;
	int srednjaVrednost = 0;
	for (int i = 0; i < n; i++)
	{
		suma = suma + niz[i];
	}
	if (n == 0)
	{
		printf("Niz je prazan!!!");
		return -1;
	}
	return (double)suma / n;
}

int daLiPostojiBrojUNizu(int niz[], int n, int broj) {

	for (int i = 0; i < n; i++)
	{
		if (niz[i] == broj)
		{
			return 1;
		}
	}
	return 0;
}

int frekvencijaBroja(int niz[], int n, int broj) {
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == broj)
		{
			brojac++;
		}
	}
	return brojac;
}

double srednjaVrednostdNeparnih(int niz[], int n) {

	int suma = 0;
	int srednjaVrednost = 0;
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 2 == 1)
		{
			suma = suma + niz[i];
			brojac++;
		}
	}
	if (n == 0)
	{
		printf("Nema neparnih!!!");
		return -1;
	}
	return (double)suma / brojac;
}

int maxNiza(int niz[], int n) {

	if (n == 0)
	{
		printf("Niz je prazan!");
		return -1;
	}

	int maxNiza = niz[0];
	for (int i = 0; i < n; i++)
	{
		if (niz[i] > maxNiza)
		{
			maxNiza = niz[i];
		}
	}
	return maxNiza;
}

int minNiza(int niz[], int n) {
	if (n == 0)
	{
		printf("Niz je prazan!");
		return -1;
	}

	int minNiza = niz[0];
	for (int i = 0; i < n; i++)
	{
		if (niz[i] < minNiza)
		{
			minNiza = niz[i];
		}
	}
	return minNiza;
}

int prviNeparanBrojNiza(int niz[], int n) {

	int neparanBroj;

	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 2 == 1)
		{
			neparanBroj = niz[i];
			return neparanBroj;
		}
	}
	return 0;
}

int maxNeparanNiza(int niz[], int n) {

	if (n == 0)
	{
		printf("Niz je prazan!");
		return -1;
	}

	int maxNiza = prviNeparanBrojNiza(niz, n);

	for (int i = 0; i < n; i++)
	{
		if (niz[i] > maxNiza && niz[i] % 2 == 1)
		{
			maxNiza = niz[i];
		}
	}
	return maxNiza;
}

void dodajNaKraj(int niz[], int* n, int broj) {
	niz[*n] = broj;
	(*n)++;

}

void formirajNiz2(int niz1[], int n1, int niz2[], int *n2) {
	*n2 = 0;
	for (int i = 0; i < n1; i++)
	{
		int trenutni = niz1[i];
		if (frekvencijaBroja(niz1, n1, trenutni) == 1)
		{
			dodajNaKraj(niz2, n2, trenutni); 
		}
	}


}

void dodajNaPocetak(int niz[], int* n, int broj) {
	for (int i = *n; i > 0; i--) {
		niz[i] = niz[i - 1];
	}
	niz[0] = broj;
	(*n)++; 
}

void dodajNaItoMesto(int niz[], int* n, int broj, int mesto) {
	for (int i = *n; i > mesto; i--) {
		niz[i] = niz[i - 1];
	}
	niz[mesto] = broj;
	(*n)++;
}

void izbaciClanaSaKraja(int niz[], int* n) {

	if (*n ==0)
	{
		return;
	}

	(*n)--;

}

void izbaciClanaSaPocetka(int niz[], int* n) {

	if (*n == 0)
	{
		return;
	}

	for (int i = 0; i < *n-1; i++) {
		niz[i] = niz[i + 1];
	}
	(*n)--;
}

void inicijalizuj_niz(int* niz, int* n) {

	*n = 0;

	while (1) {
		int broj;
		printf("Unesite broj: ");
		scanf("%d", &broj);
		if (broj == 0)
		{
			break;
		}
		niz[*n] = broj;
		(*n)++;
	}

}

void prikazi_jedinstvene(int* niz, int n) {

	printf("Jedinstveni: \n");

	for (int i = 0; i < n; i++)
	{
		if (frekvencijaBroja(niz, n, niz[i]) == 1)
		{
			printf("%d\n", niz[i]);
		}


	}

}

void sortiraj_niz(int niz[], int n) {

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (niz[i] > niz[j])
			{
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
	}

}

void kreiraj_sort(int* niz1, int n1, int* niz2, int n2, int* novi, int* nnovi) {

	*nnovi = 0;

	//prodji kroz prvi niz
	for (int i = 0; i < n1; i++)
	{
		novi[*nnovi] = niz1[i];
		(*nnovi)++;
	}
	//prodji kroz drugi niz
	for (int i = 0; i < n2; i++)
	{
		novi[*nnovi] = niz2[i];
		(*nnovi)++;
	}
	sortiraj_niz(novi, *nnovi);
}

int najmanja_razlika(int* niz, int n, int* broj1, int* broj2) {

	int minRazlika;
	if (niz[1] - niz[0] >= 0)
	{
		minRazlika = niz[1] - niz[0];
		*broj2 = niz[1];
		*broj1 = niz[0];
	}
	else
	{
		minRazlika = niz[0] - niz[1];
		*broj2 = niz[0];
		*broj1 = niz[1];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int trenutnaRazlika = niz[i] - niz[j];
			if (i != j && trenutnaRazlika >= 0 && minRazlika > trenutnaRazlika)
			{
				minRazlika = trenutnaRazlika;
				*broj2 = niz[i];
				*broj1 = niz[j];
			}

		}
	}

}

int main() {
	printf("Nizovi: \n");

	int niz[100] = { 1, 23, 17, 10, 4, 16};
	int n = 6;
	int broj1, broj2;
	najmanja_razlika(niz, n, &broj1, &broj2);

	printf("broj1 = %d  \t broj2 = %d\n\n", broj1, broj2); 

	/*int niz1[100] = { 1, 5, 2, 9, 3};
	int n1 = 5;
	int niz2[100] = { 1, 8, 5, 4, 2, 10};
	int n2 = 6;

	int niz3[100];
	int n3 = 0;

	kreiraj_sort(niz1, n1, niz2, n2, niz3, &n3);
	ispisiNiza(niz3, n3);*/

	//ispisiNiza(niz, n);
	//inicijalizuj_niz(niz, &n);
	//ispisiNiza(niz, n);

	//prikazi_jedinstvene(niz, n);




	/*int nizGodina[100] = { 19, 20, 21, 17, 20, 21, 23 };
	int niz2[100] = { 1, 2, 3 };
	int n = 7;
	int n2 = 3;
	int broj = 21;

	ispisiNiza(nizGodina, n);
	dodajNaPocetak(nizGodina, &n, 38);
	ispisiNiza(nizGodina, n);
	izbaciClanaSaPocetka(nizGodina, &n);
	ispisiNiza(nizGodina, n);*/
	/*formirajNiz2(nizGodina, n, niz2, &n2);
	ispisiNiza(niz2, n2);*/
	//printf("\nSuma niza je: %d\n", sumaNiza(nizGodina, n));
	//printf("\nSrednja vrednost (int) niza je: %d\n", srednjaVrednost(nizGodina, n));
	//printf("Srednja vrednost niza je: %.3lf\n", srednjaVrednostd(nizGodina, n));
	//printf("\nBroj %d, je u nizu[%d]\n", broj, daLiPostojiBrojUNizu(nizGodina, n, broj));
	//if (daLiPostojiBrojUNizu(nizGodina, n, broj) == 1)
	//{
	//	printf("\nBroj %d, postoji u nizu!\n", broj);
	//}
	//else
	//{
	//	printf("\nBroj %d, NE postoji u nizu!\n", broj);
	//}
	//if (frekvencijaBroja(nizGodina, n, broj) == 0)
	//{
	//	printf("\nBroj %d, ne postoji u nizu!\n", broj);
	//}
	//else
	//{
	//	printf("\nBroj %d, se pojavljuje %d puta u nizu!\n", broj, frekvencijaBroja(nizGodina, n, broj));
	//}
	//printf("\nSrednja vrednost Neparnih niza je: %.3lf\n", srednjaVrednostdNeparnih(nizGodina, n));
	////printf("\nMax vrednost niza je: %d\n", maxNiza(nizGodina, n));
	////printf("Min vrednost niza je: %d\n", minNiza(nizGodina, n));
	//printf("Max neparna vrednost niza je: %d\n", maxNeparanNiza(nizGodina, n));

}




