#include <iostream>
using namespace std;

// Realizar un programa donde el usuario rellene con números una matriz de 3 X 3. Luego, a la matriz, se le deberá reemplazar las filas por columnas y viceversa. Se deberá mostrar por pantalla la matriz transpuesta.

int main() {
    int matriz[3][3];
    int matriz_transpuesta[3][3];

    cout << "Introduce los valores para una matriz de 3x3:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Introduce el valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matriz_transpuesta[j][i] = matriz[i][j];
        }
    }

    cout << "La matriz transpuesta es: " << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matriz_transpuesta[i][j] << " ";
        }
        cout << endl;
    }
}

