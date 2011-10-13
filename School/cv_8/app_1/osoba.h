#pragma once // blok se nacte jen jednou
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// struktura osoba
typedef struct self
{
    char jm[30]; // jmeno na max 30 znaku
    int vek; // vek
    struct self* dalsi; // dalsi osoba
} Osoba; // promena pro strukturu

// deklarace funkce pro vytvoreni osoby pod jmenem a vekem
Osoba* vytvorOsobu(const char* jm, const int vek);

// dalsi deklarace funkce pro vypis
void vypis(Osoba* os);