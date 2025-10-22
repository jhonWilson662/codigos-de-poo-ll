#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Interfaz objetivo (Target): Lo que el cliente espera
class Enchufe {
public:
    virtual ~Enchufe() = default;
    virtual string conectar() const = 0;
};

// Clase Adaptee: Sistema europeo (220V)
class EnchufeEuropeo {
public:
    string conectar() const {
        return "220V conectado (Europeo)";
    }
};

// Clase Adaptee: Sistema americano (110V)
class EnchufeAmericano {
public:
    string conectar() const {
        return "110V conectado (Americano)";
    }
};

// Clase Adaptee: Sistema británico (230V)
class EnchufeBritanico {
public:
    string conectar() const {
        return "230V conectado (Británico)";
    }
};

// Adaptador para enchufe europeo
class AdaptadorEuropeo : public Enchufe {
private:
    unique_ptr<EnchufeEuropeo> enchufe;

public:
    AdaptadorEuropeo(unique_ptr<EnchufeEuropeo> e) : enchufe(move(e)) {}

    string conectar() const override {
        return "Adaptado a 110V -> " + enchufe->conectar();
    }
};

// Adaptador para enchufe británico
class AdaptadorBritanico : public Enchufe {
private:
    unique_ptr<EnchufeBritanico> enchufe;

public:
    AdaptadorBritanico(unique_ptr<EnchufeBritanico> e) : enchufe(move(e)) {}

    string conectar() const override {
        return "Adaptado a 110V -> " + enchufe->conectar();
    }
};

// Adaptador genérico usando composición (más flexible)
template<typename T>
class AdaptadorUniversal : public Enchufe {
private:
    unique_ptr<T> enchufe;
    string voltajeDestino;

public:
    AdaptadorUniversal(unique_ptr<T> e, const string& voltaje = "110V") 
        : enchufe(move(e)), voltajeDestino(voltaje) {}

    string conectar() const override {
        return "Adaptado a " + voltajeDestino + " -> " + enchufe->conectar();
    }
};

// Cliente que usa enchufes
class Dispositivo {
private:
    string nombre;

public:
    Dispositivo(const string& n) : nombre(n) {}

    void enchufar(const Enchufe& enchufe) const {
        cout << nombre << " conectado: " << enchufe.conectar() << "\n";
    }
};

int main() {
    cout << "=== Patrón Adapter en C++ ===\n\n";

    // Caso 1: Adaptador simple (como en Python)
    cout << "1. ADAPTADOR SIMPLE:\n";
    auto enchufEuropeo = make_unique<EnchufeEuropeo>();
    auto adaptador = make_unique<AdaptadorEuropeo>(move(enchufEuropeo));
    cout << adaptador->conectar() << "\n\n";

    // Caso 2: Adaptador británico
    cout << "2. ADAPTADOR BRITÁNICO:\n";
    auto enchufeBritanico = make_unique<EnchufeBritanico>();
    auto adaptadorBritanico = make_unique<AdaptadorBritanico>(move(enchufeBritanico));
    cout << adaptadorBritanico->conectar() << "\n\n";

    // Caso 3: Adaptador universal genérico
    cout << "3. ADAPTADOR UNIVERSAL (Template):\n";
    auto enchufeEuropeo2 = make_unique<EnchufeEuropeo>();
    auto adaptadorUniversal = make_unique<AdaptadorUniversal<EnchufeEuropeo>>(
        move(enchufeEuropeo2), "110V"
    );
    cout << adaptadorUniversal->conectar() << "\n\n";

    // Caso 4: Diferentes voltajes de destino
    cout << "4. ADAPTACIÓN A DIFERENTES VOLTAJES:\n";
    auto enchufeAmericano = make_unique<EnchufeAmericano>();
    auto adaptadorA220 = make_unique<AdaptadorUniversal<EnchufeAmericano>>(
        move(enchufeAmericano), "220V"
    );
    cout << "De 110V a 220V: " << adaptadorA220->conectar() << "\n\n";

    // Caso 5: Uso con dispositivos (cliente)
    cout << "5. USO CON DISPOSITIVOS:\n";
    Dispositivo laptop("Laptop");
    Dispositivo telefono("Teléfono");

    auto enchufe1 = make_unique<EnchufeEuropeo>();
    auto adapt1 = make_unique<AdaptadorEuropeo>(move(enchufe1));
    laptop.enchufar(*adapt1);

    auto enchufe2 = make_unique<EnchufeBritanico>();
    auto adapt2 = make_unique<AdaptadorBritanico>(move(enchufe2));
    telefono.enchufar(*adapt2);

    // Caso 6: Polimorfismo con diferentes adaptadores
    cout << "\n6. POLIMORFISMO CON ADAPTADORES:\n";
    unique_ptr<Enchufe> adaptadores[] = {
        make_unique<AdaptadorEuropeo>(make_unique<EnchufeEuropeo>()),
        make_unique<AdaptadorBritanico>(make_unique<EnchufeBritanico>()),
        make_unique<AdaptadorUniversal<EnchufeAmericano>>(
            make_unique<EnchufeAmericano>(), "220V"
        )
    };

    for (int i = 0; i < 3; i++) {
        cout << "Adaptador " << (i + 1) << ": " 
             << adaptadores[i]->conectar() << "\n";
    }

    return 0;
}