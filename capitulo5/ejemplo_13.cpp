#include <iostream>
#include <stdio.h>  // para getchar()
using namespace std;

// Cuenta recursivamente la ocurrencia de un caracter en una cadena
int contador(char ch, char s[]);

int main()  // Cuenta_Caracter_Recursivo.cpp
{
    char ch, s[80];
    cout << "Ingrese cadena: ";
    cin.get(s, 80);
    cout << "Ingrese caracter a contar: ";
    ch = getchar();  // leer caracter desde la entrada
    
    cout << "\nCantidad de ocurrencias del caracter " << ch << " = "
         << contador(ch, s) << endl;
    return 0;
}

int contador(char ch, char s[])
{
    if (s[0] == '\0')  // caso base
        return 0;
    else  // caso general
        if (ch == s[0])  // si hay ocurrencia
            return 1 + contador(ch, &s[1]);
        else
            return contador(ch, &s[1]);
}