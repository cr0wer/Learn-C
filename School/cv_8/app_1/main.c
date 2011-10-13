#include "osoba.h"

int main()
{
    Osoba* os;

    // vytvoreni 3 osob
    os = vytvorOsobu("aaa", 10);
    os = vytvorOsobu("bbb", 20);
    os = vytvorOsobu("ccc", 30);

    // vypise vsechny osoby
    vypisOsoby(os);

    while(!_kbhit());
    return 0;
}