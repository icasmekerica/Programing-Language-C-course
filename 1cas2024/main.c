#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//zameni mesta 2 promenljive

int main(void) {
	int x = 12, y = 5;
	printf("Pre promene x = %d \t y = %d\n", x, y);
	 
	int temp = x;
	x = y;
	y = temp;

	printf("Posle promene x = %d \t y = %d\n", x, y);
} 