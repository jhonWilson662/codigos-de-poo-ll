#include<iostream>

using namespace std;
/* Uso de la función cin.get() para leer un caracter */
int main()// cadena02.cpp
{
    char c;
    cout << "\nIngrese un caracter: ";
    cin.get(c);//lee un caracter
    cout << "\nEl caracter leido es: "<< c <<endl;
    return 0;
}