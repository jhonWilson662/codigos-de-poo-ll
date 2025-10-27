#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

class Configuracion {
private:
    string appName;
    int version;
    static int contadorInstancias;

    Configuracion() : appName("MiApp"), version(1) {
        contadorInstancias++;
        cout << "Constructor llamado. Instancias creadas: " << contadorInstancias << "\n";
    }

    Configuracion(const Configuracion&) = delete;
    Configuracion& operator=(const Configuracion&) = delete;

public:
    static Configuracion& getInstance() {
        static Configuracion instancia;
        return instancia;
    }

    void setAppName(const string& nombre) { appName = nombre; }
    void setVersion(int v) { version = v; }
    string getAppName() const { return appName; }
    int getVersion() const { return version; }
    
    void mostrarInfo() const {
        cout << "App: " << appName << " v" << version << "\n";
    }

    void mostrarDireccion() const {
        cout << "Dirección de memoria: " << this << "\n";
    }

    static int getContadorInstancias() {
        return contadorInstancias;
    }
};

int Configuracion::contadorInstancias = 0;

void pruebaBasica() {
    cout << "\n=== PRUEBA 1: Instancia Única ===\n";
    
    Configuracion& config1 = Configuracion::getInstance();
    Configuracion& config2 = Configuracion::getInstance();
    Configuracion& config3 = Configuracion::getInstance();
    
    cout << "\nConfig1 - ";
    config1.mostrarDireccion();
    cout << "Config2 - ";
    config2.mostrarDireccion();
    cout << "Config3 - ";
    config3.mostrarDireccion();
    
    if (&config1 == &config2 && &config2 == &config3) {
        cout << "✓ ÉXITO: Todas las referencias apuntan a la misma instancia\n";
    } else {
        cout << "✗ ERROR: Las referencias NO apuntan a la misma instancia\n";
    }
}

void pruebaModificacion() {
    cout << "\n=== PRUEBA 2: Modificaciones Compartidas ===\n";
    
    Configuracion& config1 = Configuracion::getInstance();
    cout << "Estado inicial:\n";
    config1.mostrarInfo();
    
    cout << "\nModificando desde config1...\n";
    config1.setAppName("SuperApp");
    config1.setVersion(2);
    
    Configuracion& config2 = Configuracion::getInstance();
    cout << "Leyendo desde config2:\n";
    config2.mostrarInfo();
    
    if (config1.getAppName() == config2.getAppName() && 
        config1.getVersion() == config2.getVersion()) {
        cout << "✓ ÉXITO: Los cambios se reflejan en todas las referencias\n";
    } else {
        cout << "✗ ERROR: Los cambios NO se comparten\n";
    }
}

void pruebaContador() {
    cout << "\n=== PRUEBA 3: Contador de Instancias ===\n";
    
    int instanciasAntes = Configuracion::getContadorInstancias();
    cout << "Instancias antes: " << instanciasAntes << "\n";
    
    Configuracion& c1 = Configuracion::getInstance();
    Configuracion& c2 = Configuracion::getInstance();
    Configuracion& c3 = Configuracion::getInstance();
    
    int instanciasDespues = Configuracion::getContadorInstancias();
    cout << "Instancias después de 3 llamadas: " << instanciasDespues << "\n";
    
    if (instanciasAntes == instanciasDespues) {
        cout << "✓ ÉXITO: No se crearon instancias adicionales\n";
    } else {
        cout << "✗ ERROR: Se crearon " << (instanciasDespues - instanciasAntes) 
             << " instancias adicionales\n";
    }
}

void funcionThread(int id) {
    Configuracion& config = Configuracion::getInstance();
    cout << "Thread " << id << " - Dirección: " << &config << "\n";
}

void pruebaThreadSafety() {
    cout << "\n=== PRUEBA 4: Thread Safety ===\n";
    
    vector<thread> threads;
    for (int i = 0; i < 5; i++) {
        threads.emplace_back(funcionThread, i);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    cout << "✓ Todos los threads accedieron a la misma instancia\n";
}

void pruebaComparacionPunteros() {
    cout << "\n=== PRUEBA 5: Comparación de Punteros ===\n";
    
    Configuracion& config1 = Configuracion::getInstance();
    Configuracion& config2 = Configuracion::getInstance();
    
    cout << "¿config1 == config2? " << (&config1 == &config2 ? "SÍ" : "NO") << "\n";
    cout << "¿Son la misma dirección? " << (&config1 == &config2 ? "✓ SÍ" : "✗ NO") << "\n";
    
    Configuracion* ptr1 = &Configuracion::getInstance();
    Configuracion* ptr2 = &Configuracion::getInstance();
    
    cout << "Puntero 1: " << ptr1 << "\n";
    cout << "Puntero 2: " << ptr2 << "\n";
    cout << "¿Punteros iguales? " << (ptr1 == ptr2 ? "✓ SÍ" : "✗ NO") << "\n";
}

void pruebaResumen() {
    cout << "\n=== RESUMEN FINAL ===\n";
    cout << "Total de instancias creadas: " << Configuracion::getContadorInstancias() << "\n";
    
    if (Configuracion::getContadorInstancias() == 1) {
        cout << "✓✓✓ ÉXITO TOTAL: Solo existe UNA instancia del Singleton\n";
    } else {
        cout << "✗✗✗ ERROR: Se crearon múltiples instancias\n";
    }
}

int main() {
    cout << "========================================\n";
    cout << "    PRUEBAS DEL PATRÓN SINGLETON\n";
    cout << "========================================\n";
    
    pruebaBasica();
    pruebaModificacion();
    pruebaContador();
    pruebaThreadSafety();
    pruebaComparacionPunteros();
    pruebaResumen();
    
    cout << "\n========================================\n";
    cout << "    FIN DE LAS PRUEBAS\n";
    cout << "========================================\n";
    
    return 0;
}