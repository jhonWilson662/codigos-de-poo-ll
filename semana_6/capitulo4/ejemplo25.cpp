// Ejemplo 25.
#include <iostream> // Edgar Ruiz Lizama

using namespace std;
const int N = 10;
int main() // Asignacion_Dinamica_3.cpp
{
    int *px, i;
    px = new int[N]; // px es arreglo de punteros dinamico
    int x[N];

    // cargando el array
    for (i=0; i<N; i++)
        x[i]=2*i;

    // recorrer y mostrar el array
    cout<<"\nArreglo de Punteros Dinamico\n"<<endl;
    for (i=0; i<N; i++) {
        px=&x[i];
        cout << "Elemento "<<i<<" valor "<<x[i]<<" direccion "<<px<<endl;
    }

    return 0;
}