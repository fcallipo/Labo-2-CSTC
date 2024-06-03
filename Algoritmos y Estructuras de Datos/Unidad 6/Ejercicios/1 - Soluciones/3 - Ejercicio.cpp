#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese un número y una lista de números enteros (la cantidad la define el usuario). Se deberá buscar el número, en el arreglo de números enteros y si se llega a encontrar, se mostrara por pantalla un mensaje diciendo: “El número se encuentra en la lista”, caso contrario devolver un mensaje diciendo: “El número no se encuentra en la lista”.

int main() {
    int numero;
    int cantidad;

    cout << "Ingrese un número: ";
    cin >> numero;
    cout << "Ingrese la cantidad de números enteros en la lista: ";
    cin >> cantidad;

    int lista[cantidad];
    cout << "Ingrese " << cantidad << " números enteros:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> lista[i];
    }

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (lista[i] == numero) {
            encontrado = true;
            i = cantidad;
        }
    }

    if (encontrado) {
        cout << "El número se encuentra en la lista" << endl;
    } else {
        cout << "El número no se encuentra en la lista" << endl;
    }
}
