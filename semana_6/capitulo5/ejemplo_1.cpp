#include <iostream>
using namespace std;

struct complejo {
    float real; // componente real
    float imag; // componente imaginaria
};

// función prototipo, retorna un complejo
complejo suma(complejo x, complejo y);
complejo resta(complejo x, complejo y);

int main() // Estructura_Complejos.cpp
{
    complejo x, y, z;
    
    cout << "\nIngrese parte real y parte imaginaria de x => ";
    cin >> x.real >> x.imag;
    cout << "\nIngrese parte real y parte imaginaria de y => ";
    cin >> y.real >> y.imag;
    
    z = suma(x, y);
    cout << "\nLa suma es : " << z.real << " + "
         << z.imag << "i" << endl;
    
    z = resta(x, y);
    cout << "\nLa resta es : " << z.real << " + "
         << z.imag << "i" << endl;
    
    return 0;
}

complejo suma(complejo x, complejo y) // Calcula la suma de dos complejos
{
    complejo z;
    z.real = x.real + y.real; // Suma las componentes reales de x e y
    z.imag = x.imag + y.imag; // Suma las componentes imaginarias de x e y
    return z; // Devuelve un objeto complejo
}

complejo resta(complejo x, complejo y) // Calcula la resta de dos complejos
{
    complejo z;
    z.real = x.real - y.real; // Resta las componentes reales de x e y
    z.imag = x.imag - y.imag; // Resta las componentes imaginarias de x e y
    return z; // Devuelve un objeto complejo
}