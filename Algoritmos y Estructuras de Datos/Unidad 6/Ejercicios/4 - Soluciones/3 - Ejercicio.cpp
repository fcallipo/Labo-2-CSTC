#include <iostream>
#include <vector>
using namespace std;

// Realizar un programa donde el usuario defina un vector de 10 enteros. Se deberán ingresar los elementos en el vector y se deberá realizar una función que invierta los elementos. Mostrar por pantalla el vector invertido.

vector<int> invertir_vector(vector<int> v) {
    vector<int> invertido(v.size());
    int longitud = v.size() - 1;
    for(int i = 0; i <= longitud; i++) {
        invertido[longitud - i] = v[i];
    }
    return invertido;
}

int main() {
    vector<int> v(10);
    vector<int> resultado;

    cout << "Ingrese los 10 elementos del vector: " << endl;
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    
    resultado = invertir_vector(v);
    
    cout << "Vector invertido:" << endl;
    for (int elemento : resultado) {
        cout << elemento << " ";
    }
    cout << endl;
}