#include <iostream>
using namespace std;

// Realizar un programa donde se ingrese una letra y validar si se trata de una letra Mayúscula o Minúscula.

int main(){
    char caracter;
    bool es_letra = false;

    cout << "ingrese una letra." << endl;
    
    while(!es_letra){
        cin >> caracter;

        if((int)caracter >= 97 && (int)caracter <= 122){

            cout << "Letra minuscula." << endl;
            es_letra = true;

        } else if((int)caracter >= 65 && (int)caracter <= 90 ){

            cout << "Letra Mayuscula." << endl;
            es_letra = true;
        }
    }
}