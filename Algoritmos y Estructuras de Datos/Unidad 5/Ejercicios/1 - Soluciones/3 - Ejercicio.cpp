#include <iostream>
using namespace std;

// Realizar un programa donde el usuario le pase a una función 2 números y un nombre de una operación, la función tiene que hacer la operación correspondiente con los números dados y retornar el resultado de la misma.

float suma(float num1, float num2){
    return num1 + num2;
}

float resta(float num1, float num2){
    return num1 - num2;
}

float multiplicacion(float num1, float num2){
    return num1 * num2;
}

float division(float num1, float num2){
    return num1 / num2;
}

int main(){
    cout << suma(3, 5) << endl;
    cout << resta(3, 5) << endl;
    cout << multiplicacion(3, 5) << endl;
    cout << division(3, 5) << endl;
}
