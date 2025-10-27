// Ejemplo 24.
#include <iostream>
#include <cstdlib>
using namespace std;

//mas acerca del uso del operador new
int main() // punter4.cpp
{
    int *pi, *pj;

    pi = new int;
    pj = new int; // pi y pj son ahora punteros dinamicos
    if (pi == NULL && pj == NULL)
    {
        cout<<"Error: Memoria insuficiente!.\n";
        exit(1);
    }

    *pi = 100;
    pj = pi;
    cout<<endl<<"*pi = "<<*pi<<endl;
    cout<<"*pj = "<<*pj<<endl;

    *pj = 50;

    cout<<"\n*pi = "<<*pi<<endl;
    cout<<"*pj = "<<*pj<<endl;

    pi = new int;
    *pi = 200;
    cout<<"\n*pi = "<<*pi<<endl;
    cout<<"*pj = "<<*pj<<endl;
    return 0;
}