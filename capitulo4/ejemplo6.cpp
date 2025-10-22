#include <iostream>
#include <string.h> // para strcpy() y strncpy()

using namespace std;
// Uso de las funciones strcpy() y strncpy()

int main() // Cadena_5.cpp
{
    char x[] = "Universidad Nacional Mayor de San Marcos";
    char y[40],z[40];
    cout<<"\nFunciones strcpy() y strncpy():\n";
    cout<<"\nEl string en el array x es -> "<<x<<endl;
    
    //strcpy() copia una cadena a otra
    cout<<"\nEl string en el array x copiado al array y es ->\n";
    cout<<strcpy(y,x)<<endl;
    
    //strncpy() copia los n primeros caracteres de una cadena a otra
    strncpy(z,x,15);
    z[15] = '\0'; //marca de fin de cadena
    cout<<"\nParte del string en el array x copiado";
    cout<<"al array z es ->\n";
    cout<<z<<endl;
    
    return 0;
}