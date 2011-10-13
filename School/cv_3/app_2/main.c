#include <stdio.h>
#include <conio.h>

#define VELIKOST_POLE 5 // nadefinovana konstanta s hodnotou 5

int main()
{
    int i, max, maxIndex, min, minIndex, pole[VELIKOST_POLE];

    // zadani cisel do pole pomoci metody scanf
    for (i = 0; i < VELIKOST_POLE; i++)
    {
        printf("Zadejte %d cislo do pole: ", i + 1);
        scanf("%d", pole + i);
    }

    // nastaveni prvniho cisla v poli na MAX a MIN + jejich indexy
    max = *(pole); maxIndex = 0;
    min = *(pole); minIndex = 0;

    // hledani MAXima a MINima
    for (i = 0; i < VELIKOST_POLE; i++)
    {
        if (*(pole + i) > max)
        {
            max = *(pole + i);
            maxIndex = i;
        }
        if (*(pole + i) < min)
        {
            min = *(pole + i);
            minIndex = i;
        }
    }
    printf("\n"); // mezera

    // vypise pole
    for (i = 0; i < VELIKOST_POLE; i++)
    {
        printf("[%d] = %d\n", i, *(pole + i));
    }
    printf("\n"); // mezera

    // vypsani MAXima a MINima
    printf("MAX = %d na indexu %d\n", max, maxIndex);
    printf("MIN = %d na indexu %d\n", min, minIndex);

    // vymeni v poli MAX za MIN a obracene
    for (i = 0; i < VELIKOST_POLE; i++)
    {
        if (i == maxIndex) *(pole + i) = min;
        if (i == minIndex) *(pole + i) = max;
    }
    printf("\n"); // mezera

    // vypise pole s prohozenym MAX a MIN
    for (i = 0; i < VELIKOST_POLE; i++)
    {
        printf("[%d] = %d\n", i, *(pole + i));
    }
    printf("\n"); // mezera

    // vypsani MAXima a MINima po prohozeni MAX a MIN
    printf("MAX = %d na indexu %d\n", max, minIndex);
    printf("MIN = %d na indexu %d\n", min, maxIndex);

    // vypise velikost pole pomoci "sizeof"
    printf("\nVelikost pole je %d", sizeof(pole) / sizeof(int));

    while(!_kbhit());
    return 0;
}