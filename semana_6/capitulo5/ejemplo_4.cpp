#include <iostream>
#include <stdio.h>  // para gets()
using namespace std;

struct Producto{
    char nombre[30];
    char fabricante[30];
    int cantidad;
    float precio_unitario;
};

int main()  // Estructura_Producto_1.cpp
{
    Producto p;
    float valor_total;  //valor total de los productos
    cout << "\nIngreso de datos:" << endl;
    // leer el nombre del producto
    cout << "\nNombre del Producto -> ";
    gets(p.nombre);
    // leer el nombre del fabricante
    cout << "Nombre del Fabricante -> ";
    gets(p.fabricante);
    // leer el numero de productos
    cout << "Numero de productos -> ";
    cin >> p.cantidad;
    // leer el precio unitario
    cout << "Precio de cada producto -> ";
    cin >> p.precio_unitario;
    
    // calcular el valor total
    valor_total = p.cantidad * p.precio_unitario;
    cout << "\nProducto\t" << p.nombre << endl;
    cout << "Fabricante\t" << p.fabricante << endl;
    cout << "Precio unitario\t" << p.precio_unitario << endl;
    cout << "Cantidad\t" << p.cantidad << endl;
    cout << "Valor total\t" << valor_total << endl;
    return 0;
}