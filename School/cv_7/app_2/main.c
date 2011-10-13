#include <stdio.h>
#include <conio.h>
#include <malloc.h>

#define POCET_OSOB 3

// vytvorena struktura se jmenem a vekem
typedef struct self
{
    char jmeno[30];
    int vek;
    struct self* dalsi; // struktura ve strukture s promennou "dalsi"
} Osoba; // jmeno struktury

// probehne alokace pameti pro osobu
Osoba* alokuj()
{
        Osoba* os;
        os = (Osoba*) malloc(sizeof(Osoba)); // staticka alokace
        return os;
}

// nacte osobu z konzole
void nactiOsobu(Osoba* os)
{
    printf("Zadej jmeno: ");
    scanf("%s", os->jmeno);
    printf("Zadej vek: ");
    scanf("%d", &os->vek);
    os->dalsi = 0; // dalsi osoba bude 0 nebo NULL (pro cyklus)
}

int main()
{
    Osoba* os, *prvni, *aktualni; // pomocne promenne
    int i, pocet = 1;

    // pres konzoli se zadaji 3 osoby
    for (i = 1; i <= POCET_OSOB; i++)
    {
        os = alokuj(); // alokuje pamet pro osobu
        nactiOsobu(os); // nacte osobu z konzole

        if (i == 1) // pouze prvni osoba (kvuli nastaveni prvni)
        {
            prvni = os; // nastati tuto osobu jako prvni
        } else {
            aktualni->dalsi = os; // tato osoba bude jako dalsi
        }
        aktualni = os; // nastavi tuto osobu jako aktualni
    }
    aktualni = prvni; // aktualni osoba bude prvni

    // vypise vsechny osoby
    while(aktualni != 0)
    {
        printf("%d. jmeno: %s [%d]\n", pocet, aktualni->jmeno, aktualni->vek);
        // preskoci na dalsi osobu a pokud narazi na NULL (viz. funkce Nacti()), tak ukonci cyklus
        aktualni = aktualni->dalsi;
        pocet++; // pouze pro vypis (pocita lidi)
    }

    while(!_kbhit());
    return 0;
}