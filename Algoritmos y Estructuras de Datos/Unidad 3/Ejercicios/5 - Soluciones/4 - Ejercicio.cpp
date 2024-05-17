#include <iostream>
using namespace std;

// Realizar un programa, utilizando el operador modulo (%), donde el usuario ingrese un número y que retorne si es primo o no lo es. Recuerden que los números primos son divisibles únicamente por si mismos y por 1.

int main(){
    int numero;
    bool es_primo = true;

    cout << "Ingrese un número entero positivo: ";
    cin >> numero;

    if (numero < 0){
        numero *= -1;
    }

    if (numero <= 1) {
        es_primo = false;
    } 
    else {
        for (int i = 2; i <= numero / 2; ++i) {
            if (numero % i == 0) {
                es_primo = false;
            }
        }
    }

    if (es_primo) {
        cout << numero << " es un número primo." << endl;
    } else {
        cout << numero << " no es un número primo." << endl;
    }
}


