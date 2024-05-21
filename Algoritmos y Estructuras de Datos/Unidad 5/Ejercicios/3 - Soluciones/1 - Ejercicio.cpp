#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese el radio de un circulo, a través de una función se le deberá devolver el área. Mostrar por pantalla el resultado obtenido.

const float PI = 3.14159;

double area_circulo(float radio) {
    return PI * radio * radio;
}

int main() {
    float radio;

    cout << "Ingresa el radio del círculo: ";
    cin >> radio;

    cout << "El área del círculo es: " << area_circulo(radio) << endl;
}
