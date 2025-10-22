#include <iostream>
using namespace std;
//función que suma recursivamente los elementos de un array
int sumarec(int a[], int n);
int main() // Suma_Array_Recursivo.cpp
{
    int a[]={1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(int);
    cout<<"\nSuma de elementos = "<<sumarec(a,n)<<endl;
    return 0;
}

int sumarec(int a[], int n)
{
    if (n == 1) //caso base
        return a[0];
    else //caso general
        return a[n-1] + sumarec(a, n-1); //llamada recursiva
}