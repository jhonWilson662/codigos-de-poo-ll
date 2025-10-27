#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Usuario {
public:
    void actualizar(const string& mensaje) {
        cout << "Notificado: " << mensaje << endl;
    }
};

class SalaChat {
private:
    vector<Usuario*> usuarios;
public:
    void registrar(Usuario* u) {
        usuarios.push_back(u);
    }
    
    void notificar(const string& mensaje) {
        for (auto u : usuarios) {
            u->actualizar(mensaje);
        }
    }
};

int main() {
    SalaChat sala;
    Usuario u1, u2;
    
    sala.registrar(&u1);
    sala.registrar(&u2);
    
    sala.notificar("Nuevo mensaje en el chat.");
    
    return 0;
}