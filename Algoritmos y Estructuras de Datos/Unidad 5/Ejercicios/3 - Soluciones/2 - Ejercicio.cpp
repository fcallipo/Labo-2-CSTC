#include <iostream>
using namespace std;

// Realizar un programa donde el usuario ingrese una palabra y a través de una función se le deberá devolver el número total de vocales que tenia la palabra. Mostrar por pantalla el resultado obtenido.

int contar_vocales(string str) {
    int contador = 0;
    for (int i = 0; i < str.size(); i++) {
        str[i] = tolower(str[i]); // Convertir la letra a minúscula para simplificar la comparación
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            contador++;
        }
    }
    return contador;
}

int main() {
    string cadena;

    cout << "Ingresa una cadena: ";
    cin >> cadena;

    cout << "El número de vocales en la cadena es: " << contar_vocales(cadena) << endl;
}
