#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese una palabra y que retorne la palabra al revés.

int main (){
    string palabra;
    cout << "Ingresar una palabra." << endl;
    cin >> palabra;

    int contador = palabra.size();

    while (contador >= 0){
        cout << palabra[contador];
        contador -= 1;
    }
    
    cout << endl;
}