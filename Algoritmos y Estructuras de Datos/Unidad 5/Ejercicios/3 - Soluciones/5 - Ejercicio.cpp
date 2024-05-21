#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese un número, a través de una función se deberá verificar si el numero ingresado es primo o no, la función devolverá true en el caso de que sea primo y false en el caso de que no lo fuera. Mostrar por pantalla el resultado obtenido.

bool es_primo(int n) {
    if (n <= 1) return false;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int num;

    cout << "Ingresa un número: ";
    cin >> num;

    if (es_primo(num)) {
        cout << num << " es un número primo." << endl;
    } else {
        cout << num << " no es un número primo." << endl;
    }
}
