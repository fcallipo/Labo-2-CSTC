#include <iostream>
using namespace std;

// Realizar un programa donde se le muestre al usuario un menú con 5 opciones, 4 de ellas son los nombres de las operaciones (Suma, resta, división y multiplicación) y la ultima opción es salir del menú. Se deberá crear una función que retorne el menú solicitado.

void menu(){
    cout << "Ingrese una opcion: " << endl;
    cout << "- Suma" << endl;
    cout << "- Resta" << endl;
    cout << "- División" << endl;
    cout << "- Multiplicación" << endl;
    cout << "- Salir  " << endl;
}

int main(){
    menu();
}