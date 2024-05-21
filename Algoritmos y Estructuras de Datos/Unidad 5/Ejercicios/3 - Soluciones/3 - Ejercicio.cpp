#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese una palabra y a través de una función se le deberá devolver la palabra invertida. Mostrar por pantalla el resultado obtenido.

string invertir_cadena(string str) {
    int largo = str.size();

    for (int i = 0; i < largo / 2; i++){
        char letra = str[i];
        str[i] = str[largo - i - 1];
        str[largo - i - 1] = letra;
    }

    // for (int i = 0; i < largo / 2; i++) {
    //     swap(str[i], str[largo - i - 1]);
    // }

    return str;
}

int main() {
    string cadena;

    cout << "Ingresa una cadena: ";
    cin >> cadena;

    cout << "La cadena invertida es: " << invertir_cadena(cadena) << endl;
}
