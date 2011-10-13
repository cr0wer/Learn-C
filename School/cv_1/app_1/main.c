#include <stdio.h>
#include <conio.h>

int main()
{
    int a, b, c, obvod;
 
    // zadani stran A,B,C pres konzoli
    printf("Strana A: ");
    scanf("%d", &a);
    printf("Strana B: ");
    scanf("%d", &b);
    printf("Strana C: ");
    scanf("%d", &c);
 
    // secte strany trojuhelnika
    obvod = a + b + c;
 
    printf("\n"); // mezera
 
    // otestovani stran trojuhelnika (jestli jde slozit)
    if ((a + b) > c && (a + c) > b && (b + c) > a)
    {
        printf("Obvod trojuhelniku je %d a jde sestrojit.\n", obvod);
    } else {
        printf("Trojuhelnik nelze sestrojit. Obvod je %d.\n", obvod);
    }
    while(!_kbhit());
    return 0;
}