// Función recursiva para imprimir una frase al revés.
#include <iostream>
#include <stdio.h>  // para putchar
#include <string.h> // para strlen
using namespace std;

void reversa_frase(char *s);

int main()  // Cadena_Reversa_Recursiva.cpp
{
    char s[] = "AMOR QUE BELLO ES AMARTE";
    cout << "\nCadena original: " << s << endl;
    cout << "\nCadena en reversa: ";
    reversa_frase(s);
    cout << endl;
    return 0;
}

void reversa_frase(char *s)
{
    if (strlen(s) > 1)
        reversa_frase(&s[1]);
    putchar(s[0]);
}