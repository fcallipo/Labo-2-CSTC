#include <iostream>
using namespace std;

// Realizar un programa donde el usuario rellene con números una matriz de 2 X 2. Luego, se deberá copiar todo su contenido hacia otra matriz. Se deberá mostrar por pantalla la nueva matriz completa.

int main() {
    int matriz_original[2][2];
    int matriz_copia[2][2];

    cout << "Introduce los valores para una matriz de 2x2:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "Introduce el valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz_original[i][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matriz_copia[i][j] = matriz_original[i][j];
        }
    }

    cout << "La nueva matriz completa es: " << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matriz_copia[i][j] << " ";
        }
        cout << endl;
    }
}
