#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese varios números (la cantidad la define el usuario). Se deberá determinar cual de ellos es el mayor elemento del arreglo, se mostrara por pantalla un mensaje diciendo: “El mayor elemento del arreglo es: num_mayor”.

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de números: ";
    cin >> cantidad;

    int numeros[cantidad];

    cout << "Ingrese los números:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> numeros[i];
    }

    int mayor = numeros[0];
    for (int i = 1; i < cantidad; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
    }

    cout << "El mayor elemento del arreglo es: " << mayor << endl;
}
