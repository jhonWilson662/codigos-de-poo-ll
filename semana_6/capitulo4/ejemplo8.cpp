#include <iostream>
#include <string.h>
#define MAX 255

using namespace std;
/* Editor de texto sencillo que lee una cadena y cuenta el numero de palabras en
ella */

int main()          // Cadena_7.cpp
{
    char linea[MAX], c, sig, blanco;
    int i = 0, numpal;
    //lectura de la linea de texto
    cout<<"\nIngrese linea de texto> ";
    while((c = cin.get()) != '\n')
    {
        linea[i++] = c;
    }
    linea[i++]='\0'; // insertar character nulo al final
    // conteo de palabras
    numpal = i = 0;
    blanco = ' ';//espacio en blanco
    c = linea[i]; //comienzo de la cadena
    //recorrido de la cadena
    while (c)
    {
        if (c != blanco)//si no es espacio en blanco
        {
            sig = linea[i+1];
            if ((sig == blanco) || (sig == '\0'))
                ++numpal;
        }
        c = linea[++i];
    }
    cout<<"\nTexto -> "<<linea<<"\nLa linea de texto tiene ";
    cout<<numpal<<" palabras"<<endl;
    
    return 0;
}
