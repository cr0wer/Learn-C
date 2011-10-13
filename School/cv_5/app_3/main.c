#include <stdio.h>
#include <conio.h>
#include <math.h>

// vypocte diskriminant
int vypoctiDiskriminant(int a, int b, int c, double body[])
{
    double dis = 0;

    // vypocet diskriminantu
    dis = (b * b) - (4 * a * c);
    dis = sqrt(dis);

    // vypocita x1 a x2 jen, pokud diskriminant neni zapornej
    if (dis >= 0)
    {
        *(body) = (- b + sqrt(dis) / (2 * a));
        *(body + 1) = (- b - sqrt(dis) / (2 * a));
        return 1; // hodnota true (vypocet probehl)
    }
    else return 0;
}

int main ()
{
    int a, b, c;
    double
        body[] = { 0, 0 },
        x1 = 0,
        x2 = 0;

    printf("Vypocet kvadraticke rovnice\n\nZadejte hodnotu A: ");
    scanf("%d", &a);
    printf("Zadejte hodnotu B: ");
    scanf("%d", &b);
    printf("Zadejte hodnotu C: ");
    scanf("%d", &c);

    if (vypoctiDiskriminant(a, b, c, body))
    {
        printf("Koreny rovnice jsou: (x1 = %0.2f) a (x2 = %0.2f)", *(body), *(body + 1));
    }
    else {
        printf("Rovnice nema reseni.");
    }

    while(!kbhit());
    return 0;
}