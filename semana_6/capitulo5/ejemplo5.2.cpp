#include <iostream>
/* Ilustrar el uso del operador flecha*/
struct fecha {
    int dia,mes,year;
}hoy;
using namespace std;

int main() // Estructuras_2.cpp
{
    struct fecha *aptr; //declaracion del apuntador
    aptr = &hoy; //inicializacion del apuntador
    cout << "\nIngrese fecha de hoy: ";
    cin >> aptr->dia >> aptr->mes >> aptr->year;
    cout << "\nEl dia de hoy es: ";
    cout << aptr->dia << '/' << aptr->mes << '/' << aptr->year << endl;
    return 0;
}