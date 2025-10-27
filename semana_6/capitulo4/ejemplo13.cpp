#include <iostream>
#include <string.h> // para strlen()
using namespace std;
// strlen(). - Devuelve el número de caracteres de la cadena

int main() // Cadena_12.cpp
{
    char cadel[] = "Eres muy valiosa para mi!";
    int longitud;
    longitud = strlen(cadel);
    cout<<"\nLa cadena:\n"<<cadel<<"\n\nTiene: "<<longitud<<" caracteres\n";

    return 0;
}