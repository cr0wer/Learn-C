#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_VELIKOST 30 // maximalni velikost pole znaku

int main ()
{
    char str1[MAX_VELIKOST],
         str2[MAX_VELIKOST],
         str3[MAX_VELIKOST],
         znak;
    char *pChar = 0;
    int isPorovnej = 0;

    // pres konzoli se zada obsah str1 a str2
    printf("Zadej str1: ");
    gets(str1);
    printf("Zadej str2: ");
    gets(str2);

    // zjisteni velikosti pole str1 a str2
    printf("Velikost str1: %d\n", strlen(str1));
    printf("Velikost str2: %d\n", strlen(str2));

    // zkopiruje obsah pole str2 do str3
    strcpy(str3, str2);
    printf("Obsah str3 je: ");
    puts(str3);

    // spoji obsah pole str1 a str3 do str1
    strcat(str1, str3);
    printf("Obsah spojeni str1 a str3 je: ");
    puts(str1);

    // zada znak, ktery se bude hledat v poli
    printf("Zadejte znak: ");
    scanf("%c", &znak);

    // zjisti ukazatel na prvni nalezeny znak promenny v poli str1
    pChar = strchr(str1, znak);

    // pokud se znak v poli vyskytuje
    if (pChar != 0)
    {
        printf("Znak je v poli str1 a je na pozici: %d\n", (pChar - str1) + 1);
    } else {
        printf("Znak se v poli nenechazi.\n");
    }

    // porovna pole str1 a str2 jestli jsou stejne, popr. jake je vetsi
    isPorovnej = strcmp(str1, str2);

    switch (isPorovnej)
    {
        case 0: printf("str1 = str2"); break;
        case 1: printf("str1 > str2"); break;
        case -1: printf("str1 < str2"); break;
    }

    while(!_kbhit());
    return 0;
}