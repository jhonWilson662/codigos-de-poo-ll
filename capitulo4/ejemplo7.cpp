#include <iostream>
#include <string.h>

using namespace std;
// Uso de las funciones strcat() y strncat()

int main() // Cadena_6.cpp
{
    char s1[100] = "Con todo lo bueno que";
    char s2[] = " significa heredar una biblioteca,";
    char s3[] = " mejor aun es reunirla - Agustine Birrel";
    cout<<"\nFunciones strcat() y strncat():"<<endl;
    //strcat() concatena una cadena a otra
    strcat(s1,s2);
    cout<<"\nConcatenar s2 en s1: ";
    cout<<endl<<s1;
    cout<<endl;
    cout<<"\nConcatenar s3 en s1: ";
    strcat(s1,s3);
    cout<<endl<<s1;
    cout<<endl;
    
    //strncat() concantena los primeros n caracteres de una cadena
    //a otra
    cout<<"\nParte de la s3 concatenada en s2: ";
    strncat(s2,s3,10);
    cout<<endl<<s2<<endl;
    
    return 0;
}