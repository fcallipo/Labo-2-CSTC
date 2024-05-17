#include <iostream>
using namespace std;

// Realizar un programa que le pida al usuario ingresar un número y luego muestre por pantalla la tabla de multiplicar correspondiente a ese número del 1 al 10.

int main(){
    int numero;
    cout << "Ingresa un número: ";
    cin >> numero;

    cout << "Tabla de multiplicar del número " << numero << " es:" << endl;

    for (int i = 1; i <= 10; ++i) {
        cout << numero << " * " << i << " = " << (numero * i) << endl;
    }
}


