#include <iostream>
using namespace std;

// función recursiva potencia x a la y
float potencia(float x, int n);

int main()  // Potencia_Recursiva.cpp
{
    int x, n;
    cout << "\nIngrese base y exponente enteros positivos: ";
    cin >> x >> n;
    cout << "\n<x^n> " << x << " a la <" << n << "> = " << potencia(x, n) << endl;
    return 0;
}

float potencia(float x, int n)
{
    if (n == 0)  // caso base
        return 1;
    else  // caso general
        return (potencia(x, n - 1) * x); // llamada recursiva
}