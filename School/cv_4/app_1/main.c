#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_VELIKOST 50 // maximalni velikost pole

int main ()
{
    char pole[MAX_VELIKOST]; // deklarace pole znaku
    int i,
        poc = 0,
        delka = 0;

    printf("Zadejte obsah pole (max %d znaku): ", MAX_VELIKOST);
    gets(pole); // naplni obsah pole z konzole
    delka = strlen(pole); // zjisti velikost pole (pocet znaku)

    for (i = 0; i < delka; i++)
    {
        // kazdy 3ti znak, nahradi znakem "*"
        if ((i + 1) % 3 == 0)
        {
            *(pole + i) = '*';
        }
    }
    printf("\n"); // mezera
    puts(pole); // vypise upravene pole

    while(!_kbhit());
    return 0;
}