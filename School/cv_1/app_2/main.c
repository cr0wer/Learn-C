#include <stdio.h>

int main()
{
    int i, volba, ukoncit;

    do
    {
        printf("Zadejte volbu (1,2,3): ");
        scanf("%d", &volba); // pres konzoli se vlozi hodnota volby
        printf("\n"); // mezera

        // podle vyberu volby (1,2,3) se ukaze vysledek
        switch (volba)
        {
        case 1: // volba 1
            printf("Volba [%d] je tvorena pres FOR\n", volba);
            for (i = 0; i < 10; i++)
            {
                printf("%d ", i);
            }
            break;

        case 2: // volba 2
            printf("Volba [%d] je tvorena pres WHILE\n", volba);
            i = 0;
            while (i < 10)
            {
                printf("%d ", i++);
            }
            break;

        case 3: // volba 3
            printf("Volba [%d] je tvorena pres DO-WHILE\n", volba);
            i = 0;
            do
            {
                printf("%d ", i++);
            }
            while (i < 10);
            break;

        default: // pokud se zada jina hodnota
            printf("Volba [%d] neni v nabidce!", volba);
            break;
        }
        printf("\n\nChcete ukoncit program? (0/1): ");
        scanf("%d", &ukoncit);
    }
    while(ukoncit != 1); // cyklus pro opakovani nebo ukonceni programu
    return 0;
}