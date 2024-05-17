#include <iostream>
using namespace std;

// Realizar un programa para calcular el área de un triángulo siendo la base y la altura ingresadas por el usuario.

int main() {
    float base, altura, resultado;

    cout << "Ingrese la base del triangulo" << endl;
    cin >> base;

    cout << "Ingrese la altura del triangulo" << endl;
    cin >> altura;

    resultado = ((base*altura) /2);
    cout << "El area es:" << resultado << endl;
}

