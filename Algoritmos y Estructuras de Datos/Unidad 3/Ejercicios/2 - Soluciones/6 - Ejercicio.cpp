#include <iostream>
using namespace std;

// Realizar un programa donde se ingresen dos números (primero el menor, luego el mayor) y se muestren todos los números intermedios (incluyendo los extremos).

int main() {
    int num1 = 1, num2 = 0;

    while (num1 > num2){
        cout << "Ingrese dos números. Primero el menor." << endl;
        cin >> num1;

        cout << "Ahora ingrese el mayor." << endl;
        cin >> num2;
    }

    cout<<"Todos los numeros son: "<<endl;
    while ( num1 <= num2 ){
        cout << num1 << endl;
        num1 += 1;
    }
}