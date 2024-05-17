#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese un número y que retorne si el mismo es par o impar. En el caso de que ingrese un número negativo, multiplicarlo por -1.

int main() {
    int num;
    cout << "Ingrese un numero" << endl;
    cin >> num;

    if (num < 0){
        num *= (-1);
    }

    while (num > 0){
        num -= 2;
    }

    if (num == 0) {
        cout<<"El numero es par"<<endl;
    }
    else {
        cout<<"El numero es impar"<<endl;
    }
    
}