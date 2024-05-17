#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese un número entero positivo y se muestre el factorial de ese número. Recuerden que el factorial de un número es el producto de todos los números positivos desde el número ingresado hasta el 1 (5! = 5 * 4 * 3 * 2 * 1 = 120), ademas el 0! y 1! = 1.

int main(){
    int numero, factorial = 1;

    cout << "Ingresa un número: ";
    cin >> numero;

    if (numero < 0){
        numero *= -1;
    }

    for (int i = 1; i <= numero; ++i) {
        factorial *= i;
    }

    cout << "El factorial de " << numero << " es: " << factorial << endl;
    
}


