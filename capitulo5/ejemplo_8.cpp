#include <iostream>
using namespace std;
//factorial recursivo
float fact (int n);
int main() // recur1.cpp
{
    int n;
    cout<<"\nIngrese n : ";
    cin>>n;
    cout<<"\nEl factorial de "<<n<<" es: "<<fact(n)<<endl;
    return 0;
}

float fact(int n)
{
    if(n == 0) //caso base
        return 1;
    else //caso general
        return n*fact(n-1); // la función se llama a si misma
}