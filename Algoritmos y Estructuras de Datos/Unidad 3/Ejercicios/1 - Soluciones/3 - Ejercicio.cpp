#include <iostream>
using namespace std;

// Realizar un programa para las cuatro operaciones básicas con dos números ingresados por el usuario.

int main() {
    float num1, num2, suma, resta, division, multiplicacion;

    cout << "Ingrese dos números" << endl;
    cin >> num1;
    cin >> num2;

    suma = num1 + num2;
    cout << "La suma es:" << suma << endl;

    resta = num1 - num2;
    cout << "La resta es:" << resta << endl;

    division = num1 / num2;
    cout << "La división es:" << division << endl;

    multiplicacion = num1 * num2;
    cout << "La multiplicación es:" << multiplicacion << endl;
}

