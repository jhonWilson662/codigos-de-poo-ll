#include <iostream>
#include <functional>
using namespace std;

function<double(double, double)> validar(function<double(double, double)> func) {
    return [func](double a, double b) {
        if (b == 0) {
            cout << "Error: No se puede dividir entre cero.\n";
            return 0.0; // evita división inválida
        }
        cout << "Validación correcta.\n";
        return func(a, b);
    };
}

double dividir(double a, double b) {
    return a / b;
}

int main() {
    // Aplicamos el "decorador"
    auto dividirSeguro = validar(dividir);

    cout << dividirSeguro(10, 2) << endl; 
    cout << dividirSeguro(10, 0) << endl; 
    return 0;
}
