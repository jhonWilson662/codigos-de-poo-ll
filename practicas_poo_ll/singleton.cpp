#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Clase Singleton con mejores prácticas de POO
class Config {
private:
    // Atributos de configuración
    string appName;
    string version;
    bool debugMode;

    // Constructor privado
    Config() : appName("MiAplicacion"), version("1.0.0"), debugMode(false) {
        cout << "Instancia de Config creada.\n";
    }

    // Eliminar constructor de copia y operador de asignación
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;

public:
    // Método estático para obtener la única instancia
    static Config& getInstance() {
        static Config instance; // Thread-safe desde C++11
        return instance;
    }

    // Destructor
    ~Config() {
        cout << "Instancia de Config destruida.\n";
    }

    // Métodos getter
    string getAppName() const { return appName; }
    string getVersion() const { return version; }
    bool isDebugMode() const { return debugMode; }

    // Métodos setter
    void setAppName(const string& name) { appName = name; }
    void setVersion(const string& ver) { version = ver; }
    void setDebugMode(bool mode) { debugMode = mode; }

    // Método para mostrar información
    void showMessage() const {
        cout << "\n=== Configuración Global ===\n";
        cout << "Aplicación: " << appName << "\n";
        cout << "Versión: " << version << "\n";
        cout << "Modo Debug: " << (debugMode ? "Activado" : "Desactivado") << "\n";
        cout << "===========================\n\n";
    }

    // Método para mostrar dirección de memoria
    void showAddress() const {
        cout << "Dirección de memoria: " << this << "\n";
    }
};

int main() {
    cout << "=== Patrón Singleton en C++ ===\n\n";

    // Obtener referencias a la instancia única
    Config& config1 = Config::getInstance();
    Config& config2 = Config::getInstance();

    // Verificar que son la misma instancia
    cout << "Comparando instancias:\n";
    config1.showAddress();
    config2.showAddress();
    cout << "¿Son la misma instancia? " << (&config1 == &config2 ? "Sí" : "No") << "\n\n";

    // Usar métodos de la configuración
    config1.showMessage();

    // Modificar configuración desde config1
    cout << "Modificando configuración desde config1...\n";
    config1.setAppName("Sistema Avanzado");
    config1.setVersion("2.5.1");
    config1.setDebugMode(true);

    // Ver cambios desde config2 (misma instancia)
    cout << "\nMostrando configuración desde config2:\n";
    config2.showMessage();
    return 0;
}