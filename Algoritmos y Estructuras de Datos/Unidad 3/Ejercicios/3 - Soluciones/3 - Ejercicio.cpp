#include <iostream>
using namespace std;

// Realizar un programa donde se ingrese una letra y se muestre el valor del carácter de la tabla ASCII.

int main(){
    char caracter;

    cout << "Ingrese un caracter." << endl;
    cin >> caracter;

    int codigo_caracter = caracter;
    cout << "Número Ascii asociado: "<< codigo_caracter << endl;
}