#include <iostream>
#include <string>
#include <memory>
#include <optional>

using namespace std;

// Clase producto: Computadora
class Computadora {
private:
    optional<string> cpu;
    optional<string> ram;
    optional<string> gpu;
    optional<string> almacenamiento;
    optional<string> motherboard;

public:
    // Constructor por defecto
    Computadora() = default;

    // Setters (usados por el Builder)
    void setCpu(const string& c) { cpu = c; }
    void setRam(const string& r) { ram = r; }
    void setGpu(const string& g) { gpu = g; }
    void setAlmacenamiento(const string& a) { almacenamiento = a; }
    void setMotherboard(const string& m) { motherboard = m; }

    // Getters
    optional<string> getCpu() const { return cpu; }
    optional<string> getRam() const { return ram; }
    optional<string> getGpu() const { return gpu; }
    optional<string> getAlmacenamiento() const { return almacenamiento; }
    optional<string> getMotherboard() const { return motherboard; }

    // Método para mostrar las especificaciones
    void mostrarEspecificaciones() const {
        cout << "\n========== ESPECIFICACIONES DE LA PC ==========\n";
        cout << "CPU:           " << (cpu ? *cpu : "No especificado") << "\n";
        cout << "RAM:           " << (ram ? *ram : "No especificado") << "\n";
        cout << "GPU:           " << (gpu ? *gpu : "No especificado") << "\n";
        cout << "Almacenamiento: " << (almacenamiento ? *almacenamiento : "No especificado") << "\n";
        cout << "Motherboard:   " << (motherboard ? *motherboard : "No especificado") << "\n";
        cout << "===============================================\n\n";
    }

    // Validar que la computadora esté completa
    bool esValida() const {
        return cpu.has_value() && ram.has_value();
    }
};

// Clase Builder (patrón constructor)
class ComputadoraBuilder {
private:
    unique_ptr<Computadora> computadora;

public:
    // Constructor: crea una nueva instancia de Computadora
    ComputadoraBuilder() : computadora(make_unique<Computadora>()) {}

    // Métodos encadenables para agregar componentes
    ComputadoraBuilder& addCpu(const string& cpu) {
        computadora->setCpu(cpu);
        return *this;
    }

    ComputadoraBuilder& addRam(const string& ram) {
        computadora->setRam(ram);
        return *this;
    }

    ComputadoraBuilder& addGpu(const string& gpu) {
        computadora->setGpu(gpu);
        return *this;
    }

    ComputadoraBuilder& addAlmacenamiento(const string& almacenamiento) {
        computadora->setAlmacenamiento(almacenamiento);
        return *this;
    }

    ComputadoraBuilder& addMotherboard(const string& motherboard) {
        computadora->setMotherboard(motherboard);
        return *this;
    }

    // Método para construir y retornar el producto final
    unique_ptr<Computadora> build() {
        if (!computadora->esValida()) {
            cerr << "Advertencia: La computadora no tiene componentes mínimos (CPU y RAM)\n";
        }
        return move(computadora);
    }

    // Método para resetear el builder
    void reset() {
        computadora = make_unique<Computadora>();
    }
};

// Director (opcional): define configuraciones predefinidas
class Director {
public:
    static unique_ptr<Computadora> construirPcGaming() {
        return ComputadoraBuilder()
            .addCpu("AMD Ryzen 9 7950X")
            .addRam("64GB DDR5")
            .addGpu("RTX 4090")
            .addAlmacenamiento("2TB NVMe SSD")
            .addMotherboard("ASUS ROG Crosshair")
            .build();
    }

    static unique_ptr<Computadora> construirPcOficina() {
        return ComputadoraBuilder()
            .addCpu("Intel i5-13400")
            .addRam("16GB DDR4")
            .addGpu("Integrada")
            .addAlmacenamiento("512GB SSD")
            .addMotherboard("MSI B660")
            .build();
    }

    static unique_ptr<Computadora> construirWorkstation() {
        return ComputadoraBuilder()
            .addCpu("Intel Xeon W-3375")
            .addRam("128GB DDR4 ECC")
            .addGpu("NVIDIA RTX A6000")
            .addAlmacenamiento("4TB NVMe RAID")
            .addMotherboard("Supermicro X12")
            .build();
    }
};

int main() {
    cout << "=== Patrón Builder en C++ ===\n";

    // Construcción manual con método encadenado
    cout << "\n1. CONSTRUCCIÓN MANUAL (Método Encadenado):\n";
    unique_ptr<Computadora> pc1 = ComputadoraBuilder()
        .addCpu("Intel i9-14900K")
        .addRam("32GB DDR5")
        .addGpu("RTX 4090")
        .addAlmacenamiento("1TB NVMe")
        .build();
    
    pc1->mostrarEspecificaciones();

    // Construcción paso a paso
    cout << "2. CONSTRUCCIÓN PASO A PASO:\n";
    ComputadoraBuilder builder;
    builder.addCpu("AMD Ryzen 7 7800X3D")
           .addRam("32GB DDR5")
           .addGpu("RX 7900 XTX");
    
    unique_ptr<Computadora> pc2 = builder.build();
    pc2->mostrarEspecificaciones();

    // Uso del Director para configuraciones predefinidas
    cout << "3. CONFIGURACIONES PREDEFINIDAS (Director):\n";
    
    cout << "\n--- PC Gaming ---";
    unique_ptr<Computadora> pcGaming = Director::construirPcGaming();
    pcGaming->mostrarEspecificaciones();

    cout << "--- PC Oficina ---";
    unique_ptr<Computadora> pcOficina = Director::construirPcOficina();
    pcOficina->mostrarEspecificaciones();

    cout << "--- Workstation ---";
    unique_ptr<Computadora> workstation = Director::construirWorkstation();
    workstation->mostrarEspecificaciones();

    // Construcción parcial (sin GPU)
    cout << "4. CONSTRUCCIÓN PARCIAL:\n";
    unique_ptr<Computadora> pc3 = ComputadoraBuilder()
        .addCpu("Intel i3-12100")
        .addRam("8GB DDR4")
        .build();
    
    pc3->mostrarEspecificaciones();

    return 0;
}