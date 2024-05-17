#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese dos números y se muestre cuál es el mayor, en el caso de ser iguales decir que son iguales.

int main() {
    float num1, num2;

    cout << "Ingrese dos números" << endl;
    cin >> num1;
    cin >> num2;

    if (num1 < num2){
        cout << "El mayor es: " << num2 << endl;
    }
    else if (num1 > num2) {
        cout << "El mayor es: " << num1 << endl;
    }
    else{
        cout << "Los numeros son iguales" << endl;
    }
}