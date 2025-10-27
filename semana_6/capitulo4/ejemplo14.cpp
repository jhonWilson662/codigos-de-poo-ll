#include <iostream>
const int MAX = 255;

// Funciones prototipo
int longcad(const char s[MAX]); // Emula a strlen()
int comparacad(const char s1[MAX], const char s2[MAX]); // Emula a strcmp()
void copiacad(char dest[MAX], const char orig[MAX]); // Emula a strcpy()

using namespace std;

int main() // Mis_Func_Cadenas.cpp
{
    char cadena[MAX];
    cadena[0] = '\0';
    cout << endl << "<1> longcad(cadena) = " << longcad(cadena) << endl;
    copiacad(cadena, "Algoritmos y Programacion");
    cout << "<2> cadena: " << cadena << endl;
    cout << "<3> longcad(cadena) = " << longcad(cadena) << endl;
    cout << "<4> comparacad(cadena, \"Algoritmos y Programacion\") = ";
    cout << comparacad(cadena, "Algoritmos y Programacion") << endl;
    cout << "<5> comparacad(cadena, \"Programacion\") = ";
    cout << comparacad(cadena, "Programacion") << endl;
    return 0;
}

int longcad(const char s[MAX])
{
    int i = 0;
    while (s[i] != '\0') // mientras s[i] no sea fin de cadena
        ++i;
    return i; // devuelve el número de caracteres
}

int comparacad(const char s1[MAX], const char s2[MAX])
{
    int i = 0;
    for (; s1[i] != '\0' && s1[i] == s2[i]; i++)
        ;
    return (int)(s1[i] - s2[i]); // retorna la diferencia de las cadenas
}

void copiacad(char dest[MAX], const char orig[MAX])
{
    int i = 0;
    for (; orig[i] != '\0'; i++)
        dest[i] = orig[i]; // copia caracter a caracter
    dest[i] = '\0';
}