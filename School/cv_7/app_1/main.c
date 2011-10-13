#include <stdio.h>
#include <conio.h>

#define POCET_OSOB 5

// vytvoreni struktury se jmenem a vekem
typedef struct
{
    char jmeno[30]; // jmeno na max 30 znaku
    int vek;
} Osoba; // zastupujici nazev struktury

int main()
{
    Osoba osoby[POCET_OSOB];
    int i, nejOs, nejIn;

    // naplni pole osobama
    for (i = 0; i < POCET_OSOB; i++)
    {
        printf("---------------[%d]---------------\n", i+1);
        printf("Jmeno %d osoby: ", i + 1);
        scanf("%s", osoby[i].jmeno);
        printf("Vek %d osoby: ", i + 1);
        scanf("%d", osoby[i].vek);
    }
    nejOs = osoby[0].vek; // nastavi prvni osobu jako nejstarsi

    // vyhleda, ktera osoba je nejstarsi a ulozi jeji vek a pozici (jmeno)
    for (i = 0; i < POCET_OSOB; i++)
    {
        if (nejOs < osoby[i].vek)
        {
            nejOs = osoby[i].vek;
            nejIn = i;
        }
    }

    // vypise nejstarsi osobu a jeji vek
    printf("\nNejstarsi osoba je: %s s vekem %d.", osoby[nejIn].jmeno, osoby[nejIn].vek);

    while(!kbhit());
    return 0;
}