#include <string.h>
#include <iostream>

using namespace std;

int main()  // Cadena_11.cpp
{
    char string[50];
    char *ptr, c = 'o'; // caracter 'o'
    strcpy(string, "Esto es una cadena");
    /* La función strchr()busca la ocurrencia de un carácter en la cadena. Si lo
    encuentra devuelve un puntero a dicho caracter, en otro caso devuelve un
    puntero nulo */
    ptr = strchr(string, c);
    cout << "\nUso de la funcion strchr():"<<endl;
    cout << "\nCadena a explorar => "<<string<<endl;
    if (ptr)
        cout<<"\nEl caracter "<<c<<" esta en el indice: "<<(ptr - string)<<endl;
    else
        cout<<"\nEl caracter "<<c<<" no se encuentra\n";
    
    return 0;
}
