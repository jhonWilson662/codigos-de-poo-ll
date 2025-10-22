// 9.
#include <iostream>
#include <string.h>

using namespace std;
/* Uso de strcmp() para comparar dos cadenas, la función devuelve un valor
negativo si la primera cadena es menor que la segunda, positivo si es mayor y
cero en caso que sean iguales. */

int main() // Cadena_8.cpp
{
    char cade1[] = "lenguaje c++";
    char cade2[] = "LENGUAJE c++";
    char cade3[] = "lenguaje c++";
    char cade4[] = "LENGuaje c++";
    int result;
    cout << "\nFuncion strcmp():"<<endl<<endl;
    cout<<"Cadena 1 : "<<cade1<<endl;
    cout<<"Cadena 2 : "<<cade2<<endl;
    cout<<"Cadena 3 : "<<cade3<<endl;
    cout<<"Cadena 4 : "<<cade4<<endl<<endl;
    
    //comparar cadena 1 con cadena 2
    result = strcmp(cade1,cade2);
    if (result<0)
        cout<<cade1<<" es menor que: "<<cade2<<" => resultado = ";
    if (result==0)
        cout<<cade1<<" es igual que: "<<cade2<<" => resultado = ";
    if (result>0)
        cout<<cade1<<" es mayor que: "<<cade2<<" => resultado = ";
    cout<<result<<endl<<endl;
    
    //comparar cadena 1 con cadena 3
    result = strcmp(cade1,cade3);
    if (result<0)
        cout<<cade1<<" es menor que: "<<cade3<<" => resultado = ";
    if (result==0)
        cout<<cade1<<" es igual que: "<<cade3<<" => resultado = ";
    if (result>0)
        cout<<cade1<<" es mayor que: "<<cade3<<" => resultado = ";
    cout<<result<<endl<<endl;
    
    //comparar cadena 1 con cadena 4
    result = strcmp(cade4,cade1);
    if (result<0)
        cout<<cade4<<" es menor que: "<<cade1<<" => resultado = ";
    if (result==0)
        cout<<cade4<<" es igual que: "<<cade1<<" => resultado = ";
    if (result>0)
        cout<<cade4<<" es mayor que: "<<cade1<<" => resultado = ";
    cout<<result<<endl<<endl;
    return 0;
}