
#include <iostream>
using namespace std;
const int MAX = 30;

//encuentra recursivamente el maximo elemento de un array
int maximo(int x[], int n);

int main() // Maximo_Valor_Array.cpp
{
    int x[MAX], n;
    cout << "\nCuantos elementos en el array? ";
    cin >> n;
    
    cout << "\nIngrese "<<n<<" enteros uno a uno: ";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    
    cout << "\nEl maximo elemento es: "<< maximo(x, n) <<endl;
    return 0;
}

int maximo(int x[], int n)
{
    if (n == 1) //caso base
        return x[0];
    
    if (x[n-1] > maximo(x, n-1))
        return x[n-1];
    else
        return maximo(x, n-1);
}