#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Clase base abstracta Transporte
class Transporte {
public:
    virtual ~Transporte() = default;
    virtual string entregar() const = 0; // Método virtual puro
};

// Clase concreta Camion
class Camion : public Transporte {
public:
    string entregar() const override {
        return "Entrega por carretera";
    }
};

// Clase concreta Barco
class Barco : public Transporte {
public:
    string entregar() const override {
        return "Entrega por mar";
    }
};

// Clase concreta Avion (ejemplo adicional)
class Avion : public Transporte {
public:
    string entregar() const override {
        return "Entrega por aire";
    }
};

// Clase Factory (Fábrica)
class Factory {
public:
    // Método estático que retorna un unique_ptr
    static unique_ptr<Transporte> getTransporte(const string& tipo) {
        if (tipo == "camion") {
            return make_unique<Camion>();
        } 
        else if (tipo == "barco") {
            return make_unique<Barco>();
        }
        else if (tipo == "avion") {
            return make_unique<Avion>();
        }
        return nullptr; // Tipo no válido
    }
};

int main() {
    cout << "=== Patrón Factory en C++ ===\n\n";

    // Crear transporte tipo barco
    unique_ptr<Transporte> t1 = Factory::getTransporte("barco");
    if (t1) {
        cout << "Transporte 1: " << t1->entregar() << "\n";
    }

    // Crear transporte tipo camion
    unique_ptr<Transporte> t2 = Factory::getTransporte("camion");
    if (t2) {
        cout << "Transporte 2: " << t2->entregar() << "\n";
    }

    // Crear transporte tipo avion
    unique_ptr<Transporte> t3 = Factory::getTransporte("avion");
    if (t3) {
        cout << "Transporte 3: " << t3->entregar() << "\n";
    }

    // Tipo no válido
    unique_ptr<Transporte> t4 = Factory::getTransporte("tren");
    if (!t4) {
        cout << "\nError: Tipo de transporte 'tren' no disponible.\n";
    }

    cout << "\n=== Polimorfismo en acción ===\n";
    
    // Array de diferentes transportes
    unique_ptr<Transporte> transportes[] = {
        Factory::getTransporte("camion"),
        Factory::getTransporte("barco"),
        Factory::getTransporte("avion")
    };

    for (int i = 0; i < 3; i++) {
        if (transportes[i]) {
            cout << "Transporte " << (i + 1) << ": " 
                 << transportes[i]->entregar() << "\n";
        }
    }

    return 0;
}