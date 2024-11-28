#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// Funkcija za ispis niza
void ispisiNiza(int niz[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");
}

// Funkcija za dodavanje broja na pocetak niza
void dodajNaPocetak(int niz[], int* n, int broj) {
    // Pomeri sve elemente u desno za jedno mesto
    for (int i = *n; i > 0; i--) {
        niz[i] = niz[i - 1];
    }
    // Umetni novi broj na početak niza
    niz[0] = broj;
    // Povećaj broj elemenata u nizu
    (*n)++;
}

int main() {
    printf("Nizovi: \n");

    int nizGodina[100] = { 19, 20, 21, 17, 20, 21, 23 }; // Inicijalizovani niz
    int n = 7;  // Broj elemenata u nizu

    // Prikazi niz pre dodavanja novog broja
    printf("Pre dodavanja broja:\n");
    ispisiNiza(nizGodina, n);

    // Dodaj broj 38 na pocetak niza
    dodajNaPocetak(nizGodina, &n, 38);

    // Prikazi niz nakon dodavanja novog broja
    printf("Nakon dodavanja broja:\n");
    ispisiNiza(nizGodina, n);

    return 0;
}
