#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Elemento {
public:
    virtual void mostrar(int nivel = 0) = 0;
};

class Archivo : public Elemento {
    string nombre;
public:
    Archivo(string n) : nombre(n) {}
    void mostrar(int nivel = 0) override {
        cout << string(nivel, ' ') << "Archivo: " << nombre << endl;
    }
};

// Clase compuesta
class Carpeta : public Elemento {
    string nombre;
    vector<Elemento*> elementos;
public:
    Carpeta(string n) : nombre(n) {}

    void agregar(Elemento* e) {
        elementos.push_back(e);
    }

    void mostrar(int nivel = 0) override {
        cout << string(nivel, ' ') << "Carpeta: " << nombre << endl;
        for (auto e : elementos)
            e->mostrar(nivel + 2);
    }
};

int main() {
    Archivo a1("foto.png");
    Archivo a2("documento.txt");
    Carpeta c1("Tareas");
    Carpeta c2("Proyectos");

    c1.agregar(&a2);
    c2.agregar(&a1);
    c2.agregar(&c1);

    c2.mostrar();
    return 0;
}
