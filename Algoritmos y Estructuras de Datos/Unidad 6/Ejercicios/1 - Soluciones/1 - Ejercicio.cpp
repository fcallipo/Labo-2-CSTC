#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese 5 números flotantes. Esos números se deberán guardar en un arreglo y posteriormente se deberá mostrar por pantalla la suma de todos ellos.

int main() {
    const int largo = 5;
    float numeros[largo];
    float suma = 0;

    cout << "Ingrese 5 números flotantes: " << endl;

    for (int i = 0; i < largo; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> numeros[i];
        suma += numeros[i];
    }

    cout << "La suma de los números es: " << suma << endl;
}
