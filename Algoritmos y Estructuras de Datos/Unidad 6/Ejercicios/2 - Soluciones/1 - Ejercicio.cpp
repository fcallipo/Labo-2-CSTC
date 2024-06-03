#include <iostream>
using namespace std;

// Realizar un programa donde el usuario defina 2 arreglos de caracteres (el largo del arreglo lo define el usuario). Se deberán juntar ambos arreglos en 1 solo, los elementos del 1er arreglo seguido de los elementos del 2do. Posteriormente se deberá ordenar el arreglo de menor a mayor y mostrar por pantalla el nuevo arreglo.

void mostrar_arrglo(char arreglo[], int cantidad){
    for (int i = 0; i < cantidad; i++) {
        if (i != cantidad-1){
            cout << arreglo[i] << ", ";
        }
        else{
            cout << arreglo[i] << ". " <<endl;
        }
    }
}

void ingresar_cantidad_arreglo(int numero, int &cantidad){
    cout << "Ingrese el tamaño del " << numero << "° arreglo de caracteres: ";
    cin >> cantidad;
}

void ingresar_caracteres_arreglo(int numero, char arreglo[], int cantidad){
    cout << "Ingrese los caracteres del " << numero << "° arreglo: " << endl;
    for (int i = 0; i < cantidad; i++) {
        cin >> arreglo[i];
    }
}

void intercambiar(char &a, char &b) {
    int aux = a;
    a = b;
    b = aux;
}

void ordenar_menor_a_mayor(char numeros[], int cantidad) {
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
    int cantidad_1, cantidad_2;
    ingresar_cantidad_arreglo(1, cantidad_1);
    ingresar_cantidad_arreglo(2, cantidad_2);
    char arreglo_1[cantidad_1], arreglo_2[cantidad_2];

    int tamanio_total = cantidad_1 + cantidad_2;
    char arreglo_total[tamanio_total];

    ingresar_caracteres_arreglo(1, arreglo_1, cantidad_1);
    ingresar_caracteres_arreglo(2, arreglo_2, cantidad_2);

    for (int i = 0; i < cantidad_1; i++) {
        arreglo_total[i] = arreglo_1[i];
    }

    for (int i = 0; i < cantidad_2; i++) {
        arreglo_total[cantidad_1 + i] = arreglo_2[i];
    }
    
    ordenar_menor_a_mayor(arreglo_total, tamanio_total);
    cout << "El nuevo arreglo formado es: ";
    mostrar_arrglo(arreglo_total, tamanio_total);
}
