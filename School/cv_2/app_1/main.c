#include <stdio.h>
#include <conio.h>

int main()
{
    int i, dec;
    int max = 7; // velikost mist binaru (8)
    char bin;

    printf("Zadejte cislo (0-255): ");
    scanf("%d", &dec); // pres konzoli se zada cislo

    // nastavi rozmezi cisel (0-255)
    if (dec >= 0 && dec <= 255)
    {
        printf("\nCislo %d je v binaru ", dec);

        // zacne cyklus od zadu (zepredu by binarni cislo bylo pozpatku)
        for (i = max; i >= 0; i--)
        {
            bin = dec / (1 << i); // bitovej posun (dec / (1 * 2^i))
            dec = dec - bin * (1 << i); // bitovej posun (dec - bin * (1 * 2^i))
            printf("%d", bin);
        }
    } else {
        printf("\nCislo %d neodpovida rozmezi!", dec);
    }
    while(!_kbhit());
    return 0;
}