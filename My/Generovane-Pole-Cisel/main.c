#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef unsigned int uint;
typedef struct
{
    uint* poleCisel;
    uint pocetCisel;
    uint pocetSudych;
    uint pocetLichych;
    uint soucetCisel;
} Pole;

// alokuje pole cisel na pozadovanou velikost
uint* alokuj(const int velikost)
{
    return (uint*) calloc(velikost, sizeof(uint));
}

// pres konzoli se nastavi pocet prvku v poli
uint nastavPocetCisel(const int min, const int max)
{
    int pocet;
    printf("Nastav pocet prvku v poli: ");
    scanf("%d", &pocet);

    return (pocet >= min && pocet <= max) ? pocet : 0;
}

// vygeneruje a vlozi cisla do pole
uint* vygenerujCisla(Pole pole, const int min, const int max)
{
    uint i;
    pole.poleCisel = alokuj(pole.pocetCisel);
    srand(time(0));

    for (i = 0; i < pole.pocetCisel; i++)
        *(pole.poleCisel + i) = min + rand() % (max - min + 1);
    return pole.poleCisel;
}

// zjisti informace o poli - cisla suda, licha a soucet cisel
void zjistiPocty(Pole* pole)
{
    uint i;
    for (i = 0; i < pole->pocetCisel; i++)
    {
        // pokud cislo bude sude
        if (*(pole->poleCisel + i) % 2 == 0)
        {
            pole->pocetSudych++;
        } else {
            pole->pocetLichych++;
        }
        pole->soucetCisel += *(pole->poleCisel + i);
    }
}

// vypise cele pole se vsemi informacemi
void vypis(const Pole pole)
{
    uint i;
    printf("\nPole ma %d prvku. Z toho:\n  Sudych: %d\n  Lichych: %d\n  Soucet: %d\n\n",
        pole.pocetCisel, pole.pocetSudych, pole.pocetLichych, pole.soucetCisel);

    for (i = 0; i < pole.pocetCisel; i++)
        printf("%d ", *(pole.poleCisel + i));
}

/* vytvori novy soubor, kam zapise obsah pole */
void vytvorSoubor(const Pole pole, const int zapsatPo, const char* nazevSouboru)
{
    uint i;
    FILE* f = fopen(nazevSouboru, "w");

    for (i = 0; i < pole.pocetCisel; i++)
    {
        fprintf(f, "%d ", *(pole.poleCisel + i));

        // zjistuje na kolikatem cislu ma prejit na novy radek
        if ((i + 1) % zapsatPo == 0)
            fprintf(f, "\n");
    }
    fclose(f);
}

/* hlavni funkce main() */
int main()
{
    Pole pole;
    pole.pocetCisel = nastavPocetCisel(1, 1000); // limity
    pole.pocetSudych = 0;
    pole.pocetLichych = 0;
    pole.soucetCisel = 0;
    pole.poleCisel = vygenerujCisla(pole, 1, 9); // generace (1-9)

    zjistiPocty(&pole);
    vypis(pole);
    vytvorSoubor(pole, 50, "poleCisel.txt"); // zalomit radek po cislech + nazev souboru

    while (!_kbhit());
    return 0;
}