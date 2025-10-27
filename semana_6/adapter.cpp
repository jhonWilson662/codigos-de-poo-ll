#include <iostream>
#include <string>
using namespace std;

// Clase original 
class EnchufeEuropeo {
public:
    string conectar() { 
        return "220V conectado"; 
    }
};

// Clase Adaptador
class Adaptador {
private:
    EnchufeEuropeo enchufe;  
public:
    Adaptador(EnchufeEuropeo e) : enchufe(e) {}  

    string conectar() { 
        // adapta la conexión a 110V
        return "Adaptado a 110V -> " + enchufe.conectar(); 
    }
};

int main() {
    EnchufeEuropeo e;        
    Adaptador a(e);          // adaptador
    cout << a.conectar();    
    return 0;
}
