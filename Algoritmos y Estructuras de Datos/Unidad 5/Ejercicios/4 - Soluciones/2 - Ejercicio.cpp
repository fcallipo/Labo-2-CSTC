#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese 2 números, 1 como base y el otro como exponente. A través de una función recursiva se deberá obtener el resultado de la operación y al finalizar la cuenta se deberá mostrar el resultado final correspondiente.

int potencia(int base, int exponente){
    if (exponente == 0){
        // Caso base
        exponente = 1;
    }
    else{
        // Caso general
        exponente = base * potencia(base, exponente - 1);
    }
    return exponente;
}

int main(){
    int base, exponente;
    cout << "Ingrese la base: " << endl;
    cin >> base;
    cout << "Ingrese el exponente: " << endl;
    cin >> exponente;

    if (exponente < 0) {
        exponente *= -1;
    }

    cout << base << " elevado a la potencia " << exponente << " es: " << potencia(base, exponente) << endl;
}