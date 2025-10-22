#include <iostream>
#include <string>
#include <functional>

using namespace std;

function<string(const string&)> log(function<string(const string&)> func, const string& nombreFunc) {
    return [func, nombreFunc](const string& nombre) {
        cout << "Ejecutando función: " << nombreFunc << "\n";
        return func(nombre);
    };
}

string saludar(const string& nombre) {
    return "Hola " + nombre;
}

int main() {
    auto saludarDecorado = log(saludar, "saludar");
    cout << saludarDecorado("Aldo") << "\n";
    return 0;
}