#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	else{
		return 10;
	}

}

int main() {

	int info[100][4] = { {20180018, 99, 12, 1}, {20200001, 52, 76, 2}, {20100005, 78, 66, 1}, };
	int n = 3;

	printf("%d", ocena(20200001, 2, info, n));
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