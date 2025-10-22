#include<iostream>

using namespace std;
/* El identificador cin también lee cadenas pero termina o trunca la cadena al
encontrar el primer espacio en blanco */

int main()          // Cadena_0.cpp
{
    char nombre[40];
    cout<<"Ingrese su nombre completo: ";
    cin>>nombre;//Lee hasta el primer espacio en blanco
    cout<<"Hola, "<<nombre<<endl;
    
    return 0;
}