#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct index {
	int brojIndexa;
	int godinaUpisa;

}INDEX;

typedef struct smer {
	int sifraSmera;
	char nazivSmera[20];
}SMER;

typedef struct student {
	char ime[20];
	char prezime[20];
	INDEX index;
	SMER smer;
}STUDENT;

void ispisiStudenta(STUDENT st) {
	printf("\nStudent: %s %s, Index je: %d/%d, Smer je: %s-%d\n", 
		st.ime, st.prezime, st.index.brojIndexa, st.index.godinaUpisa,
		st.smer.nazivSmera, st.smer.sifraSmera);
}

STUDENT unesiStudenta() {
	STUDENT st;
	printf("Unesite Ime studenta: ");
	gets(st.ime);
	printf("Unesite Prezime studenta: ");
	gets(st.prezime);
	printf("Unesite broj Indexa studenta: ");
	scanf("%d", &st.index.brojIndexa);
	printf("Unesite godinu Upisa studenta: ");
	scanf("%d", &st.index.godinaUpisa);
	printf("Unesite Sifru smera studenta\n(1-ISIT, 2-MEN, 3-DALJ): ");
	int x;
	scanf("%d", &x);
	getchar();
	SMER smer1 = { 1, "ISIT" };
	SMER smer2 = { 2, "MEN" };
	SMER smer3 = { 3, "DALJ" };

	switch (x)
	{
	case 1: st.smer = smer1; 
		break;
	case 2: st.smer = smer2;
		break;
	case 3: st.smer = smer3;
		break;
	default:
		printf("Greska!");
	}
	return st;
}

void ubaciStudentaUNiz(STUDENT studenti[], int* n, STUDENT st) {

	studenti[*n] = st;
	(*n)++;

}

void ispisiNizStudenata(STUDENT studenti[], int n) {

	if (n == 0)
	{
		printf("Greska! Nema studenata u nizu!\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		ispisiStudenta(studenti[i]);
	}

}

//void napuniNiz(STUDENT studenti[], int *n) {
//
//	char izbor;
//	do
//	{
//		STUDENT st;
//		st = unesiStudenta();
//		ubaciStudentaUNiz(studenti, n, st);
//		printf("Da li zelite da uneste jos jednog studenta (d-da / n-ne): ");
//		scanf("%c", &izbor);
//		getchar();
//	} while (izbor != 'n' && izbor != 'N');
//
//}

void napuniNiz(STUDENT studenti[], int* n) {
	char izbor;

	do {
		printf("Da li zelite da uneste jos jednog studenta (d-da / n-ne): ");
		scanf(" %c", &izbor);
		getchar();  // clear the newline character

		if (izbor == 'n' || izbor == 'N') {
			break;  // exit the loop if the user answers 'n' or 'N'
		}
		else if (izbor == 'd' || izbor == 'D') {
			STUDENT st = unesiStudenta();  // enter student details
			ubaciStudentaUNiz(studenti, n, st);
		}
		else {
			printf("Neispravan unos! Molimo unesite 'd' za da ili 'n' za ne.\n");
		}

	} while (1);  // loop until 'n' or 'N' is entered
}

void main() {

	STUDENT ica = { "Ivan", "Radosavljevic", {252, 2018} , {1, "ISIT"}};

	SMER smer = { 1, "ISIT" };

	/*STUDENT st2;
	st2 = unesiStudenta();
	ispisiStudenta(st2);*/

	STUDENT studenti[100];
	int n = 0;
	napuniNiz(studenti, &n);

	ispisiNizStudenata(studenti, n);

	/*STUDENT ogi = { "Ognjen", "Ignjatovic", {525, 2018}};
	printf("Student se zove %s", ogi.ime);
	printf("\n%s, index je %d/%d", ogi.ime, ogi.index.brojIndexa, ogi.index.godinaUpisa);*/


}
