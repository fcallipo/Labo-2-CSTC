#include <iostream>
using namespace std;

// Realizar un programa para rellenar una matriz (con números) pidiendo al usuario el numero de filas y columnas. Ademas el programa determinará si la matriz tiene las misma cantidad de filas que de columnas y si es igual a su matriz transpuesta. Se deberá mostrar por pantalla la respuesta.

int main() {
    int filas, columnas;

    cout << "Introduce el número de filas: ";
    cin >> filas;
    cout << "Introduce el número de columnas: ";
    cin >> columnas;

    int matriz[filas][columnas];
    int matriz_transpuesta[filas][columnas];

    // Verificar si la matriz es cuadrada
    bool es_cuadrada = (filas == columnas);

    // Rellenar la matriz con valores proporcionados por el usuario
    cout << "Introduce los valores para la matriz de " << filas << "x" << columnas << ":" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Introduce el valor para la posición [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz_transpuesta[j][i] = matriz[i][j];
        }
    }

    // Verificar si la matriz es igual a su transpuesta
    bool es_simetrica = true;
    if (es_cuadrada) {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (matriz[i][j] != matriz_transpuesta[i][j]) {
                    es_simetrica = false;
                    break;
                }
            }
            if (!es_simetrica) break;
        }
    } else {
        es_simetrica = false;  // No puede ser simétrica si no es cuadrada
    }

    if (es_cuadrada) {
        cout << "La matriz es cuadrada." << endl;
        if (es_simetrica) {
            cout << "Además, la matriz es igual a su transpuesta (es simétrica)." << endl;
        } else {
            cout << "Sin embargo, la matriz no es igual a su transpuesta." << endl;
        }
    } else {
        cout << "La matriz no es cuadrada y, por lo tanto, no puede ser igual a su transpuesta." << endl;
    }

    return 0;
}

