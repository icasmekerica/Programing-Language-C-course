#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//oktobar 2 2020

void zadatak1() {
	int n;
	printf("Unesite n: ");
	scanf("%d", &n);
	int trenutniNeParni = 1;
	int trenutniParni = 2;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (i % 2 == 0)
			{
				//parna red
				printf("%d ", trenutniParni);
				trenutniParni += 2;
			}
			else
			{
				//neparna red
				printf("%d ", trenutniNeParni);
				trenutniNeParni += 2;
			}

		}
		printf("\n");
	}

}

void popunjenKvadrat(int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
	
}

void masna(int n) {

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("@");
		}
		for (int j = 0; j < 2 * (n - i); j++)
		{
			printf(" ");
		}
		for (int j = 0; j < i; j++)
		{
			printf("@");
		}

		printf("\n");
	}

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("@");
		}
		for (int j = 0; j < 2 * (n - i); j++)
		{
			printf(" ");
		}
		for (int j = 0; j < i; j++)
		{
			printf("@");
		}

		printf("\n");
	}

}


int main() {
	masna(7);

}



