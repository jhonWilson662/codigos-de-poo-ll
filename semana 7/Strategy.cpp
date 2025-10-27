#include <iostream>
using namespace std;

class Estrategia {
public:
    virtual void ejecutar() = 0;
    virtual ~Estrategia() = default;
};

class EstrategiaA : public Estrategia {
public:
    void ejecutar() override { 
        cout << "Algoritmo A\n"; 
    }
};

class EstrategiaB : public Estrategia {
public:
    void ejecutar() override { 
        cout << "Algoritmo B\n"; 
    }
};

class Contexto {
private:
    Estrategia* estrategia;
public:
    Contexto(Estrategia* e) : estrategia(e) {}
    
    void setEstrategia(Estrategia* e) { 
        estrategia = e; 
    }
    
    void operar() { 
        estrategia->ejecutar(); 
    }
};

int main() {
    EstrategiaA a;
    EstrategiaB b;
    
    Contexto ctx(&a);
    ctx.operar();  // Salida: Algoritmo A
    
    ctx.setEstrategia(&b);
    ctx.operar();  // Salida: Algoritmo B
    
    return 0;
}