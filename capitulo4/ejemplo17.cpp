#include <iostream>
#include <string.h>
/* Objetivo: Arrays de punteros a cadenas */
//prototipo de las funciones
int buscaNombres(char *p[], char *nomb);
void printArrayCadenas(char *p[]);
using namespace std;

int main() // Array_Punteros_Cadenas.cpp
{
    char *nombres[] = { "Gabriel Jara", "Estrella Cori", "Ana Lucia",
                        "David Melendez", "Melissa", NULL};

    printArrayCadenas(nombres);

    cout<<"Buscando en el array de cadenas:"<<endl<<endl;
    if ( buscaNombres(nombres, "Estrella Cori") != -1)
    {
        cout<<"Estrella Cori, si esta en lista\n";
    }
    else
    {
        cout<<"Estrella Cori, no esta en lista\n";
    }

    if ( buscaNombres(nombres, "Jose Carlos") == -1)
    {
        cout<<"Jose Carlos, no esta en lista\n";
    }
    else
    {
        cout<<"Jose Carlos, si esta en lista\n";
    }
    return 0;
}

void printArrayCadenas(char *p[])
{
    cout << "\nCadenas en el array o vector:\n"<<endl;
    int i = 0;
    while (p[i] != NULL)
    {
        cout<<p[i]<<endl;
        i++;
    }
    cout<<endl<<endl;
}

int buscaNombres(char *p[], char *nomb)
{
    for (int i = 0; p[i] ; ++i)
    {
        if ( strcmp(p[i], nomb) == 0 )
            return i;
    }
    return -1; // codigo de error: no se encuentra
}