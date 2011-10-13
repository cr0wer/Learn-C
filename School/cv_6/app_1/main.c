#include <stdio.h>
#include <conio.h>
#include <malloc.h>

int main ()
{
    // promenna "soubor", zastupujici realny soubor
    FILE* soubor;

    int i, *pole, *pole2,
        pocet = 5;

    // alokace pameti pro dynamicke pole
    pole = (int*) calloc(pocet, sizeof(int));

    // zapise do pole hodnoty (10,11,12,13,14)
    for (i = 0; i < pocet; i++)
    {
        *(pole + i) = i + 10;
    }

    // otevre binarni soubor "data.bin" pouze pro zapis
    soubor = fopen("./data.bin", "wb");
    // zapise do souboru budouci velikost (velikost zapisu) = (sizeof(pocet) * 1)
    fwrite(&pocet, sizeof(pocet), 1, soubor);
    // zapise do souboru hodnoty celeho pole
    fwrite(pole, sizeof(int), pocet, soubor);
    fclose(soubor); // uzavre soubor

    pocet = 0;

    // otevre binarni soubor "data.bin" pouze pro cteni
    soubor = fopen("./data.bin","rb");
    // zjisti ze souboru pocet pozic (velikost souboru) = (sizeof(pocet) * 1)
    fread(&pocet, sizeof(pocet), 1, soubor);
    // alokuje pametove misto pro pole2
    pole2 = (int*) calloc(pocet, sizeof(int));
    // precte soubor a ulozi jeho obsah do pole2
    fread(pole2, sizeof(int), pocet, soubor);
    fclose(soubor); // uzavre soubor

    // vypise obsah pole2 (10,11,12,13,14)
    for (i = 0; i < pocet; i++)
    {
        printf("%d\n", *(pole2 + i));
    }

    while(!_kbhit());
    return 0;
}