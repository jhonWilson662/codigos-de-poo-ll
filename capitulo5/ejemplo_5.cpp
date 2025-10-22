#include <iostream>
#include <stdio.h> // para gets()
using namespace std;

struct Producto{
    char nombre[30];
    char fabricante[30];
    int cantidad;
    float precio_unitario;
};

void LeeProducto(Producto &p); // Paso por referencia
void Resultado(Producto p);

int main()  // Estructura_Producto_2.cpp
{
    Producto p;
    LeeProducto(p);
    Resultado(p);
    return 0;
}

void LeeProducto(Producto &p)
{
    cout << "\nIngreso de datos:" << endl;
    // Leer el nombre del producto
    cout << "\nNombre del Producto -> ";
    gets(p.nombre);
    // Leer el nombre del fabricante
    cout << "Nombre del Fabricante -> ";
    gets(p.fabricante);
    // leer el numero de productos
    cout << "Numero de productos -> ";
    cin >> p.cantidad;
    // leer el precio unitario
    cout << "Precio de cada producto -> ";
    cin >> p.precio_unitario;
}

void Resultado(Producto p)
{
    float valor_total;  //valor total de los productos
    //calcular el valor total
    valor_total = p.cantidad * p.precio_unitario;
    cout << "\nProducto\t" << p.nombre << endl;
    cout << "Fabricante\t" << p.fabricante << endl;
    cout << "Precio unitario\t" << p.precio_unitario << endl;
    cout << "Cantidad\t" << p.cantidad << endl;
    cout << "Valor total\t" << valor_total << endl;
}