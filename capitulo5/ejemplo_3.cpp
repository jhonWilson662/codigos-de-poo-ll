#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct punto {
    float x;
    float y;
};

double modulo(punto p1, punto p2); //recibe dos variables punto
void printPunto(punto p);
int main() // Estructura_Punto_1.cpp
{
    punto p1 = {1,1}, p2 = {2,2};
    printPunto(p1);
    printPunto(p2);
    double distancia;
    distancia = modulo(p1, p2);
    cout<<"\nLa distancia es : "<<setw(10)<<setprecision(7)<<distancia<<endl;
    return 0;
}

double modulo(punto p1, punto p2)
{
    // Retorna la distancia
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

void printPunto(punto p)
{
    cout << "\nPunto p(" << p.x << "," << p.y << ")" << endl;
}