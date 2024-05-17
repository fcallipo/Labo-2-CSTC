#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese dos palabras y que retorne si las palabras son iguales o distintas.

int main (){
    string palabra1, palabra2;
    int posicion = 0;
    bool son_iguales = true;

    cout << "Ingrese dos palabras: " << endl;
    cin >> palabra1;
    cin >> palabra2;

    if (palabra1.length() != palabra2.length()){
        cout << "Son distintas." << endl;
    }
    else {
        while (posicion < palabra1.length() && son_iguales){
            if(palabra1[posicion]!= palabra2[posicion]){
                son_iguales = false;
            }
            posicion += 1;
        }
        if(son_iguales){
            cout << "Las palabras son iguales." << endl;
        }
        else {
            cout << "Las palabras no son iguales." << endl;
        }
    }
}
