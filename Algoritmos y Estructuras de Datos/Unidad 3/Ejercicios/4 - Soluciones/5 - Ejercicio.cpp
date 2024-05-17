#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese una palabra y que retorne si se lee igual de atrás para adelante que de adelante para atrás.

int main (){
    int largo, posicion = 0, contador = 0, indice = 0;
    bool es_palindromo = true;
    string palabra;

    cout << "Ingrese una palabra" << endl;
    cin >> palabra;

    largo = palabra.length();

    while(posicion < largo && es_palindromo){
        indice += 1;
        if(palabra[posicion] != palabra[largo-indice]){
            es_palindromo = false;
        }
        posicion ++;
    }

    if (es_palindromo){
        cout << "La palabra es palíndroma." << endl;
    }
    else {
        cout << "No va la palabra." << endl;
    }
}
