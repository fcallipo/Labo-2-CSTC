#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese un número y a través de una función recursiva se deberá sumar todos los números desde el que ingreso, hasta el cero. Al finalizar la cuenta se deberá mostrar el resultado final correspondiente.

int sumatoria(int n){
    if (n == 0){
        // Caso base
        n = 0;
    }
    else{
        // Caso general
        n = n + sumatoria(n-1);
    }
    return n;
}

int main(){
    int n;
    cout << "Ingrese un número: " << endl;
    cin >> n;

    if (n < 0) {
        n *= -1;
    }

    cout << "La sumatoria de todos los números hasta " << n << " es: " << sumatoria(n) << endl;
}