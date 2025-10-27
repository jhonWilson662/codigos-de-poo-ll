#include <iostream>

/* Ilustrar el uso del operador punto */
struct fecha {
    int dia, mes, year;
};

using namespace std;

int main() // Estructuras_1.cpp
{
    struct fecha hoy;
    cout << "Ingrese fecha de hoy (dd/mm/aaaa): ";
    cin >> hoy.dia >> hoy.mes >> hoy.year;
    cout << "\nEl dia de hoy es: ";
    cout << hoy.dia << '/' << hoy.mes << '/' << hoy.year << endl;
    
    return 0;
}