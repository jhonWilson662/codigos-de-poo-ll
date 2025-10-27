#include <stdlib.h>
#include <iostream>
using namespace std;

// funcion fibonacci recursiva
float fibo(int n);

int main()  // Fibonacci_Recursiva.cpp
{
    int n;
    cout << "\nIngrese n: ";
    cin >> n;
    cout << "\nEl numero Fibonacci es: " << fibo(n) << endl;
    return 0;
}

float fibo(int n)
{
    if (n == 0 || n == 1)  // caso base
        return n;
    else  // caso general
        return (fibo(n-1) + fibo(n-2)); // llamada recursiva
}