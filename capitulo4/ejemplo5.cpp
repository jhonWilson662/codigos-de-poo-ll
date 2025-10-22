#include<iostream>

using namespace std;
// Muestra como una cadena de caracteres es tratada como un array unidimensional
int main()          // Cadena_4.cpp
{
    char cadena[] = "ALGORITMOS";
    cout << "\nCadena inicial: "<< cadena << endl;
    //imprimiendo cadena como un array de caracteres
    cout << "\nCadena con un espacio entre caracteres: ";
    for(int i = 0; cadena[i] != '\0'; i++)
        cout << cadena[i] << ' ';
    cout<<endl;
    return 0;
}