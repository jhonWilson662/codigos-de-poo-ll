#include <iostream>
#include <vector>
using namespace std;

class Estrategia {
public:
    virtual void ordenar(vector<int>& arr) = 0;
    virtual ~Estrategia() = default;
};

class Burbuja : public Estrategia {
public:
    void ordenar(vector<int>& arr) override {
        cout << "Ordenando con Burbuja...\n";
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }
};

class QuickSort : public Estrategia {
private:
    void quicksort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i+1], arr[high]);
            int pi = i + 1;
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }
public:
    void ordenar(vector<int>& arr) override {
        cout << "Ordenando con QuickSort...\n";
        quicksort(arr, 0, arr.size() - 1);
    }
};

class Ordenador {
private:
    Estrategia* estrategia;
public:
    Ordenador(Estrategia* e) : estrategia(e) {}
    
    void setEstrategia(Estrategia* e) {
        estrategia = e;
    }
    
    void ejecutar(vector<int>& arr) {
        estrategia->ordenar(arr);
    }
};

void imprimir(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Burbuja burbuja;
    QuickSort quicksort;
    
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr2 = {64, 34, 25, 12, 22, 11, 90};
    
    Ordenador ord(&burbuja);
    
    cout << "Array original: ";
    imprimir(arr1);
    
    ord.ejecutar(arr1);
    cout << "Resultado: ";
    imprimir(arr1);
    
    cout << "\nArray original: ";
    imprimir(arr2);
    
    ord.setEstrategia(&quicksort);
    ord.ejecutar(arr2);
    cout << "Resultado: ";
    imprimir(arr2);
    
    return 0;
}