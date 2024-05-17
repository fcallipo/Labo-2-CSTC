#include <iostream>
using namespace std;

// Realizar un programa que calcule la suma de todos los números pares del 1 al 100 y luego muestre por pantalla el resultado.

int main(){
    int suma = 0;

    for (int i = 2; i <= 100; i += 2) {
        suma += i;
    }

    cout << "La suma de los números pares del 1 al 100 es: " << suma << endl;
}


