#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese varios números enteros (la cantidad la define el usuario). Se deberá mostrar por pantalla cual de esos números es el mayor y cual es el menor.

int main() {
    int cantidad, mayor, menor;

    cout << "Ingrese la cantidad de números enteros: ";
    cin >> cantidad;

    int numeros[cantidad];

    cout << "Ingrese " << cantidad << " números enteros:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> numeros[i];
    }

    mayor = numeros[0];
    menor = numeros[0];

    for (int i = 0; i < cantidad; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }

    cout << "El número mayor es: " << mayor << endl;
    cout << "El número menor es: " << menor << endl;
}
