#include <iostream>
#include <string>
#include <functional>  
using namespace std;

// "Decorador" que envuelve una función
function<string(string)> log(function<string(string)> func) {
    // devuelve una nueva función anónima 
    return [func](string nombre) {
        cout << "Ejecutando función: saludar" << endl;
        return func(nombre); 
    };
}

// función original
string saludar(string nombre) {
    return "Hola " + nombre;
}

int main() {
    // aplica el "decorador" a la función
    auto saludarConLog = log(saludar);

    // llama a la función decorada
    cout << saludarConLog("Aldo") << endl;

    return 0;
}
