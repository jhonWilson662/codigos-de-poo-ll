#include <iostream>
#include <vector>
using namespace std;

// Clase  abstracta
class Figura {
public:
    virtual void dibujar() = 0; 
};

class Circulo : public Figura {
public:
    void dibujar() override {
        cout << "Círculo\n";
    }
};

// Clase compuesta: Grupo
class Grupo : public Figura {
    vector<Figura*> figuras;
public:
    void add(Figura* f) {
        figuras.push_back(f);
    }

    void dibujar() override {
        for (auto f : figuras)
            f->dibujar();  // llama al método de cada figura
    }
};

int main() {
    Circulo c1, c2;
    Grupo g;

    g.add(&c1);
    g.add(&c2);

    g.dibujar(); 
    return 0;
}
