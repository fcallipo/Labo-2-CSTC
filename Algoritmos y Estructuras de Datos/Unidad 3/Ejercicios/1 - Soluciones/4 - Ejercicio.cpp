#include <iostream>
using namespace std;

// Realizar un programa para calcular la edad de una persona conociendo el año de su nacimiento.

int main() {
    int anio_actual, anio_nacimiento, resultado;

    cout << "Ingrese el año actual: " <<endl;
    cin >> anio_actual;

    cout << "Ingrese año de nacimiento: " <<endl;
    cin >> anio_nacimiento;

    resultado = anio_actual - anio_nacimiento;
    cout << "Su edad es: " << resultado << endl;

}

