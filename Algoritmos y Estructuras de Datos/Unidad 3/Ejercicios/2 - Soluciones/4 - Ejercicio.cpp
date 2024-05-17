#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese un número y este se le mostrará multiplicado por 2. En el caso de querer frenar el programa, se deberá ingresar el número cero.

int main() {
    int num = 1;

    cout << "Ingrese numeros y se mostrara el numero multiplicado por 2. Cuando decida parar ingrese 0." << endl;

    while (num!=0){
        cin >> num;
        if (num != 0){
            cout << "Multiplicacion: " << num*2 << endl;
        }
    }
}