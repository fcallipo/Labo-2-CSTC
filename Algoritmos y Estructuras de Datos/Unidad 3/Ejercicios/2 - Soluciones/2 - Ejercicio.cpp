#include <iostream>
using namespace std;

// Realizar un programa para las cuatro operaciones básicas con dos números ingresados por el usuario. En el caso de la división, tener en cuenta que no se puede dividir por cero.

int main() {
    float num1, num2, suma, resta, division, multiplicacion;

    cout << "Ingrese dos números" << endl;
    cin >> num1;
    cin >> num2;

    suma = num1 + num2;
    cout << "La suma es:" << suma << endl;

    resta = num1 - num2;
    cout << "La resta es:" << resta << endl;

    if (num2 == 0){
        cout << "No se puede dividir por 0" << endl;
    } else{
        division = num1 / num2;
        cout << "La division es:" << division << endl;
    }

    multiplicacion = num1 * num2;
    cout << "La multiplicacion es:" << multiplicacion << endl;

}