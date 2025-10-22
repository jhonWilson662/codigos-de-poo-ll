#include <iostream>
#include <stdio.h>  // Para gets() y puts()
#include <string.h> // Para strupr() y strlwr()

using namespace std;
/* La función strupr() convierte los caracteres de una cadena en mayúsculas
La función strlwr() convierte los caracteres de una cadena en minúsculas */
int main()  // Cadena_10.cpp
{
    char cade1[40], cade2[40];
    cout <<"\nIngrese Cadena en minusculas: ";
    gets(cade1);
    strupr(cade1);
    cout <<"\nA mayusculas: ";
    puts(cade1);
    cout <<endl;
    cout <<"\nIngrese Cadena en Mayusculas: ";
    gets(cade2);
    strlwr(cade2);
    cout <<"\nA minusculas: ";
    puts(cade2);
    cout<<endl;
    return 0;
}
