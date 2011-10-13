#include "osoba.h"

// globalni nastaveni pro prvni a aktualni osobu
Osoba* prvni = 0, *aktualni = 0;

// funkce pro vytvoreni osoby
Osoba* vytvorOsobu(const char* jm, const int vek)
{
    // alokovana struktura pro osobu
    Osoba* os = (Osoba*) malloc(sizeof(Osoba));
    strcpy(os->jm, jm); // zkopiruje "jm" z funkce do jmena struktury
    os->vek = vek; // vek osoby
    os->dalsi = 0; // nastavi dalsi osobu jako 0

    // pokud globalni promena "prvni" (vytvoreny osoby) neni 0
    if (prvni == 0)
    {
        prvni = os; // priradi osobu jako prvni
    } else {
        aktualni->dalsi = os; // tato osoba nahradi dalsi
    }
    aktualni = os; // nastavi aktualni osobu
    return os;
}

// funkce pro vypsani osoby / skupiny osob
void vypis()
{
    Osoba* pom = prvni; // pomocna pro prvni osobu (kvuli cyklu, aby zacal od 1. osoby)

    // cykluje do ty doby, dokud nenarazi na 0 (dalsi osoba)
    while(pom != 0)
    {
        printf("Jmeno: %s, Vek: %d\n", pom->jm, pom->vek);
        pom = pom->dalsi; // skoci na dalsi osobu
    }
}