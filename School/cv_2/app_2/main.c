#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, gen, num;
	int numbers = 0,
		chars = 0,
		bigLetters = 0,
		smallLetters = 0;

	printf("Zadejte pocet generovanych cisel: ");
	scanf("%d", &num); // zadani poctu nahodnych cisel z konzole
	printf("\n"); // mezera
	srand(time(0)); // zajisti, aby cisla nebyla vzdy stejna

	// cyklus pro N opakovani
	for (i = 1; i <= num; i++)
	{
		gen = 48 + rand() % 75; // generuje cisla v rozmezi 48 - 122

		// podminky pro kategorie cisel, znaku a pismen
		if (gen >= 48 && gen <= 57) numbers++;
		if ((gen >= 58 && gen <= 64) || (gen >= 91 && gen <= 96)) chars++;
		if (gen >= 65 && gen <= 90) bigLetters++;
		if (gen >= 97 && gen <= 122) smallLetters++;

		printf("char(%d) --> %c\n", gen, gen);
	}

	// vypsani statistiky
	printf("\nPocet generaci: %d\n", num);
	printf("Pocet cisel: %d\n", numbers);
	printf("Pocet znaku: %d\n", chars);
	printf("Pocet velkych pismen: %d\n", bigLetters);
	printf("Pocet malych pismen: %d", smallLetters);

	while(!_kbhit());
	return 0;
}