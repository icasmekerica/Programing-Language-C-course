#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define CAP 10


void ispisi_matricu_obicnu(int matrica[][CAP], int n, int m) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", matrica[i][j]);
		}
		printf("\n");
	}


}

void ispisi_matricu(int matrica[][CAP], int n) {

	printf("Matrica: \n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrica[i][j]);
		}
		printf("\n");
	}


}

void ucitaj_matricu(int mat[10][10], int* n) {

	printf("Dimenzija kvadraten matrice: ");
	scanf("%d", n);

	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			printf("mat[%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}


}

int izracunaj_zbir_kolone(int j, int mat[10][10], int n) {

	int suma = 0;

	for (int i = 0; i < n; i++)
	{
		suma = suma + mat[i][j];
	}
	return suma;
}

int izracunaj_zbir_reda(int i, int mat[10][10], int n) {

	int suma = 0;

	for (int j = 0; j < n; j++)
	{
		suma = suma + mat[i][j];
	}
	return suma;
}

void dodaj_zbirove(int mat[10][10], int* n) {
	int poslednjaSuma = 0;
	for (int i = 0; i < *n; i++)
	{
		int zbirReda = izracunaj_zbir_reda(i, mat, *n);
		int zbirKolone = izracunaj_zbir_kolone(i, mat, *n);
		mat[i][*n] = zbirReda;
		mat[*n][i] = zbirKolone;
		poslednjaSuma += zbirKolone;
	}
	mat[*n][*n] = poslednjaSuma;
	(*n)++;
}

void prikazi(int mat[10][10], int n) {

	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			for (int i = 0; i < (n + 2) * 4; i++)
			{
				printf("=");
			}
			printf("\n");
		}

		for (int j = 0; j < n; j++)
		{
			if (j == n -1)
			{
				printf("| ");
			}
			printf("%4d ", mat[i][j]);
		}

		printf("\n");
	}

}

//142. Дата је квадратна матрица целих бројева М димензије nXn.Имплементирати функцију која 
//формира низ од елемената главне дијагонале тако да у низу не буде понављања.

int frekvencija(int niz[], int n, int broj) {

	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == brojac)
		{
			brojac++;
		}
	}
	return brojac;
}

void ispisiNiz(int niz[], int dimN) {

	for (int i = 0; i < dimN; i++)
	{
		printf("%d  ", niz[i]);
	}
	printf("\n");
}

void formirajNizOdGlavneDiag(int mat[10][10], int n, int niz[], int* dimN) {

	*dimN = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j && frekvencija(niz, *dimN, mat[i][j]) == 0)
			{
				niz[*dimN] = mat[i][j];
				(*dimN)++;
			}
		}
	}


}

int sumaIznadGlavneDig(int mat[10][10], int n) {

	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
			{
				suma += mat[i][j];
			}
		}
	}
	return suma;
}

int sumaIspodGlavneDig(int mat[10][10], int n) {

	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j)
			{
				suma += mat[i][j];
			}
		}
	}
	return suma;
}

/*Nadji max na sporednoj dijagonali*/

int maxNaSporednoj(int mat[10][10], int n) {
	int max = mat[0][n - 1];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == n-1 && max < mat[i][j])
			{
				max = mat[i][j];
			}
		}
	}

	return max;
}

void prikaziIznadSporedne(int mat[10][10], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j < n - 1) {
				printf("%d\t", mat[i][j]);
			}
		}
	}
}

//zadatak 149

int je_rastuci(int mat[][10], int n, int m, int trazeniRed) {

	for (int i = 0; i < m; i++)
	{
		if (mat[trazeniRed][i] >= mat[trazeniRed][i+1])
		{
			return 0;
		}
	}
	return 1;
}

void prebaciObodUNiz(int mat[][10], int n, int niz[], int* dimN) {
	
	*dimN = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 || j == 0 || i == n-1 || j == n-1)
			{
				niz[*dimN] = mat[i][j];
				(*dimN)++;
			}
		}
	}

}

// Zadatak 152

int nadjiMaxNeparniKolone(int j, int mat[10][10], int n) {

	int max = 0;
	for (int  i = 0; i < n; i++)
	{
		if (mat[i][j] % 2 == 1)
		{
			if (max == 0)
			{
				max = mat[i][j];
			}else if(max < mat[i][j])
			{
				max = mat[i][j];
			}
		}
	} 
	return max;
}

void zameniNuleSaNeparinim(int mat[][10], int n) {

	for (int i = 0; i < n; i++)
	{
		int maxNeparni = nadjiMaxNeparniKolone(i, mat, n);
		if (maxNeparni == 0)
		{
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			if (mat[j][i] == 0)
			{
				mat[j][i] = maxNeparni;
			}
		}
	}

}

int main() {

	printf("Matrice: \n\n");

	int mat[10][10] = { {1, 2, 5, 3, 5}, {0, 8, 0, 0, 6}, {2, 4, 0, 0, 8}, {3, 0, 7, 8, 2} , {4, 8, 0, 9, 3}};
	int n = 5;

	ispisi_matricu(mat, n);
	zameniNuleSaNeparinim(mat, n);
	ispisi_matricu(mat, n);

	/*152
	ispisi_matricu(mat, n);
	int niz[100], dimN = 0;
	prebaciObodUNiz(mat, n, niz, &dimN);
	ispisiNiz(niz, dimN);*/

	//int mat[10][10] = { {2, 5, 4}, {9, 7, 3}, {3, 6, 8} };
	//int n = 3;
	//ispisi_matricu(mat, n);

	////printf("Max na sporednoj: %d", maxNaSporednoj(mat, n));
	//prikaziIznadSporedne(mat, n);

	/*int niz[1000];
	int dimN = 0;
	formirajNizOdGlavneDiag(mat, n, niz, &dimN);

	printf("\nNiz: ");
	ispisiNiz(niz, dimN);*/


	/*ucitaj_matricu(mat, &n);
	ispisi_matricu(mat, n);
	dodaj_zbirove(mat, &n);
	printf("\n\n");
	

	prikazi(mat, n);*/

	/*printf("Suma j = 1 reda je %d\n", izracunaj_zbir_reda(1, mat, n));
	printf("Suma i = 0 kolone je %d\n", izracunaj_zbir_kolone(0, mat, n));*/

	/*int matirca[CAP][CAP] = {
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8},
		{ 9, 10, 11, 12}
	};

	int n = 3, m = 4;

	ispisi_matricu(matirca, n, m);*/


}


