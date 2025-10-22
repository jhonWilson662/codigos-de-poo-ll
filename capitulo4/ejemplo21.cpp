#include <iostream>
#include <string.h>
const int N = 20;
const int M = 80;
int GeneraVectorCadena( char C[], char nC[N][M], char car);

using namespace std;

int main() // Matriz_Cadenas_071.cpp
{
    char *C = "Electron, tipo de particula elemental de carga negativa que forma \
parte de la familia de los leptones y que, junto con los protones y los \
neutrones, forma los atomos y las moleculas. Los electrones estan presentes en \
todos los atomos y cuando son arrancados del atomo se llaman electrones libres";
    cout<<"\nLongitud de la cadena C = "<<strlen(C)<<endl;
    char nC[N][M];
    char car = 'e';
    cout<<"\nPalabras en el vector de cadenas:"<<endl;
    int npals = GeneraVectorCadena(C, nC, car);
    cout<<"\nNumero de palabras almacenadas en el vector = \
"<<npals<<endl<<endl;
    return 0;
}

int GeneraVectorCadena( char C[], char nC[N][M], char car)
{
    int i = 0, j, k = 0, contPal = 0;
    char palab[20];
    while ( C[i] != 0 )
    {
        // sacando cada palabra
        j = 0;
        while ( C[i] != ' ' )
        {
            palab[j] = C[i];
            j++;
            i++;
        }
        palab[j] = '\0';
        // si primer caracter de palabra es igual a car
        if ( palab[0] == car )
        {
            // se mete en el vector de cadenas
            strcpy(nC[k], palab);
            cout<<nC[k]<<endl;//imprime palabra almacenada en el vector
            k++;
            contPal++;
        }
        i++;
    }
    return contPal;
}