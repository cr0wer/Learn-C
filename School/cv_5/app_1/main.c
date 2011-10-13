#include <stdio.h>
#include <conio.h>

// reseni pres rekurzivni fci
int vypocet(int n)
{
    if (n == 0) return 0;
    return vypocet(n - 1) + n;
}

int main ()
{
    int cislo;

    // zadani cisla pres konzoli
    printf("Zadejte cislo: ");
    scanf("%d", &cislo);

    // vytiskne vysledek (spocita pres funkci)
    printf("Soucet cisel 1 az %d je: %d\n", cislo, vypocet(cislo));

    while(!_kbhit());
    return 0;
}