#include <iostream>
#include <string>
using namespace std;

class PagoDolares {
public:
    string pagar(double monto) {
        return "Pago realizado: $" + to_string(monto);
    }
};

// Adaptador
class AdaptadorPago {
private:
    PagoDolares pago; // objeto adaptado
    const double tasaCambio = 3.8;
public:
    AdaptadorPago(PagoDolares p) : pago(p) {}

    string pagarEnSoles(double montoSoles) {
        double montoDolares = montoSoles / tasaCambio;
        return "Adaptado a dólares -> " + pago.pagar(montoDolares);
    }
};

int main() {
    PagoDolares pd;                   
    AdaptadorPago adaptador(pd);       // adaptador 

    cout << adaptador.pagarEnSoles(380.0) << endl; 
    return 0;
}
