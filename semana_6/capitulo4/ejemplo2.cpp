#include<iostream>

using namespace std;
/* Uso de la función cin.getline() para leer cadenas en C++. Observe que
cin.getline() lee una cadena hasta el número de caracteres especificado */
int main()          //cadena01.cpp
{
    char cadena[80];
    cout<<"\nIngrese una cadena:\n";
    cin.getline(cadena,80);// Lee cadena hasta un maximo de 80 caracteres
    cout<<"\nLa cadena leida es:\n"<<cadena<<endl;
    return 0;
}