#include <iostream>
using namespace std;

// Realizar un programa para convertir un número decimal en su equivalente en binario. El usuario deberá ingresar un número decimal y posteriormente se calculará la conversión del numero a binario. Mostrar por pantalla el número decimal y su equivalente en binario.

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

void decimal_a_binario(int n, int binario[], int& tamanio) {
    while (n > 0) {
        binario[tamanio++] = n % 2;
        n /= 2;
    }
}

int main() {
    const int tamanio_binario = 32;
    int numero;
    cout << "Ingrese un número decimal: ";
    cin >> numero;

    int binario[tamanio_binario];
    int tamanio = 0;

    decimal_a_binario(numero, binario, tamanio);

    cout << "El número decimal " << numero << " en binario es: ";
    for (int i = tamanio - 1; i >= 0; i--) {
        if (i != 0){
            cout << binario[i];
        }
        else{
            cout << binario[i] <<endl;
        }
    }
}
