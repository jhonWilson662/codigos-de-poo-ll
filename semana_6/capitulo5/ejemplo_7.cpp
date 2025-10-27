/* Objetivo: Un arrays de estructuras */
#include <iostream>
#include <stdio.h>
#include <string.h>
const int N = 50;

struct fecha{
    int dia, mes, year;
};

struct persona{
    char nombre[40];
    short edad;
    fecha fNac; // Este campo es a su vez una estructura
    char direccion[40];
    char ocupacion[20];
};

// Prototipo de las funciones
void leerPersona(persona &p);
void imprimirPersona(persona &p);
void leerArrayPersonas(persona jov[], int n);
void imprimirArrayPersonas(persona jov[], int n);
void buscaPersona(persona jov[], int n, char nom[]);
using namespace std;

int main()
{
    persona jovenes[N]; // Declara un array de estructuras
    int n;
    cout << "Ingresa cantidad de personas: ";
    cin >> n;
    leerArrayPersonas(jovenes, n);
    imprimirArrayPersonas(jovenes, n);
    cout << endl;
    char nom[80];
    cout << "Ingrese nombre a buscar: ";
    gets(nom);
    buscaPersona(jovenes, n, nom);
    return 0;
}

void leerPersona(persona &p)
{
    cout << "\nIngrese nombre: ";
    gets(p.nombre);
    fflush(stdin);
    cout << "Ingrese la edad: ";
    cin >> p.edad;
    cout << "Ingrese fecha de nacimiento (dd/mm/aaaa): ";
    fflush(stdin);
    cout << "Ingrese el año mayor-> fNac.year: ";
    fflush(stdin);
    cout << "Ingrese el mes menor-> fNac.mes: ";
    fflush(stdin);
    cout << "Ingrese ocupacion: ";
    gets(p.ocupacion);
}

void imprimirPersona(persona &p)
{
    cout << "\nDatos de la persona" << endl;
    cout << "\nNombre: " << p.nombre << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Fecha de Nacimiento (dd/mm/aaaa): ";
    cout << p.fNac.dia << "/" << p.fNac.mes << "/" << p.fNac.year << endl;
    cout << "Direccion: " << puts(p.direccion);
    cout << "Ocupacion: " << puts(p.ocupacion);
}

void leerArrayPersonas(persona jov[], int n)
{
    cout << "Lectura de datos en el array de personas" << endl;
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        leerPersona(jov[i]);
    }
}

void imprimirArrayPersonas(persona jov[], int n)
{
    cout << "\nArray de personas" << endl;
    for (int i = 0; i < n; i++)
        imprimirPersona(jov[i]);
}

void buscaPersona(persona jov[], int n, char nom[])
{
    bool existe = false; // se asume que no existe
    strupr(nom); // pasando a mayusculas
    for (int i = 0; i < n; i++)
    {
        strupr(jov[i].nombre); // pasando a mayusculas
        if (strcmp(jov[i].nombre, nom) == 0)
        {
            existe = true;
            imprimirPersona(jov[i]);
        }
    }
    if (existe == false)
        cout << "Persona no existe!..." << endl;
}