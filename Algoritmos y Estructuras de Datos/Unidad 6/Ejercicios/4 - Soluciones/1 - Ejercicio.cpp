#include <iostream>
#include <vector>
using namespace std;

// Realizar un programa donde el usuario defina un vector de enteros (el largo lo define el usuario). Se deberán ingresar los elementos en el vector y se deberá realizar una función que muestre por pantalla los elementos ingresados.

void mostrarElementos(const vector<int>& vector) {
    for (int elemento : vector) {
        cout << elemento << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Ingrese la longitud del vector: "<< endl;
    cin >> n;
    
    vector<int> vector(n);
    cout << "Ingrese los elementos del vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> vector[i];
    }
    
    cout << "Elementos ingresados:" << endl;
    mostrarElementos(vector);
    
    return 0;
}
