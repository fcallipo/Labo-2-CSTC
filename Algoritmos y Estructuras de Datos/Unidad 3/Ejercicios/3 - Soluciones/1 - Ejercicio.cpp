#include <iostream>
using namespace std;

// Realizar un programa donde se ingresa un número y valida si se encuentra dentro del rango de 0 a 10 (excluyendo los extremos). Si no se encuentra, decir que no pertenece al rango.

int main() {
    float num;

    cout<<"Ingrese un número"<<endl;
    cin>>num;

    if (num>0 && num<10) {
        cout << "El número es: " << num << endl;
    }
    else {
        cout << "No esta dentro del rango." << endl; 
    }
}
