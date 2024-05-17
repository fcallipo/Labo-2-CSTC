#include <iostream>
using namespace std;

// Realizar un programa para mostrar el promedio de dos números ingresados por usuario.

int main(){
    float num1, num2, resultado;

    cout << "Ingrese dos numeros"<< endl;
    cin >> num1;
    cin >> num2;
    resultado=((num1 + num2)/2);
    cout << "El promedio es: " << resultado << endl;
}

