#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese una temperatura en grados Celsius y a través de una función se le deberá devolver la temperatura convertida a Fahrenheit. Mostrar por pantalla el resultado obtenido.

double celsius_a_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    float celsius;

    cout << "Ingresa la temperatura en grados Celsius: ";
    cin >> celsius;

    cout << "La temperatura en grados Fahrenheit es: " << celsius_a_fahrenheit(celsius) << endl;
}
