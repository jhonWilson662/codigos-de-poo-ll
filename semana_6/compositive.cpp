#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Figura {
public:
    virtual ~Figura() = default;
    virtual void dibujar() const = 0;
};

class Circulo : public Figura {
public:
    void dibujar() const override {
        cout << "Círculo\n";
    }
};

class Rectangulo : public Figura {
public:
    void dibujar() const override {
        cout << "Rectángulo\n";
    }
};

class Triangulo : public Figura {
public:
    void dibujar() const override {
        cout << "Triángulo\n";
    }
};

class Grupo : public Figura {
private:
    vector<shared_ptr<Figura>> figuras;

public:
    void add(shared_ptr<Figura> f) {
        figuras.push_back(f);
    }

    void dibujar() const override {
        cout << "--- Grupo de figuras ---\n";
        for (const auto& f : figuras) {
            f->dibujar();
        }
    }
};

int main() {
    auto c1 = make_shared<Circulo>();
    auto c2 = make_shared<Circulo>();
    auto r1 = make_shared<Rectangulo>();
    
    Grupo g;
    g.add(c1);
    g.add(c2);
    g.add(r1);
    g.dibujar();
    
    cout << "\n--- Grupos anidados ---\n";
    auto subgrupo = make_shared<Grupo>();
    subgrupo->add(make_shared<Triangulo>());
    subgrupo->add(make_shared<Circulo>());
    
    Grupo grupoMaestro;
    grupoMaestro.add(subgrupo);
    grupoMaestro.add(make_shared<Rectangulo>());
    grupoMaestro.dibujar();

    return 0;
}