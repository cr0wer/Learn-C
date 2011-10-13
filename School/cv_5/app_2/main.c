#include <stdio.h>
#include <conio.h>
#include <string.h>

// zjisti pocet vyskytu v poli
int cetnost(char pole[], char znak)
{
    int i, vel,
        vyskytZnaku = 0;

    vel = strlen(pole); // zjisti velikost pole

    for (i = 0; i < vel; i++)
    {
        if (*(pole + i) == znak)
            vyskytZnaku++;
    }
    return vyskytZnaku;
}

int main ()
{
    char znak, pole[50];
    int pocet;

    printf("Zadejte obsah pole: ");
    gets(pole);

    printf("Zadejte znak, ktery se bude hledat v poli: ");
    scanf("%c", &znak);

    pocet = cetnost(pole, znak); // priradi vysledek funkce do promenne

    // vypise, pokud existuje a kolikrat a pokud neexistuje
    if (pocet > 0)
    {
        printf("Znak [%c] se v poli vyskytuje %dx.\n", znak, pocet);
    } else {
        printf("Znak [%c] se v poli nevyskytuje.\n", znak);
    }

    while(!_kbhit());
    return 0;
}