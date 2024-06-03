#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese 5 números en un arreglo. Se deberá copiar en otro arreglo los elemento ingresados pero multiplicados por 2. Posteriormente se deberá ordenar el arreglo de menor a mayor y mostrar por pantalla el nuevo arreglo.

void mostrar_arrglo(int arreglo[], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        if (i != cantidad-1){
            cout << arreglo[i] << ", ";
        }
        else{
            cout << arreglo[i] << ". " <<endl;
        }
    }
}

void intercambiar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void ordenar_menor_a_mayor(int numeros[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < cantidad; j++) {
            if (numeros[j] < numeros[min_idx]) {
                min_idx = j;
            }
        }
        intercambiar(numeros[min_idx], numeros[i]);
    }
}

int main() {
    const int tamanio = 5;
    int numeros[tamanio];
    int numeros_duplicados[tamanio];

    cout << "Ingrese 5 números enteros:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cin >> numeros[i];
        numeros_duplicados[i] = numeros[i] * 2;
    }

    ordenar_menor_a_mayor(numeros_duplicados, tamanio);
    cout << "El nuevo arreglo con los números multiplicados por 2 es: ";
    mostrar_arrglo(numeros_duplicados, tamanio);
}
