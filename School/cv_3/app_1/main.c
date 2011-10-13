#include <stdio.h>
#include <conio.h>

int main()
{
    int a, b, *pA, *pB, soucet = 0;

    pA = &a; // do ukazatele ulozi adresu "a"
    pA = &b; // do ukazatele ulozi adresu "b"

    printf("Zadejte hodnotu A: ");
    scanf("%d", &a); // do adresy promenne "a" vlozi hodnotu
    printf("Zadejte hodnotu B: ");
    scanf("%d", &b); // do adresy promenne "b" vlozi hodnotu

    printf("\n"); // mezera
    soucet = *pA + *pB; // secte hodnoty, na ktere ukazuji ukazatele

    // vypise.. (%X = vypise hex tvar (velikost pismena X urcuje velikost pismen hex))
    printf("PA obsahuje adresu %X a ukazuje na hodnotu %d\n", pA, *pA);
    printf("PB obsahuje adresu %X a ukazuje na hodnotu %d\n", pB, *pB);
    // znak & u souctu je proto, protoze chceme zjistit jeho adresu, nikoliv hodnotu
    printf("Adresa pro soucet je %X a ukazuje na hodnotu %d", &soucet, soucet);

    while(!_kbhit());
    return 0;
}