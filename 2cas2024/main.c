#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int main() {
//	int x = 12;
//	printf("Vrednost od x = %d \n", x);
//	printf("Adresa od x = %x \n\n\n", &x);
//
//	int* pX = &x;
//
//	printf("Vrednost od pX = %d \n", pX);
//	printf("Adresa od pX = %x \n", &pX);
//	printf("Najbitnije: *pX = %d", *pX);
//
//	*pX = 33;
//	printf("Vrednost od x = %d\n");
//
//	return 0;
//
//}

//int main() {
//	int x = 12;
//	int* pointer = NULL; 
//
//	printf("x = %d\n", x);
//	pointer = &x;
//	*pointer = 33;
//	printf("x = %d\n", x);
//
//	return 0;
//}

//int saberiDvaBroja(int a, int b) {
//	int rezultat = a + b;
//	return rezultat;
//}
//
//
//int main() {
//	
//	printf("Main\n");
//	int x, y;
//	printf("Unesite 2 integera: ");
//	scanf("%d %d", &x, &y);
//
//	int zbir = saberiDvaBroja(x, y);
//	printf("\n\nZbir = %d\n", zbir);
//
//}

//void ispisiBrojNaKvadrat(int broj) {
//	int kvadrat = broj * broj;
//	printf("kvadrat = %d\n", kvadrat);
//
//}
//
//
//int main() {
//
//	int broj = 12;
//	printf("Broj je: %d\n", broj);
//	ispisiBrojNaKvadrat(broj);
//	printf("Broj je: %d\n", broj);
//}

///*Napisati fukciju koja vraca faktorijel nekog broja,
//izracunati vrednost iyraza x! + (x + 2)! - (2x)!   */
//
//int faktorijel(int broj) {
//
//	int proizvod = 1;
//	for (int i = broj; i >= 1; i--)
//	{
//		proizvod = proizvod * i;
//	}
//
//
//	return proizvod;
//}
//
//int main() {
//	int broj;
//	printf("Upisite broj: ");
//	scanf("%d", &broj);
//	//int fakt = faktorijel(broj);
//	int resenje = faktorijel(broj) + faktorijel(broj + 2) - faktorijel(2 * broj);
//	printf("\n\nFaktorijel je: %d\n", resenje);
//}

/* Napisati kod koji radi zamenu mesta 2 broja, definisati 2 broja prikazati njihove vrednosti prei posle zamene*/



void zamenMesta(int* broj1, int* broj2); //pokazivaci na brojeve

int main() { 

	int broj1 = 12, broj2 = 24;
	printf("Pre promene: broj 1 = %d, broj 2 = %d \n\n", broj1, broj2);

	zamenMesta(&broj1, &broj2);//prosledjujemo adrese

	printf("Posle promene: broj 1 = %d, broj 2 = %d \n\n", broj1, broj2);
}

void zamenMesta(int* broj1, int* broj2) {
	int c = *broj1;
	*broj1 = *broj2;
	*broj2 = c;

}

