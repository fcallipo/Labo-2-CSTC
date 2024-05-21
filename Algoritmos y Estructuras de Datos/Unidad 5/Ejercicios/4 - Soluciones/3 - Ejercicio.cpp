#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese un número y a través de una función recursiva se deberá devolver y mostrar por pantalla, la posición correspondiente a la secuencia Fibonacci. Recuerden que esta sucesión, es una serie matemática infinita de números en la que cada término se calcula sumando los dos términos anteriores. (Los primeros términos de la secuencia son: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, etc.)

int fibonacci(int n){
    if (n == 1){
        // Caso base 1
        n = 0;
    }
    else if(n == 2){
        // Caso base 2
        n = 1;
    }
    else{
        // Caso general
        n = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return n;
}

int main(){
    int n = -1;
    while (n < 0){
        cout << "Ingrese un número mayor a 0: " << endl;
        cin >> n;
    }

    cout << "La posicion " << n << " de la secuencia de Fibonacci es: " << fibonacci(n) << endl;
}