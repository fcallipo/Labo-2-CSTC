#include <iostream>
using namespace std;

// Realizar un programa que le muestre al usuario un menú con 2 opciones: - Sumar 3 números.- Calcular el promedio de 3 números.El usuario deberá elegir una de ellas y al finalizar el algoritmo se deberá mostrar por pantalla el resultado calculado.

int main(){
    int opcion = 0, n1, n2, n3;

    while (opcion < 1 or opcion > 2){
        cout << "Elija una de las 2 opciones: " << endl;
        cout << "- Sumar 3 números." << endl;
        cout << "- Calcular el promedio de 3 números." << endl;
        cin >> opcion;
    }

    cout << "Ingrese 3 números: " << endl;
    cin >> n1;
    cin >> n2;
    cin >> n3;

    switch (opcion)
    {
    case 1:
        cout << "El resultado de la suma es: " << n1 + n2 + n3 << endl;
        break;
    
    case 2:
        cout << "El resultado del promedio es: " << (n1 + n2 + n3)/3 << endl;
        break;

    default:
        cout << "Error." << endl;
        break;
    }
    
    
}