// Presenta variantes de la funciones que usan punteros en el ejemplo anterior
#include <iostream>
const int MAX = 255;

// Funciones prototipo
int longcad(char *s);
int comparacad(char *s1, char *s2);
void copiacad(char *dest, char *orig);

using namespace std;

int main() // Mis_Func_Cadenas_3.cpp
{
    char Cadena[MAX];
    Cadena[0] = '\0';
    cout << "\n<1> longcad(Cadena) = " << longcad(Cadena) << endl;
    copiacad(Cadena, "Algoritmos y Programacion");
    cout << "<2> Cadena: " << Cadena << endl;
    cout << "<3> longcad(Cadena) = " << longcad(Cadena) << endl;
    cout << "<4> comparacad(Cadena, Algoritmos y Programacion) = ";
    cout << comparacad(Cadena, "Algoritmos y Programacion") << endl;
    cout << "<5> comparacad(Cadena, Aloritmos) = ";
    cout << comparacad(Cadena, "Aloritmos") << endl;
    return 0;
}

int longcad(char *s)
{
    int i = 0;
    while (*s++)
        ++i;
    return i;
}

int comparacad(char *s1, char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (int)(*s1 - *s2);
}

void copiacad(char *dest, char *orig)
{
    while (*dest++ = *orig++)
        ;
}