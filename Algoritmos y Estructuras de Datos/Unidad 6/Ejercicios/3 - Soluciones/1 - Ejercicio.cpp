#include <iostream>
using namespace std;

// Realizar un programa para rellenar una matriz pidiendo al usuario el numero de filas y columnas. Se deberá mostrar por pantalla la matriz completa.

int main() {
    int filas, columnas;

    cout << "Introduce el número de filas: ";
    cin >> filas;
    cout << "Introduce el número de columnas: ";
    cin >> columnas;

    int matriz[filas][columnas];

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Introduce el valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Mostrar la matriz completa
    cout << "La matriz completa es: "<<endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

