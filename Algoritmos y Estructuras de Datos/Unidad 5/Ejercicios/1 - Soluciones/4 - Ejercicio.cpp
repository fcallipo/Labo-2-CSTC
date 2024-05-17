#include <iostream>
using namespace std;

// Realizar un programa donde junte ambos ejercicios anteriores, se le pedirá al usuario que ingrese 2 números y el número del menú.

void menu(){
    cout << "Ingrese una opcion: " << endl;
    cout << "- Suma" << endl;
    cout << "- Resta" << endl;
    cout << "- División" << endl;
    cout << "- Multiplicación" << endl;
    cout << "- Salir  " << endl;
}

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
    int num1, num2;
    string opcion;

    cout << "Ingrese 2 numeros: " << endl;
    cin >> num1;
    cin >> num2;
    menu();
    cin >> opcion;

    if (opcion != "salir"){
        if (opcion == "suma"){
            cout << suma(num1, num2) << endl;
        }
        else if (opcion == "resta"){
            cout << resta(num1, num2) << endl;
        }
        else if (opcion == "division"){
            if (num2 == 0){
                cout << "No se puede dividir por cero." << endl;
            }
            else{
                cout << division(num1, num2) << endl;
            }
        }
        else{
            cout << multiplicacion(num1, num2) << endl;
        }
    }
    else{
        cout << "Saliendo del programa." << endl;
    }
}