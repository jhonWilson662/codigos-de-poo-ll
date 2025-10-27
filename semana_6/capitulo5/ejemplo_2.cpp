#include <iostream>
#include <stdlib.h>
using namespace std;
struct complejo {
    float real;
    float imag;
};

complejo suma(complejo x,complejo y);
complejo resta(complejo x,complejo y);
// A diferencia del programa 1, se inicializan las variables complejas
int main() // Estructura_Complejos_2.cpp
{
    complejo x = {1,2}, y = {2,3}, z;// Inicializando los complejos x, y

    z = suma(x,y);
    cout << "\nLa suma es : " << z.real << " + "
         << z.imag <<"i"<< endl;
    z = resta(x,y);
    cout << "\nLa resta es : " << z.real << " + "
         << z.imag <<"i"<< endl;
    return 0;
}

complejo suma(complejo x,complejo y)
{
    complejo z;
    z.real = x.real + y.real;
    z.imag = x.imag + y.imag;
    return z;
}

complejo resta(complejo x, complejo y)//Calcula la resta de dos complejos
{
    complejo z;
    z.real = x.real - y.real; // Resta las componentes reales de x e y
    z.imag = x.imag - y.imag; // Resta las componentes imaginarias de x e y
    return z; // Devuelve un objeto complejo
}