#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int duzinaStringa(char string[]) {

	int i = 0;

	while (string[i] != '\0') {
		i++;
	}
	return i;
}

void prekopirajString(char destination[], char source[]) {

	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}

int uporediStringove(char string1[], char string2[]) {

	int i = 0;
	while (string1[i] == string2[i] && string1[i] != '\0' && string2[i] != '\0') {
		i++;
	}
	if (string1[i] > string2[i])
	{
		return 1;
	}
	else if (string1[i] < string2[i])
	{
		return -1;
	}
	return 0;
}

int daLiJeStringPlaindorm(char str[]) {

	int duzinaStringa = strlen(str);

	for (int i = 0; i < duzinaStringa / 2; i++)
	{
		if (str[i] != str[duzinaStringa - 1 - i])
		{
			return 0;
		}
		return 1;
	}

	
	return 0;
}

int daLiPostojiKarakterUStringu(char str[], char c) {

	for (int i = 0; i < strlen(str); i++)
	{
		if (c == str[i])
		{
			return 1;
		}
	}
	return 0;
}

int daLiJeSuglasnik(char c) {

	return daLiPostojiKarakterUStringu("qwrtyupsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM", c);




	/*if (c == 'A' || c == 'a' ||
		c == 'E' || c == 'e' || 
		c == 'I' || c == 'i' || 
		c == 'O' || c == 'o' || 
		c == 'A' || c == 'u')
	{
		return 0;
	}
	return 1;*/
}

int najduziPodstringSuglasnika(char str[]) {

	int duzina = strlen(str);

	int i = 0;
	int maxLen = 0;
	
	while (i < duzina) {
		int j = i;
		while (daLiJeSuglasnik(str[j]) && j < duzina) {
			j++;
		}
		if (j - i > maxLen)
		{
			maxLen = j - i;
		}
		i = j + 1;
	}
	return maxLen;
}

int main() {

	char tekst[] = "12 fg aaa bvcf ssd ae";

	printf("Duzina najduzeg podstringa je %d", najduziPodstringSuglasnika(tekst));
	
	//printf("Da li je palindrom: %d", daLiJeStringPlaindorm(tekst));

	/*char ime[100] = "Ivan";
	char prezime[100];
	printf("%d  %d", strcmp("Ivan", "Ivan"), uporediStringove("Ivan", "Ivan"));*/ 

	/*strcpy(prezime, "Radosavljevic");
	prekopirajString(prezime, "Radosavljevic");
	printf("%s, %s", ime, prezime);*/

	/*char ime[100] = "Ivan";
	char prezime[100];
	if (strcmp(ime, "Ivan") == 0)
	{
		strcpy(prezime, "Radosavljevic");
	}
	printf("%s, duzina: %d, %d \n", prezime, strlen(prezime), duzinaStringa(prezime));*/

	//char imeKreatora[100] = "Ivan";
	//char ime[100];
	//printf("Unesite ime: ");
	////scanf("%s", &ime);
	//gets(ime);
	//printf("Cao %s\n", ime);
	//if (strcmp(ime, imeKreatora) == 0)
	//{
	//	printf("Zovete se kao kreator programa!\n");
	//}
	//else {
	//	printf("Ne zovete se kao kreator programa!\n");
	//}
}


