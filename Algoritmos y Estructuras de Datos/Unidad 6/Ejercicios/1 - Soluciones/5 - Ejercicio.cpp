#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese varios números enteros (la cantidad la define el usuario). Se deberá ordenar el arreglo de mayor a menor, mostrar por pantalla el antes y el después.

void mostrar_arrglo(int numeros[], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        if (i != cantidad-1){
            cout << numeros[i] << ", ";
        }
        else{
            cout << numeros[i] << ". " <<endl;
        }
    }
}

void intercambiar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void ordenar_mayor_a_menor(int numeros[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (numeros[j] < numeros[j + 1]) {
                intercambiar(numeros[j], numeros[j + 1]);
            }
        }
    }
}

int main() {
    int cantidad;

    cout << "Ingrese la cantidad de números enteros: ";
    cin >> cantidad;

    int numeros[cantidad];

    cout << "Ingrese " << cantidad << " números enteros:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> numeros[i];
    }

    cout << "Arreglo antes de ordenar:" << endl;
    mostrar_arrglo(numeros, cantidad);

    ordenar_mayor_a_menor(numeros, cantidad);

    cout << "Arreglo después de ordenar de mayor a menor:" << endl;
    mostrar_arrglo(numeros, cantidad);

}
