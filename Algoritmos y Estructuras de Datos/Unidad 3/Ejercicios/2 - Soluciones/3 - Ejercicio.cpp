#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese una cantidad de libros que desea levarse de una librería en la cual todos los libros cuestan $300, pero llevando más de 5 libros cuestan $250 c/u y que retorne el monto total. En el caso de que ingrese un número negativo, decir que no se pueden utilizar esos números.

int main() {
    int libros, precio;

    cout << "ingrese cantidad de libros positiva" << endl;
    cin >> libros;

    if(libros < 0){
        libros = libros * (-1);
        cout << "No se pueden utilizar valores negativos" << endl;
    }

    if (libros > 5){
        precio = libros * 250;
        cout << "Debera abonar: " << precio << endl;
    }
    else {
        precio = libros * 300;
        cout << "Debera abonar: " << precio << endl;
    }
}

