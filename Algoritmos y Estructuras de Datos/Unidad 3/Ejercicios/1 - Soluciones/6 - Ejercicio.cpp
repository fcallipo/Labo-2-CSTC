#include <iostream>
using namespace std;

// Realizar un programa para saber si el número ingresado por el usuario es par o impar.

int main() {
    int num;

    cout << "Ingrese un número: " <<endl;
    cin >> num;

    if (num % 2 == 0){
        cout << "Es par" << endl;
    }
    else{
        cout << "Es impar" << endl;
    }
    
}
