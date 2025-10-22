#include <iostream>
#include <stdio.h> // para gets
struct fecha {
    int dia, mes, year;
};

struct persona{
    char nombre[40];
    short edad;
    fecha fNac; // este campo es a su vez una estructura
    char direccion[45];
    char ocupacion[20];
};

void leerPersona(persona &p); // Paso por referencia
void imprimePersona(persona p);
using namespace std;

int main() // Estructura_Persona_1.cpp
{
    struct persona p1;
    leerPersona(p1);
    imprimePersona(p1);
    return 0;
}

void leerPersona(persona &p)
{
    cout<<"\nLectura de datos de la persona"<<endl;
    cout<<"Ingresar nombre: "; gets(p.nombre);
    cout<<"Ingrese la edad: "; cin>>p.edad;
    cout<<"Ingrese fecha de nacimiento: "; fflush(stdin);
    cin>>p.fNac.dia>>p.fNac.mes>>p.fNac.year; fflush(stdin);
    cout<<"Ingrese direccion: "; gets(p.direccion); fflush(stdin);
    cout<<"Ingrese ocupacion: "; gets(p.ocupacion);
}

void imprimePersona(persona p)
{
    cout<<"\nDatos de la persona"<<endl;
    cout<<"Nombre: "<<p.nombre<<endl;
    cout<<"Edad: "<<p.edad<<endl;
    cout<<"Fecha de nacimiento: ";
    cout<<p.fNac.dia<<"/"<<p.fNac.mes<<"/"<<p.fNac.year<<endl;
    cout<<"Direccion: "; puts(p.direccion);
    cout<<"Ocupacion: "; puts(p.ocupacion);
}