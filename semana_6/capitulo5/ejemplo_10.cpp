#include <iostream>
using namespace std;
//multiplicacion a*b recursiva
int multrec(int a, int b);

int main() // Multiplica_Recursivo.cpp
{
    int a, b;
    cout << "Ingrese dos enteros ";
    cin >> a >> b;
    cout << "\nEl producto es " << multrec(a,b) << endl;
    return 0;
}

int multrec(int a, int b)
{
    if (b == 1) // caso base
        return a;
    else // caso general
        return (a + multrec(a,b-1));
}