#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese una palabra y que retorne cuantas vocales tiene la palabra.

int main () {
    int contador = 0, vocales = 0;
    string palabra;

    cout << "Ingrese una cadena" << endl;
    cin >> palabra;

    while (contador < palabra.length()){
        if((int)palabra[contador] == 97 || (int)palabra[contador] == 101 || (int)palabra[contador] == 105 || (int)palabra[contador] == 111 || (int)palabra[contador] == 117) {
            vocales ++;
        }
        contador ++;
    }
    cout << "El numero de vocales es: " << vocales << endl;
}
