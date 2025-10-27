#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Command {
public:
    virtual void ejecutar() = 0;
    virtual ~Command() = default;
};

class GuardarCommand : public Command {
public:
    void ejecutar() override {
        cout << "Guardando documento..." << endl;
    }
};

class DeshacerCommand : public Command {
public:
    void ejecutar() override {
        cout << "Deshaciendo última acción..." << endl;
    }
};

class Editor {
private:
    vector<Command*> historial;
public:
    void ejecutar(Command* comando) {
        comando->ejecutar();
        historial.push_back(comando);
    }
};

int main() {
    Editor editor;
    GuardarCommand guardar;
    DeshacerCommand deshacer;
    
    editor.ejecutar(&guardar);
    editor.ejecutar(&deshacer);
    editor.ejecutar(&guardar);
    
    return 0;
}